cmake_minimum_required(VERSION 3.10)
project(Avoidant)

set(CMAKE_CXX_STANDARD 20)

# Include Core directory
add_subdirectory("../Core" Core)

file(GLOB Source "Code/*.cpp")

add_executable(Game "${Source}"
        Code/Data/WindowSettings.h
        Code/Game.cpp
        Code/Game.h)
target_link_libraries(Game PUBLIC Engine)