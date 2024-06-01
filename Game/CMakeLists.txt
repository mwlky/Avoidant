cmake_minimum_required(VERSION 3.10)
project(Avoidant)

set(CMAKE_CXX_STANDARD 20)

# Include Core directory
add_subdirectory("../Core" Core)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

if(CMAKE_BUILD_TYPE MATCHES Debug)
    add_compile_definitions(DEBUG)
endif ()

file(GLOB Source "Code/*.cpp")

add_executable(Game "${Source}"
        Code/Player/PlayerController.cpp
        Code/Player/PlayerController.h
        Code/Player/PlayerData.h)

target_link_libraries(Game PUBLIC Engine ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
