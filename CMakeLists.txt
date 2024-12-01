cmake_minimum_required(VERSION 3.29)
project(jumpThingy C)

set(CMAKE_C_STANDARD 23)

find_package(raylib REQUIRED)

add_executable(jumpThingy src/main.c
        src/globals.c
        includes/globals.h)

target_link_libraries(jumpThingy raylib GL m pthread dl rt X11)
target_include_directories(jumpThingy PRIVATE includes)