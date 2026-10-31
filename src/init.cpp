#include "./g_lib.h"

namespace wpx
{
    // Default every value of g_Lib
    Lib g_Lib = Lib{};



    bool Initialize()
    {
    #if defined(WPX_PLATFORM_WIN32)
        FnPointers targetPlatformPFNs
        {
            .pfn_InitWindow              = Win32_InitWindow,
            .pfn_TerminateWindow         = Win32_TerminateWindow,

            .pfn_PollEvent               = Win32_PollEvent,
            .pfn_WaitEvent               = Win32_WaitEvent,

            .pfn_Initialize              = Win32_Initialize,
            .pfn_Terminate               = Win32_Terminate,
        };

    #elif defined(WPX_PLATFORM_MACOS)
        FnPointers targetPlatformPFNs
        {
            .pfn_InitWindow              = Cocoa_InitWindow,
            .pfn_TerminateWindow         = Cocoa_TerminateWindow,

            .pfn_PollEvent               = Cocoa_PollEvent,
            .pfn_WaitEvent               = Cocoa_WaitEvent,

            .pfn_Initialize              = Cocoa_Initialize,
            .pfn_Terminate               = Cocoa_Terminate,
        };

    #elif defined(WPX_PLATFORM_LINUX)
        FnPointers targetPlatformPFNs;

        // We dynamically detect if the user is on Wayland or X11, and set the PFNs accordingly

        if (strcmp(getenv("XDG_SESSION_TYPE"), "wayland") == 0)
        {
            targetPlatformPFNs.pfn_InitWindow              = Wayland_InitWindow;
            targetPlatformPFNs.pfn_TerminateWindow         = Wayland_TerminateWindow;

            targetPlatformPFNs.pfn_PollEvent               = Wayland_PollEvent;
            targetPlatformPFNs.pfn_WaitEvent               = Wayland_WaitEvent;

            targetPlatformPFNs.pfn_Initialize              = Wayland_Initialize;
            targetPlatformPFNs.pfn_Terminate               = Wayland_Terminate;
        }
        else
        {
            targetPlatformPFNs.pfn_InitWindow              = X11_InitWindow;
            targetPlatformPFNs.pfn_TerminateWindow         = X11_TerminateWindow;

            targetPlatformPFNs.pfn_PollEvent               = X11_PollEvent;
            targetPlatformPFNs.pfn_WaitEvent               = X11_WaitEvent;

            targetPlatformPFNs.pfn_Initialize              = X11_Initialize;
            targetPlatformPFNs.pfn_Terminate               = X11_Terminate;
        }

    #endif

        g_Lib.pfns = targetPlatformPFNs;


        g_Lib.pfns.pfn_Initialize();
    }

} // namespace wpx