#include <iostream>

#if !defined(UNICODE)
    #define UNICODE
    
#endif

#if !defined(_UNICODE)
    #define _UNICODE

#endif

#include "windows.h"
#include "winpux/winpux.h"


LRESULT CALLBACK WindowProc(HWND hWnd, UINT msgId, WPARAM wParam, LPARAM lParam);


int main()
{
    HWND hWnd = CreateWindowExW(
        0, 
        pClassName, L"Window !",
        WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, 640, 360,
        nullptr, nullptr, 
        GetModuleHandleW(nullptr), 
        nullptr
    );

    ShowWindow(hWnd, SW_MINIMIZE);
    ShowWindow(hWnd, SW_RESTORE);
    UpdateWindow(hWnd);

    MSG msg{};
    BOOL bResult{};

    while(GetMessageW(&msg, nullptr, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    if (bResult == -1)
        return -1;

    else
        return msg.wParam;


    return 0;


    if (!wpx::Initialize())
        return -1;

    if (!wpx::InitWindow(0, 640, 360, "Window", wpx::NO_AUTOPAINT | wpx::DEFAULT_Y_POS /*| wpx::WPX_DEFAULT_X_POS*/));
    (wpx::NO_AUTOPAINT | wpx::DEFAULT_Y_POS) & wpx::NO_AUTOPAINT;
    (wpx::NO_AUTOPAINT | wpx::DEFAULT_Y_POS) & wpx::RESIZABLE;

    wpx::Shutdown();




}



LRESULT CALLBACK WindowProc(HWND hWnd, UINT msgId, WPARAM wParam, LPARAM lParam)
{
    switch (msgId)
    {
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    }

    return DefWindowProcW(hWnd, msgId, wParam, lParam);
}