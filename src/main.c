#include <raylib.h>
#include <raymath.h>
#include "globals.h"

void drawPlayerOutOfScreen(Vector2 pos, Vector2 player, Color color);
void velocityVerlet(Vector2 *position, Vector2 *velocity, float mass, float timestep);

int main(void) {

    // raylib
    InitWindow(WIDTH, HEIGHT, "Jump Thingy");

    // player
    Vector2 player = {30, 40};
    Vector2 pos = {(float) WIDTH / 2, 800};
    Vector2 screenPos;
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
    Rectangle platform = {center.x, 550, 80, 10};

    while(!WindowShouldClose()) {

        // calculate player velocity
        velocityVerlet(&pos, &velocity, mass, timestep);

        // input
        if (IsKeyDown(KEY_A))
            velocity.x = -moveSpd;
        if (IsKeyDown(KEY_D))
            velocity.x = moveSpd;
        if (IsKeyDown(KEY_S))
            velocity.x -= velocity.x * 8 * timestep;

        // handle off-screen
        if (pos.x > WIDTH) pos.x -= WIDTH;
        if (pos.x + player.x < 0) pos.x += WIDTH;

        // get player hit-box and check collision
        playerPointColl = (Rectangle) {pos.x, pos.y + player.y - 1, player.x, 1};
        if (CheckCollisionRecs(playerPointColl, ground))
            velocity.y = jumpSpd;
        if (CheckCollisionRecs(playerPointColl, platform) && velocity.y > 0.0f)
            velocity.y = jumpSpd;

        // set camera target
        target.y = target.y - 200.0f > pos.y ? pos.y + 200.0f : target.y;
        camera.target = target;

        // get player screen pos and check game over
        screenPos = GetWorldToScreen2D(pos, camera);
        if (screenPos.y > 900.0f) {
            velocity = Vector2Zero();
            pos = (Vector2) {(float) WIDTH / 2, 800};
            target = center;
        }


        BeginDrawing();

            ClearBackground(SKYBLUE);

            BeginMode2D(camera);

                // draw game scene
                DrawRectangleRec(ground, DARKGREEN);
                DrawRectangleRec(platform, PURPLE);

                // draw player
                DrawRectangleV(pos, player, RED);
                drawPlayerOutOfScreen(pos, player, RED);

            EndMode2D();

            DrawText(TextFormat("POS\n%.2f\n%.2f\n\nVEL\n%.2f\n%.2f\n\nSCREEN POS\n%.2f\n%.2f", pos.x, pos.y, velocity.x, velocity.y, screenPos.x, screenPos.y), 10, 10, 20, WHITE);
            DrawFPS(10, HEIGHT - 30);

        EndDrawing();
        timestep = GetFrameTime();

    }

    CloseWindow();

    return 0;
}

void drawPlayerOutOfScreen(Vector2 pos, Vector2 player, Color color) {
    if (pos.x < player.x) {
        DrawRectangle((int) pos.x + WIDTH, (int) pos.y, (int) player.x, (int) player.y, color);
    }
    if (pos.x + player.x > WIDTH) {
        DrawRectangle((int) pos.x - WIDTH, (int) pos.y, (int) player.x, (int) player.y, color);
    }
}

void velocityVerlet(Vector2 *position, Vector2 *velocity, float mass, float timestep) {
    Vector2 force = {-velocity->x * 4, -gravity * mass};
    Vector2 acceleration = {force.x / mass, force.y / mass};

    position->x += timestep * (velocity->x + 0.5f * timestep * acceleration.x);
    position->y += timestep * (velocity->y + 0.5f * timestep * acceleration.y);

    Vector2 newForce = {0, -gravity * mass};
    Vector2 newAcceleration = {newForce.x / mass, newForce.y / mass};

    velocity->x += timestep * 0.5f * (acceleration.x + newAcceleration.x);
    velocity->y += timestep * 0.5f * (acceleration.y + newAcceleration.y);
}