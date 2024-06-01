cmake_minimum_required(VERSION 3.10)
project(Engine)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_library(Engine STATIC
        Code/Engine.cpp
        Code/Engine.h
        Code/Window/Window.cpp
        Code/Window/Window.h
        Code/Utilities/SpriteLoader.cpp
        Code/Utilities/SpriteLoader.h
        Code/Math/Vector2.cpp
        Code/Math/Vector2.h)

target_link_libraries(Engine PUBLIC SDL2::SDL2 SDL2_image)

target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Engine PUBLIC ${SDL2_INCLUDE_DIRS})
target_include_directories(Engine PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS})
