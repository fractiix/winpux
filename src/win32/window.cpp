#include "../g_lib.h"
#include <math.h>
#include <string.h>
#include <stdio.h>

namespace wpx
{
    bool Win32_InitWindow(WindowID wndID, uint32_t cWidth, uint32_t cHeight, const char* title/*, const WindowSpecs& wndSpecs*/)
    {
        Win32_WindowImpl wnd{};

        // This looks horrible, but it gets the number of digits of the wndID,
        // and allocates that much bytes
        char* userIDstr = (char*)malloc( sizeof(char) * (size_t)log10((double)wndID) );
        sprintf(userIDstr, "%d", wndID);
        // And then it creates a char* like that : WPX_WND_CLASS_NAME_%userID%
        char* baseClassName = "WPX_WND_CLASS_NAME_";
        char* className = (char*)malloc(strlen(userIDstr) + strlen(baseClassName) + 1);
        className = baseClassName;
        strcat(className, userIDstr);
        



        WNDCLASSEXW wc;
        wc.cbSize = sizeof(WNDCLASSEXW);       
        wc.style = 0; // since each window has its own WNDCLASSEXW, CS_OWNDC is not required
        wc.lpfnWndProc = WindowProc;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hInstance = g_Lib.impl.library.hInstance;
        wc.hIcon = nullptr;
        wc.hCursor = nullptr;
        wc.hbrBackground = nullptr;
        wc.lpszMenuName = nullptr;
        wc.lpszClassName = Win32_CharToWideChar(className);
        wc.hIconSm = nullptr;

        RegisterClassExW(&wc);
        wnd.wndClass = wc;



        wnd.handle = CreateWindowExW(
            0, 
            wnd.wndClass.lpszClassName, Win32_CharToWideChar(title),
            WS_OVERLAPPEDWINDOW, 
            CW_USEDEFAULT, CW_USEDEFAULT, static_cast<int>(cWidth), static_cast<int>(cHeight),
            nullptr, nullptr, g_Lib.impl.library.hInstance, nullptr
        );

        // Sets the window client area to the correct values (the one asked by the user)
        SetWindowPos(wnd.handle, HWND_TOP, 0, 0, cWidth, cHeight, SWP_NOMOVE | SWP_NOZORDER);



        // ... I need to handle all the ID stuff, and the basic window creation should be done
    }
}