cmake_minimum_required(VERSION 3.23)
project(Winpux VERSION 1.0 LANGUAGES CXX)

set(LIBRARY_NAME winpux)


set(CXX_STANDARD 11)
set(CXX_EXTENSIONS OFF)


set(CROSS_PLATFORM_CPP_FILES
    src/init.cpp
)
set(CROSS_PLATFORM_H_FILES 
    
    include/winpux/winpux.h

    src/g_lib.h
    src/platform_defines.h
    src/platform_impl.h
)


add_library(
    ${LIBRARY_NAME}
    STATIC
    ${CROSS_PLATFORM_H_FILES}
    ${CROSS_PLATFORM_CPP_FILES} 
)

if (WIN32)
    target_sources(
        ${LIBRARY_NAME}
        PRIVATE

        src/win32/implementations.h
        src/win32/lightweight_windows.h

        src/win32/init.cpp
        src/win32/window.cpp
    )   

elseif (APPLE)

elseif (LINUX)

else ()
    message(FATAL_ERROR "Unsuported platform !")

endif()


target_include_directories(
    ${LIBRARY_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

set(EXECUTABLE_NAME wpx_tests)


add_executable(${EXECUTABLE_NAME} main.cpp)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE ${LIBRARY_NAME})




