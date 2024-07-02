cmake_minimum_required(VERSION 3.10)
project(Avoidant)

set(CMAKE_CXX_STANDARD 20)

# Include Core directory
add_subdirectory("../Core" Core)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

include_directories(${CMAKE_SOURCE_DIR}/Include)
include_directories(${CMAKE_SOURCE_DIR}/Include/box2d)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    add_compile_definitions(DEBUG)
endif ()

file(GLOB Source "Code/*.cpp")

add_executable(Game "${Source}"
        Code/Player/Player.cpp
        Code/Player/Player.h
        Code/Settings.h
        Code/Map/Map.cpp
        Code/Map/Map.h
        Code/Map/Tile.cpp
        Code/Map/Tile.h
        Code/Map/TileData.h
        Code/DebugDraw.cpp
        Code/DebugDraw.h
        Code/Bullets/BulletManager.cpp
        Code/Bullets/BulletManager.h
        Code/Bullets/Bullet.cpp
        Code/Bullets/Bullet.h)

target_link_libraries(Game PUBLIC Engine ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(Game PUBLIC ${CMAKE_SOURCE_DIR}/Include/box2d/libbox2d.a)