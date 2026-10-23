#include <iostream>

#if !defined(UNICODE)
    #define UNICODE
    
#endif

#if !defined(_UNICODE)
    #define _UNICODE

#endif

#include "windows.h"





LRESULT CALLBACK WindowProc(HWND hWnd, UINT msgId, WPARAM wParam, LPARAM lParam);

int main()
{
    const WCHAR* pClassName = L"DXWIN32WND"; 

    WNDCLASSEXW wc
    {
        .cbSize = sizeof(WNDCLASSEXW),
        .style = CS_OWNDC,
        .lpfnWndProc = WindowProc,
        .cbClsExtra = 0,
        .cbWndExtra = 0,
        .hInstance = GetModuleHandleW(nullptr),
        .hIcon = nullptr, 
        .hCursor = nullptr, 
        .hbrBackground = nullptr,
        .lpszMenuName = nullptr,
        .lpszClassName = pClassName,
        .hIconSm = nullptr
    };
    RegisterClassExW(&wc);

    HWND hWnd = CreateWindowExW(
        0, 
        pClassName, L"Window !",
        WS_OVERLAPPEDWINDOW,
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