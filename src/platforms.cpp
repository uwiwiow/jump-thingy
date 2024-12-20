#include "platforms.h"
#include "globals.h"

void platformsInit(Vector2 platforms[5], Vector2 platformSize, float *start, float gap) {
    for(int i = 0; i < 5; i++) {
        platforms[i] = {(float) GetRandomValue(0,  Globals::WIDTH - (int) platformSize.x), *start};
        *start -= gap;
    }
}

void platformsDraw(Vector2 platforms[5], Vector2 platformSize) {
    for(int i = 0; i < 5; i++) {
        DrawRectangleV(platforms[i], platformSize, PURPLE);
    }
}

void platformUpdate(Vector2 *platform, Vector2 platformSize, float *start, float gap) {
    *platform = {(float) GetRandomValue(0, Globals::WIDTH - (int) platformSize.x), *start};
    *start -= gap;
}

void platformsCheckCollision(Vector2 platforms[5], Vector2 platformSize, Rectangle playerPointColl, Rectangle killZone, Vector2 *velocity, float *start, float gap) {
    Rectangle platform;
    for(int i = 0; i < 5; i++) {
        platform = {platforms[i].x, platforms[i].y, platformSize.x, platformSize.y};
        if (CheckCollisionRecs(playerPointColl,
                               platform)
            && velocity->y > 0.0f) {
            velocity->y = Globals::jumpSpd;
        }
        if (CheckCollisionRecs(killZone,
                               platform)) {
            platformUpdate(&platforms[i], platformSize, start, gap);
        }

    }
}

void platformsDrawPos(Vector2 platforms[5]) {
    int start = 170;
    int gap = 16;
    for(int i = 0; i < 5; i++) {
        DrawText(TextFormat("%d\t\t%.0f\t\t%.0f", i, platforms[i].x, platforms[i].y), 10, start, 20, WHITE);
        start += gap;
    }
}