#include "game.h"
#include <raylib.h>
#include <raygui.h>
#include "globals.h"
#include "player.h"
#include "platforms.h"

namespace Game {

    int run() {

        int option = 0;
        GuiSetStyle(DEFAULT, TEXT_SIZE, 36);

        while (!WindowShouldClose()) {

            if (option != 0) break;

            BeginDrawing();
            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

            if (GuiButton({(((float) Globals::WIDTH / 2) - 200), 200, 400, 150}, "Infinite mode")) option = 1;
            if (GuiButton({(((float) Globals::WIDTH / 2) - 200), 550, 400, 150}, "Level mode")) option = 2;

            EndDrawing();
        }

        switch (option) {
            case 1:
                Game::infinite();
                break;
            case 2:
            default:
                break;
        }

        GuiSetStyle(DEFAULT, TEXT_SIZE, 24);


        return 0;
    }

    int infinite() {

        // player
        Player player({30, 40},
                      {(float) Globals::WIDTH / 2, 800},
                      {0, 0},
                      {0, 0, 0, 0},
                      1.0f);

        // camera
        Vector2 center = {(float) Globals::WIDTH / 2, (float) Globals::HEIGHT / 2};
        Camera2D camera = {{0, 0}, {0, 0}, 0, 0};
        camera.zoom = 1.0f;
        camera.offset = center;
        Vector2 target = center;


        // game
        float timestep = 0.0f;
        Rectangle ground = {0, 800, Globals::WIDTH, Globals::HEIGHT};

        // platforms
        Vector2 platforms[5];
        Vector2 platformSize = {80, 10};
        float platformStart = 550.0f;
        float platformGap = 250.0f;
        Rectangle killZone = {-Globals::WIDTH, Globals::HEIGHT, 2 * Globals::WIDTH, 200.0f};
        platformsInit(platforms, platformSize, &platformStart, platformGap);

        // game loop
        while (!WindowShouldClose()) {

            timestep = GetFrameTime();

            // input
            if (IsKeyDown(KEY_A))
                player.velocity.x = -Globals::moveSpd;
            if (IsKeyDown(KEY_D))
                player.velocity.x = Globals::moveSpd;
            if (IsKeyDown(KEY_S)) {
                player.velocity.x -= player.velocity.x * 8 * timestep;
                if (player.velocity.y > 0.0f)
                    player.velocity.y += player.velocity.y * 4 * timestep;
            }

#if DEBUG
            if (IsKeyDown(KEY_C))
                player.pos = {(float) Globals::WIDTH / 2, 800};
#endif


            // calculate player velocity
            playerGetVelocity(&player.pos, &player.velocity, player.mass, timestep);


            // handle off-screen
            if (player.pos.x > Globals::WIDTH) player.pos.x -= Globals::WIDTH;
            if (player.pos.x + player.size.x < 0) player.pos.x += Globals::WIDTH;


            // set camera target
            target.y = target.y - 200.0f > player.pos.y ? player.pos.y + 200.0f : target.y;
            camera.target = target;


            // update kill zone
            killZone.y = target.y + center.y;


            // get player hit-box and check collisions
            player.playerPointColl = {player.pos.x, player.pos.y + player.size.y - 1, player.size.x, 1};

            if (CheckCollisionRecs(player.playerPointColl, ground))
                player.velocity.y = Globals::jumpSpd;

            platformsCheckCollision(platforms, platformSize, player.playerPointColl, killZone,
                                    &player.velocity, &platformStart, platformGap);


            // check game over or reset
            if (CheckCollisionPointRec(player.pos, killZone) || IsKeyPressed(KEY_R)) {
                // reset player params
                player.velocity = {0, 0};
                player.pos = {(float) Globals::WIDTH / 2, 800};

                // reset camera target
                target = center;

                // reset platforms params
                platformStart = 550.0f;
                platformsInit(platforms, platformSize, &platformStart, platformGap);
            }


            BeginDrawing();

            ClearBackground(SKYBLUE);

            BeginMode2D(camera);

            // draw game scene
            DrawRectangleRec(ground, DARKGREEN);
            platformsDraw(platforms, platformSize);

            // draw player
            DrawRectangleV(player.pos, player.size, RED);
            playerDrawOutScreen(player.pos, player.size, RED);

            EndMode2D();

            DrawText(TextFormat("POS\n%.2f\n%.2f\n\nVEL\n%.2f\n%.2f", player.pos.x, player.pos.y, player.velocity.x,
                                player.velocity.y), 10, 10, 20, WHITE);

            DrawFPS(10, Globals::HEIGHT - 30);


#if DEBUG
            platformsDrawPos(platforms);
#endif

            EndDrawing();

        }

        return 0;
    }
}