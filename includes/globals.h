#ifndef GLOBALS_H
#define GLOBALS_H

#define WIDTH 600 ///< The width of the game window in pixels.
#define HEIGHT 900 ///< The height of the game window in pixels.

/**
 * @brief Enables or disables Debug Mode.
 *
 * When set to 1, Debug Mode is enabled, which:
 * - Displays the positions of all platforms on the screen.
 * - Allows resetting the player's position with the C key without restarting the game.
 *
 * Set to 0 to disable Debug Mode.
 */
#define DEBUG 0

static float gravity = -981.0f; ///< The gravitational force applied to the player.
static float jumpSpd = -1000.0f; ///< The vertical speed of the player when jumping.
static float moveSpd = 300.0f; ///< The horizontal movement speed of the player.


#endif //GLOBALS_H
