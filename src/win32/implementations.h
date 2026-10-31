#pragma once

#include "winpux/winpux.h" 
#include "./lightweight_windows.h"

namespace wpx
{
    struct Win32_WindowImpl
    {
        WindowID internalID{};
        WindowID userID{};
        
        ::HWND handle;
        // Each window will have its own WNDCLASSEXW, so that we can create multiple ones, 
        // and that when one window is destroyed, the other ones aren't
        ::WNDCLASSEXW wndClass;

        
        uint32_t cWidth{}, cHeight{}; // width and height of the client area
        uint32_t cXPos{}, yPos{}; // x and y position of the client area
    };

    


    struct Win32_Lib
    {
        // The one HINSTANCE used for the entirety of the lifetime of the library
        ::HINSTANCE hInstance;
    }; 



    LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

    WCHAR* Win32_CharToWideChar(const char* source);
    char* Win32_WideCharToChar(const WCHAR* source);


    bool Win32_InitWindow(WindowID wndID, uint32_t cWidth, uint32_t cHeight, const char* title/*, const WindowSpecs& specs*/ );
    void Win32_TerminateWindow(WindowID wndID);

    bool Win32_PollEvent(Event* pEvent); 
    bool Win32_WaitEvent(Event* pEvent); 

    bool Win32_Initialize();
    void Win32_Terminate();

} // namespace wpx