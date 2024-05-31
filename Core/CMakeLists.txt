cmake_minimum_required(VERSION 3.10)
project(Engine)

set(CMAKE_CXX_STANDARD 20)

add_library(Engine STATIC
        Code/Engine.cpp
        Code/Engine.h)
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})