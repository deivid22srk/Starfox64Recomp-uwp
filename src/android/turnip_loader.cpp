#ifdef __ANDROID__

#include "turnip_loader.h"

#include <android/log.h>
#include <dlfcn.h>
#include <fstream>
#include <filesystem>
#include <jni.h>

#include <SDL.h>
#include <SDL_system.h>
#include <vulkan/vulkan.h>

#include <adrenotools/driver.h>

#define LOG_TAG "TurnipLoader"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

namespace plume {
    PFN_vkGetInstanceProcAddr android_vulkanGetInstanceProcAddr = nullptr;
}

namespace TurnipLoader {

static DriverInfo g_info;
static std::string g_driverPath;
static bool g_configLoaded = false;

static std::string getConfigPath() {
    const char *internalPath = SDL_AndroidGetInternalStoragePath();
    if (!internalPath) return "";
    return std::string(internalPath) + "/turnip_driver.txt";
}

static void loadConfig() {
    if (g_configLoaded) return;
    g_configLoaded = true;

    std::string configPath = getConfigPath();
    if (configPath.empty()) return;

    std::ifstream file(configPath);
    if (file.is_open()) {
        std::getline(file, g_driverPath);
        file.close();
        LOGI("Loaded driver config: %s", g_driverPath.c_str());
    }
}

static std::string getNativeLibraryDir() {
    JNIEnv *env = (JNIEnv *)SDL_AndroidGetJNIEnv();
    if (!env) return "";

    jobject activity = (jobject)SDL_AndroidGetActivity();
    if (!activity) return "";

    jclass clazz = env->GetObjectClass(activity);
    jmethodID getApplicationInfo = env->GetMethodID(clazz, "getApplicationInfo", "()Landroid/content/pm/ApplicationInfo;");
    jobject appInfo = env->CallObjectMethod(activity, getApplicationInfo);

    jclass appInfoClass = env->GetObjectClass(appInfo);
    jfieldID nativeLibraryDirField = env->GetFieldID(appInfoClass, "nativeLibraryDir", "Ljava/lang/String;");
    jstring nativeLibraryDir = (jstring)env->GetObjectField(appInfo, nativeLibraryDirField);

    std::string result;
    if (nativeLibraryDir) {
        const char *str = env->GetStringUTFChars(nativeLibraryDir, nullptr);
        result = str;
        env->ReleaseStringUTFChars(nativeLibraryDir, str);
    }

    env->DeleteLocalRef(activity);
    return result;
}

DriverInfo &get() {
    return g_info;
}

bool isCustomDriverConfigured() {
    loadConfig();
    return !g_driverPath.empty() && std::filesystem::exists(g_driverPath);
}

std::string getCustomDriverDir() {
    loadConfig();
    if (g_driverPath.empty()) return "";
    std::filesystem::path p(g_driverPath);
    return p.parent_path().string();
}

std::string getCustomDriverName() {
    loadConfig();
    if (g_driverPath.empty()) return "";
    std::filesystem::path p(g_driverPath);
    return p.filename().string();
}

void setCustomDriverPath(const std::string &path) {
    g_driverPath = path;
    std::string configPath = getConfigPath();
    if (!configPath.empty()) {
        std::ofstream file(configPath);
        if (file.is_open()) {
            file << path;
            file.close();
            LOGI("Saved driver config: %s", path.c_str());
        }
    }
}

bool loadCustomDriver() {
    if (g_info.loaded) return true;
    if (!isCustomDriverConfigured()) {
        LOGI("No custom driver configured");
        return false;
    }

    std::string driverDir = getCustomDriverDir();
    std::string driverName = getCustomDriverName();
    std::string hookDir = getNativeLibraryDir();
    std::string tmpDir = std::string(SDL_AndroidGetInternalStoragePath()) + "/tmp_lib";

    // adrenotools concatenates dir+name without separator, ensure trailing slash
    if (!driverDir.empty() && driverDir.back() != '/') {
        driverDir += '/';
    }

    LOGI("Loading custom driver: dir=%s name=%s hookDir=%s tmpDir=%s",
         driverDir.c_str(), driverName.c_str(), hookDir.c_str(), tmpDir.c_str());

    std::filesystem::create_directories(tmpDir);

    void *handle = adrenotools_open_libvulkan(
        RTLD_NOW,
        ADRENOTOOLS_DRIVER_CUSTOM,
        tmpDir.c_str(),
        hookDir.c_str(),
        driverDir.c_str(),
        driverName.c_str(),
        nullptr,
        nullptr
    );

    if (!handle) {
        LOGE("adrenotools_open_libvulkan failed");
        return false;
    }

    PFN_vkGetInstanceProcAddr getProcAddr = (PFN_vkGetInstanceProcAddr)dlsym(handle, "vkGetInstanceProcAddr");
    if (!getProcAddr) {
        LOGE("Failed to get vkGetInstanceProcAddr from custom driver");
        dlclose(handle);
        return false;
    }

    plume::android_vulkanGetInstanceProcAddr = getProcAddr;
    g_info.libvulkanHandle = handle;
    g_info.adrenotoolsHandle = handle;
    g_info.loaded = true;

    LOGI("Custom driver loaded successfully");
    return true;
}

}

extern "C" void android_loadTurnipDriver() {
    TurnipLoader::loadCustomDriver();
}

#endif
