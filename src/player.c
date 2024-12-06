#include "player.h"
#include "globals.h"

void playerDrawOutScreen(Vector2 pos, Vector2 player, Color color) {
    if (pos.x < player.x) {
        DrawRectangle((int) pos.x + WIDTH, (int) pos.y, (int) player.x, (int) player.y, color);
    }
    if (pos.x + player.x > WIDTH) {
        DrawRectangle((int) pos.x - WIDTH, (int) pos.y, (int) player.x, (int) player.y, color);
    }
}

void playerGetVelocity(Vector2 *position, Vector2 *velocity, float mass, float timestep) {
    Vector2 force = {-velocity->x * 4, -gravity * mass};
    Vector2 acceleration = {force.x / mass, force.y / mass};

    position->x += timestep * (velocity->x + 0.5f * timestep * acceleration.x);
    position->y += timestep * (velocity->y + 0.5f * timestep * acceleration.y);

    Vector2 newForce = {0, -gravity * mass};
    Vector2 newAcceleration = {newForce.x / mass, newForce.y / mass};

    velocity->x += timestep * 0.5f * (acceleration.x + newAcceleration.x);
    velocity->y += timestep * 0.5f * (acceleration.y + newAcceleration.y);
}