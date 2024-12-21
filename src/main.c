#include <raylib.h>
#include <raymath.h>
#include "globals.h"
#include "player.h"
#include "platforms.h"
#include "utils.h"


int main(void) {

    // raylib
    SetTraceLogLevel(LOG_WARNING);
    InitWindow(WIDTH, HEIGHT, "Jump Thingy");

    // player
    Vector2 player = {30, 40};
    Vector2 pos = {(float) WIDTH / 2, 800};
    Vector2 velocity = Vector2Zero();
    Rectangle playerPointColl;
    float mass = 1.0f;

    // camera
    Vector2 center = {(float) WIDTH / 2, (float) HEIGHT / 2};
    Camera2D camera = { 0 };
    camera.zoom = 1.0f;
    camera.offset = center;
    Vector2 target = center;

    // game
    float timestep = 0.0f;
    Rectangle ground = {0, 800, WIDTH, HEIGHT};

    // platforms
    Vector2 platforms [5];
    Vector2 platformSize = {80, 10};
    float platformStart = 550.0f;
    float platformGap = 250.0f;
    Rectangle killZone = {-WIDTH, HEIGHT, 2 *WIDTH, 200.0f};
    platformsInit(platforms, platformSize, &platformStart, platformGap);

    // TODO: refactor to not use WindowShouldClose
    // game loop
    while(!WindowShouldClose()) {

        // input
        if (IsKeyDown(KEY_A))
            velocity.x = -moveSpd;
        if (IsKeyDown(KEY_D))
            velocity.x = moveSpd;
        if (IsKeyDown(KEY_S)) {
            velocity.x -= velocity.x * 8 * timestep;
            if (velocity.y > 0.0f)
                velocity.y += velocity.y * 4 * timestep;
        }

#if DEBUG
        if (IsKeyDown(KEY_C))
            pos = vector2((float) WIDTH / 2, 800);
#endif


        // calculate player velocity
        playerGetVelocity(&pos, &velocity, mass, timestep);


        // handle off-screen
        if (pos.x > WIDTH) pos.x -= WIDTH;
        if (pos.x + player.x < 0) pos.x += WIDTH;


        // set camera target
        target.y = target.y - 200.0f > pos.y ? pos.y + 200.0f : target.y;
        camera.target = target;


        // update kill zone
        killZone.y = target.y + center.y;


        // get player hit-box and check collisions
        playerPointColl = rectangle(pos.x, pos.y + player.y - 1, player.x, 1);

        if (CheckCollisionRecs(playerPointColl, ground))
            velocity.y = jumpSpd;

        platformsCheckCollision(platforms, platformSize, playerPointColl, killZone,
                                &velocity, &platformStart, platformGap);


        // check game over or reset
        if (CheckCollisionPointRec(pos, killZone) || IsKeyPressed(KEY_R)) {
            // reset player params
            velocity = Vector2Zero();
            pos = vector2((float) WIDTH / 2, 800);

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
                DrawRectangleV(pos, player, RED);
                playerDrawOutScreen(pos, player, RED);

            EndMode2D();

            DrawText(TextFormat("POS\n%.2f\n%.2f\n\nVEL\n%.2f\n%.2f", pos.x, pos.y, velocity.x, velocity.y), 10, 10, 20, WHITE);

#if DEBUG
            platformsDrawPos(platforms);
#endif

            DrawFPS(10, HEIGHT - 30);

        EndDrawing();
        timestep = GetFrameTime();

    }

    CloseWindow();

    return 0;
}
