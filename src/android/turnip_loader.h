#pragma once

#ifdef __ANDROID__

#include <string>

namespace TurnipLoader {

struct DriverInfo {
    bool loaded = false;
    void *libvulkanHandle = nullptr;
    void *adrenotoolsHandle = nullptr;
};

DriverInfo &get();
bool isCustomDriverConfigured();
std::string getCustomDriverDir();
std::string getCustomDriverName();
bool loadCustomDriver();
void setCustomDriverPath(const std::string &path);

}

#endif
