#include "../g_lib.h"

namespace wpx
{
    WCHAR* Win32_CharToWideChar(const char* source)
    {
        // Since the last two parameters (destination and size to copy to dest) are null,
        // the function returns the size of the memory to copy 
        size_t pWideCharLen = MultiByteToWideChar(CP_UTF8, 0, source, -1, nullptr, 0);
        WCHAR* pWideChar = (WCHAR*)malloc(sizeof(WCHAR) * pWideCharLen);
        // The last two parameters are non-null, the functions runs normally
        // (if it fails, it returns a non-zero value, but we assume it's not going to :) )
        MultiByteToWideChar(CP_UTF8, 0, source, -1, pWideChar, pWideCharLen);
    }

    char* Win32_WideCharToChar(const WCHAR* source)
    {
        // Same thing as the function above, but this time the types are inverted
        size_t pCharLen = WideCharToMultiByte(CP_UTF8, 0, source, -1, nullptr, 0, nullptr, nullptr);
        char* pChar = (char*)malloc(sizeof(char) * pCharLen);
        WideCharToMultiByte(CP_UTF8, 0, source, -1, pChar, pCharLen, nullptr, nullptr);
    }


    bool Win32_Initialize()
    {
        g_Lib.impl.library.hInstance = reinterpret_cast<HINSTANCE>(GetModuleHandleW(NULL)); 

        return true;
    }
}