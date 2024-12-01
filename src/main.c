#include <raylib.h>
#include <raymath.h>
#include "globals.h"

void drawPlayerOutOfScreen(Vector2 pos, Vector2 player, Color color);
void velocityVerlet(Vector2 *position, Vector2 *velocity, float mass, float timestep);

int main(void) {

    InitWindow(WIDTH, HEIGHT, "Jump Thingy");

    // player
    Vector2 player = {30, 40};
    Vector2 pos = {(float) WIDTH / 2, 50};
    Vector2 velocity = Vector2Zero();
    float mass = 1.0f;

    // game
    float timestep = 0.0f;

    while(!WindowShouldClose()) {

        velocityVerlet(&pos, &velocity, mass, timestep);

        if (IsKeyPressed(KEY_SPACE) && velocity.y > 0.0f)
            velocity.y = -1000.0f;
        if (IsKeyDown(KEY_A))
            velocity.x = -300.0f;
        if (IsKeyDown(KEY_D))
            velocity.x = 300.0f;
        if (IsKeyDown(KEY_S))
            velocity.x -= velocity.x * 8 * timestep;

        if (pos.x > WIDTH) pos.x -= WIDTH;
        if (pos.x + player.x < 0) pos.x += WIDTH;
//        if (pos.y > HEIGHT) pos.y -= HEIGHT;
//        if (pos.y + player.y < 0) pos.y += HEIGHT;

        BeginDrawing();

        ClearBackground(BLACK);

        // draw player
        DrawRectangleV(pos, player, RED);
        drawPlayerOutOfScreen(pos, player, RED);

        DrawText(TextFormat("POS\n%.2f\n%.2f\n\nVEL\n%.2f\n%.2f", pos.x, pos.y, velocity.x, velocity.y), 10, 10, 20, WHITE);
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

//    if (pos.y < player.y) {
//        DrawRectangle((int) pos.x, (int) pos.y + HEIGHT, (int) player.x, (int) player.y, color);
//    }
//    if (pos.y + player.y > HEIGHT) {
//        DrawRectangle((int) pos.x, (int) pos.y - HEIGHT, (int) player.x, (int) player.y, color);
//    }
//
//    if (pos.x < player.x && pos.y < player.y) {
//        DrawRectangle((int) pos.x + WIDTH, (int) pos.y + HEIGHT, (int) player.x, (int) player.y, color);
//    }
//    if (pos.x + player.x > WIDTH && pos.y < player.y) {
//        DrawRectangle((int) pos.x - WIDTH, (int) pos.y + HEIGHT, (int) player.x, (int) player.y, color);
//    }
//    if (pos.x < player.x && pos.y + player.y > HEIGHT) {
//        DrawRectangle((int) pos.x + WIDTH, (int) pos.y - HEIGHT, (int) player.x, (int) player.y, color);
//    }
//    if (pos.x + player.x > WIDTH && pos.y + player.y > HEIGHT) {
//        DrawRectangle((int) pos.x - WIDTH, (int) pos.y - HEIGHT, (int) player.x, (int) player.y, color);
//    }
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