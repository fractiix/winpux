#pragma once

#include <cstdint>

namespace wpx
{
    // ID (unsigned 32-bits integer) used to identify a window
    typedef uint32_t WindowID;
    inline static constexpr WindowID INVALID_WND_ID = UINT32_MAX; 


    /*
    // ID (unsigned 32-bits integer) used to identify an image
    typedef uint32_t ImageID;
    inline static constexpr ImageID INVALID_IMAGE_ID = UINT32_MAX;



    typedef uint32_t WindowStyleFlags;

    struct WindowSpecs
    {
        WindowStyleFlags wndStyleFlags{};
        uint32_t initialXPos{};
        uint32_t initialYPos{};
        ImageID smallIcon{};
        ImageID bigIcon{};
    };

    */




    

    
    bool InitWindow(
        const WindowID wndID, 
        const uint32_t clientWidth, const uint32_t clientHeight,
        const char* const wndTitle/*, 
        const WindowSpecs& windowSpecifications*/
    );
    void TerminateWindow(WindowID wndID);

    /*
    inline static constexpr WindowStyleFlags RESIZABLE              = 0x00000001;
    inline static constexpr WindowStyleFlags CENTERED               = 0x00000002;
    inline static constexpr WindowStyleFlags NO_AUTOPAINT           = 0x00000004;
    inline static constexpr WindowStyleFlags NEW_DEVICE_CONTEXT     = 0x00000008;
    inline static constexpr WindowStyleFlags DEFAULT_X_POS          = 0x00000010;
    inline static constexpr WindowStyleFlags DEFAULT_Y_POS          = 0x00000020;
    inline static constexpr WindowStyleFlags MINIMIZED_ON_INIT      = 0x00000040;
    inline static constexpr WindowStyleFlags MAXIMIZED_ON_INIT      = 0x00000080;
    inline static constexpr WindowStyleFlags CLOSE_BOX              = 0x00000100;
    inline static constexpr WindowStyleFlags MINIMIZE_BOX           = 0x00000200;
    inline static constexpr WindowStyleFlags MAXIMIZE_BOX           = 0x00000400;
    */




    bool Initialize();
    void Shutdown();



    enum class EventType
    {
        WindowMove,
        WindowResize,

        WindowClose,
    };

    struct Event
    {
        Event() = default; 

        WindowID wndID = INVALID_WND_ID;
        EventType type;

        union
        {
            struct { uint32_t xPos{}, yPos{}; } move; 
            struct { uint32_t width{}, height{}; } resize; 
        };
    };


    void PollEvents();
    bool PollEvent(Event* event);


    

} // namespace wpx