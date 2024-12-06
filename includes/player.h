#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

/**
 * @brief Draws the player's rectangle when it goes out of the screen bounds,
 * wrapping it to the opposite side of the screen.
 *
 * @param pos Current position of the player.
 * @param player Dimensions of the player's rectangle.
 * @param color Color of the rectangle to draw.
 */
void playerDrawOutScreen(Vector2 pos, Vector2 player, Color color);

/**
 * @brief Updates the player's position and velocity based on forces,
 * gravity, and the provided timestep using a basic physics simulation.
 *
 * @param position Pointer to the player's current position.
 * @param velocity Pointer to the player's current velocity.
 * @param mass Mass of the player, used in force calculations.
 * @param timestep Time step for the simulation, controlling precision.
 */
void playerGetVelocity(Vector2 *position, Vector2 *velocity, float mass, float timestep);


#endif //PLAYER_H
