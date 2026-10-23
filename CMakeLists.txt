cmake_minimum_required(VERSION 3.23)
project(Winpux VERSION 1.0 LANGUAGES CXX)

set(LIBRARY_NAME winpux)


set(CXX_STANDARD 11)
set(CXX_EXTENSIONS OFF)

set(CROSS_PLATFORM_CPP_FILES
    
)
set(CROSS_PLATFORM_H_FILES 
    
)


add_library(
    ${LIBRARY_NAME}
    STATIC
    ${CROSS_PLATFORM_CPP_FILES} 
    ${CROSS_PLATFORM_H_FILES}
)
target_include_directories(
    ${LIBRARY_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

set(EXECUTABLE_NAME wpx_tests)


add_executable(${EXECUTABLE_NAME} main.cpp)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE ${LIBRARY_NAME})



if(MSVC)
    target_compile_options(${EXECUTABLE_NAME} PRIVATE /std:c++20 /Wall)
else(MSVC)
    target_compile_options(${EXECUTABLE_NAME} PRIVATE -std=c++20 -Wall -Wextra)
endif(MSVC)


