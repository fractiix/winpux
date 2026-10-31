#pragma once

#if defined(_WIN32)
    #define WPX_PLATFORM_WIN32

#elif defined(__MACH__)
    #define WPX_PLATFORM_MACOS

#elif defined(__linux__)
    #define WPX_PLATFORM_LINUX

#else
    #error "Unsupported platform !"

#endif