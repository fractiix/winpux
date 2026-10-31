#pragma once

// Targets Windows 7
#define _WIN32_WINNT 0x0661
#include <sdkddkver.h>

// Disables all the useless stuff in windows.h

#if !defined(WIN32_LEAN_AND_MEAN)
    #define WIN32_LEAN_AND_MEAN
#endif
#if !defined(NOMINMAX)
    #define NOMINMAX
#endif
#if !defined(STRICT)
    #define STRICT
#endif


#if !defined(UNICODE)
    #define UNICODE
#endif
#if !defined(_UNICODE)
    #define _UNICODE
#endif



#include <windows.h>