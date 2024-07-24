cmake_minimum_required(VERSION 3.10)
project(Avoidant)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory("../Core" Core)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
include_directories(${SDL2_TTF_INCLUDE_DIRS})

include_directories(${CMAKE_SOURCE_DIR}/Include)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    add_compile_definitions(DEBUG)
endif ()

file(GLOB_RECURSE GAME_SOURCES "Code/*.cpp" "Code/*.h" "../Core/*.cpp" "../Core/*.h")

add_executable(Game ${GAME_SOURCES})

target_link_libraries(Game PUBLIC Engine
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        ${CMAKE_SOURCE_DIR}/Include/box2d/libbox2d.a
        ${CMAKE_SOURCE_DIR}/Include/SDL2_ttf/libSDL2_ttf.so)
