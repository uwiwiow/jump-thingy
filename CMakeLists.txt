cmake_minimum_required(VERSION 3.29)
project(jumpThingy CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")

find_package(raylib REQUIRED)

add_executable(jumpThingy
        src/main.cpp
        includes/globals.h
        src/player.cpp
        includes/player.h
        src/platforms.cpp
        includes/platforms.h
        src/game.cpp
        includes/game.h
        src/scene.cpp
        includes/scene.h
        src/object.cpp
        includes/object.h
)

target_link_libraries(jumpThingy raylib GL m pthread dl rt X11)
target_include_directories(jumpThingy PRIVATE includes)