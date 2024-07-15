cmake_minimum_required(VERSION 3.10)
project(Engine)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    add_compile_definitions(DEBUG)
endif ()

add_library(Engine STATIC
        Code/Engine.cpp
        Code/Engine.h
        Code/Window/Window.cpp
        Code/Window/Window.h
        Code/Utilities/SpriteLoader.cpp
        Code/Utilities/SpriteLoader.h
        Code/Math/Vector2.cpp
        Code/Math/Vector2.h
        Code/Utilities/Macros.h
        Code/Math/Math.cpp
        Code/Math/Math.h
        Code/Utilities/Application.cpp
        Code/Utilities/Application.h)

target_link_libraries(Engine PUBLIC SDL2::SDL2 SDL2_image)

target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Engine PUBLIC ${SDL2_INCLUDE_DIRS})
target_include_directories(Engine PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS})
