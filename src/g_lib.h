#pragma once

#include "./platform_impl.h"


#include <vector>
#include <queue>



namespace wpx
{
    struct Lib;

    // The global state of the library, containing everything, and accessed by every file
    extern Lib g_Lib;



    struct FnPointers
    {
        bool (*pfn_InitWindow)(WindowID, uint32_t, uint32_t, const char* /*, const WindowSpecs&*/); // id, cwidth, cheight, title, specs 
        void (*pfn_TerminateWindow)(WindowID); // id

        bool (*pfn_PollEvent)(Event*); // event
        bool (*pfn_WaitEvent)(Event*); // event

        bool (*pfn_Initialize)();
        void (*pfn_Terminate)();
    };



    struct Lib
    {
        FnPointers pfns;

        // Defined in platform_impl.h
        Implementations impl;

        std::queue<Event> eventQ;
    };
}