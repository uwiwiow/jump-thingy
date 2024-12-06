#ifndef PLATFORMS_H
#define PLATFORMS_H

#include <raylib.h>

/**
 * @brief Initialize the platforms array with random values, starting at `start`
 * and decrementing by `gap` for each iteration on the y axis.
 * @param platforms Array containing platform positions.
 * @param platformSize Size of each platform.
 * @param start Initial position for the first platform on the y axis.
 * @param gap Gap between platforms on the y axis.
 */
void platformsInit(Vector2 platforms[5], Vector2 platformSize, float *start, float gap);

/**
 * @brief Draws all the platforms in the array
 * @param platforms Array containing platform positions.
 * @param platformSize  Size of each platform.
 */
void platformsDraw(Vector2 platforms[5], Vector2 platformSize);

/**
 * @brief Updates the values of a single platform.
 * @param platform Pointer to a platform in the array.
 * @param platformSize Size of the platform.
 * @param start Initial position for the platform on the y axis.
 * @param gap Gap between platforms on the y axis.
 */
void platformUpdate(Vector2 *platform, Vector2 platformSize, float *start, float gap);

/**
 * @brief Checks for collisions between the player's hit-box, each platform,
 * and the kill zone.
 * @param platforms Array containing platform positions.
 * @param platformSize Size of each platform.
 * @param playerPointColl Rectangle representing the player's hit-box.
 * @param killZone Rectangle representing the kill zone.
 * @param velocity Pointer to the player's velocity vector.
 * @param start Initial position for the platforms on the y axis.
 * @param gap Gap between platforms on the y axis.
 */
void platformsCheckCollision(Vector2 platforms[5], Vector2 platformSize, Rectangle playerPointColl, Rectangle killZone, Vector2 *velocity, float *start, float gap);

/**
 * @brief Draws the platforms positions on the screen.
 * @param platforms Array containing platform positions.
 */
void platformsDrawPos(Vector2 platforms[5]);

#endif //PLATFORMS_H
