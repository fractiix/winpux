#pragma once

#include "./platform_defines.h"
#include <vector>

#if defined(WPX_PLATFORM_WIN32)
    #include "./win32/implementations.h"

namespace wpx
{
    // Struct containing all the Win32-specific stuff...
    struct Win32_Impl
    {
        struct
        {
            std::vector<Win32_WindowImpl> wnds;
            std::vector<WindowID> freeWndIDs;
        } handles;
        Win32_Lib library{};
    };

    // ...typedef'd so that I don't have to use #ifdef _WIN32 in the global data
    typedef Win32_Impl Implementations;

} // namespace wpx

#elif defined(WPX_PLATFORM_MACOS)
    #include "./cocoa/implementations.h"

#elif defined(WPX_PLATFORM_LINUX)
    #include "./x11/implementations.h"
    #include "./wayland/implementations.h"

#endif


