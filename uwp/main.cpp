#include <Windows.h>
#include "SDL2/SDL.h"

// If I don't include this for some reason the game_warps don't get initialized?
#include "../include/zelda_debug.h"

extern "C" __declspec(dllimport) void* uwp_GetWindowReference();

#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Graphics.Display.Core.h>
using namespace winrt;
using namespace Windows;
using namespace Windows::Graphics::Display::Core;

void EnableHDR() {
    auto hdi = HdmiDisplayInformation::GetForCurrentView();
    // HDR Setup
    auto modes = hdi.GetSupportedDisplayModes();
    for (unsigned i = 0; i < modes.Size(); i++) {
        auto mode = modes.GetAt(i);
        if (mode.ColorSpace() == HdmiDisplayColorSpace::BT2020 && mode.RefreshRate() >= 59) {
            // TODO: Optionally enable dolbyvision (how to check for support?
            // HdmiDisplayHdrOption::DolbyVisionLowLatency)
            hdi.RequestSetCurrentDisplayModeAsync(mode, HdmiDisplayHdrOption::Eotf2084);
            break;
        }
    }
}


int bootstrap(int argc, char** argv)
{
    uwp_GetWindowReference(); // Call once to init reference for other threads
    //EnableHDR();

    return SDL_main(argc, argv);
}

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR argv, int argc)
{
    auto warps = zelda64::game_warps;

    return SDL_WinRTRunApp(bootstrap, NULL);
}
