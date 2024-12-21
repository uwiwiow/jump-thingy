#include <raylib.h>
#ifndef RAYGUI_IMPLEMENTATION
    #define RAYGUI_IMPLEMENTATION
#endif
#include <raygui.h>
#include "globals.h"
#include "game.h"
#include "scene.h"

int main() {

    // raylib
    SetTraceLogLevel(LOG_WARNING);
    InitWindow(Globals::WIDTH, Globals::HEIGHT, "Jump Thingy");
    GuiSetStyle(DEFAULT, TEXT_SIZE, 24);

    while(!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

        if (GuiButton({50, 50, 200, 50}, "GAME")) Game::run();
        if (GuiButton({350, 50, 200, 50}, "EDITOR")) Scene::run();

        EndDrawing();

    }

    CloseWindow();

    return 0;
}
