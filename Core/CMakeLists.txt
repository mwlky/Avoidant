cmake_minimum_required(VERSION 3.10)
project(Engine)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)

add_library(Engine STATIC
        Code/Engine.cpp
        Code/Engine.h
        Code/Window/Window.cpp
        Code/Window/Window.h)

target_link_libraries(Engine SDL2::SDL2)

target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Engine PUBLIC ${SDL2_INCLUDE_DIRS})
