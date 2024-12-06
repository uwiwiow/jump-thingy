cmake_minimum_required(VERSION 3.29)
project(jumpThingy C)

set(CMAKE_C_STANDARD 23)

find_package(raylib REQUIRED)

add_executable(jumpThingy
        src/main.c
        includes/globals.h
        src/player.c
        includes/player.h
        src/platforms.c
        includes/platforms.h
)

target_link_libraries(jumpThingy raylib GL m pthread dl rt X11)
target_include_directories(jumpThingy PRIVATE includes)