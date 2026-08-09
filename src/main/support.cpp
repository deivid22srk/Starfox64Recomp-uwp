#include "zelda_support.h"
#include <SDL.h>
#include "nfd.h"
#include "RmlUi/Core.h"

#ifdef _UWP
extern "C" __declspec(dllimport) void uwp_PickAFile(char* path);
#endif

#ifdef __ANDROID__
#include <jni.h>
#include <SDL_system.h>
#include <mutex>
#include <condition_variable>

namespace {
std::mutex rom_pick_mutex;
std::condition_variable rom_pick_cv;
bool rom_pick_done = false;
bool rom_pick_success = false;
std::string rom_pick_path;
}

// Called from Java (MainActivity.onActivityResult) on the UI thread after the
// user picks a ROM file. Wakes up the thread waiting in perform_file_dialog_operation.
extern "C" JNIEXPORT void JNICALL
Java_com_sf64recomp_app_MainActivity_nativeOnRomSelected(JNIEnv* env, jclass, jstring jpath) {
    {
        std::lock_guard lock(rom_pick_mutex);
        if (jpath != nullptr) {
            const char* path_c = env->GetStringUTFChars(jpath, nullptr);
            rom_pick_success = path_c != nullptr && path_c[0] != '\0';
            rom_pick_path = path_c != nullptr ? path_c : "";
            if (path_c != nullptr) {
                env->ReleaseStringUTFChars(jpath, path_c);
            }
        } else {
            rom_pick_success = false;
            rom_pick_path = "";
        }
        rom_pick_done = true;
    }
    rom_pick_cv.notify_all();
}

// Launches the system file picker through MainActivity and blocks until a file
// is chosen or the dialog is cancelled.
void android_open_rom_picker() {
    {
        std::lock_guard lock(rom_pick_mutex);
        rom_pick_done = false;
    }

    JNIEnv* env = (JNIEnv*) SDL_AndroidGetJNIEnv();
    jobject activity = (jobject) SDL_AndroidGetActivity();
    jclass cls = env->GetObjectClass(activity);
    jmethodID openRomPicker = env->GetStaticMethodID(cls, "openRomPicker", "()V");
    if (openRomPicker != nullptr) {
        env->CallStaticVoidMethod(cls, openRomPicker);
    }

    std::unique_lock lock(rom_pick_mutex);
    rom_pick_cv.wait(lock, [] { return rom_pick_done; });
}
#endif

namespace zelda64 {
    // MARK: - Internal Helpers
    void perform_file_dialog_operation(const std::function<void(bool, const std::filesystem::path&)>& callback) {
#ifdef __ANDROID__
        android_open_rom_picker();

        std::unique_lock lock(rom_pick_mutex);
        bool success = rom_pick_success;
        std::filesystem::path path = success ? std::filesystem::path(rom_pick_path) : std::filesystem::path{};
        lock.unlock();

        callback(success, path);
        return;
#elif !defined(_UWP)
        nfdnchar_t* native_path = nullptr;
        nfdresult_t result = NFD_OpenDialogN(&native_path, nullptr, 0, nullptr);

        bool success = (result == NFD_OKAY);
        std::filesystem::path path;

        if (success) {
            path = std::filesystem::path{native_path};
            NFD_FreePathN(native_path);
        }
#else
        char buffer[256];
        std::filesystem::path path;
        uwp_PickAFile(buffer);
        bool success = strlen(buffer) > 0;

        if (success) {
            path = std::filesystem::path(buffer);
        }
#endif

        callback(success, path);
    }

    void perform_file_dialog_operation_multiple(const std::function<void(bool, const std::list<std::filesystem::path>&)>& callback) {
        const nfdpathset_t* native_paths = nullptr;
        nfdresult_t result = NFD_OpenDialogMultipleN(&native_paths, nullptr, 0, nullptr);

        bool success = (result == NFD_OKAY);
        std::list<std::filesystem::path> paths;
        nfdpathsetsize_t count = 0;

        if (success) {
            NFD_PathSet_GetCount(native_paths, &count);
            for (nfdpathsetsize_t i = 0; i < count; i++) {
                nfdnchar_t* cur_path = nullptr;
                nfdresult_t cur_result = NFD_PathSet_GetPathN(native_paths, i, &cur_path);
                if (cur_result == NFD_OKAY) {
                    paths.emplace_back(std::filesystem::path{cur_path});
                }
            }
            NFD_PathSet_Free(native_paths);
        }

        callback(success, paths);
    }

    // MARK: - Public API

    std::filesystem::path get_program_path() {
#if defined(__APPLE__)
        return get_bundle_resource_directory();
#elif defined(__linux__) && defined(RECOMP_FLATPAK)
        return "/app/bin";
#else
        return "";
#endif
    }

    std::filesystem::path get_asset_path(const char* asset) {
        return get_program_path() / "assets" / asset;
    }

    void open_file_dialog(std::function<void(bool success, const std::filesystem::path& path)> callback) {
#ifdef __APPLE__
        dispatch_on_ui_thread([callback]() {
            perform_file_dialog_operation(callback);
        });
#else
        perform_file_dialog_operation(callback);
#endif
    }

    void open_file_dialog_multiple(std::function<void(bool success, const std::list<std::filesystem::path>& paths)> callback) {
#ifdef __APPLE__
        dispatch_on_ui_thread([callback]() {
            perform_file_dialog_operation_multiple(callback);
        });
#else
        perform_file_dialog_operation_multiple(callback);
#endif
    }

    void show_error_message_box(const char *title, const char *message) {
#ifdef __APPLE__
    std::string title_copy(title);
    std::string message_copy(message);

    dispatch_on_ui_thread([title_copy, message_copy] {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, title_copy.c_str(), message_copy.c_str(), nullptr);
    });
#else
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, title, message, nullptr);
#endif
    }
}
