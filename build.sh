#!/bin/bash
emcc -o jumpThingy.html src/main.c src/globals.c src/platforms.c src/player.c -Os -Wall ./libs/libraylib.a -I./includes -I/usr/include -L./libs -s USE_GLFW=3 -s ASYNCIFY -DPLATFORM_WEB