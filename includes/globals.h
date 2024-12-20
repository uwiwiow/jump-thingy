#ifndef GLOBALS_H
#define GLOBALS_H

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

namespace Globals {
    constexpr int WIDTH = 600; ///< The width of the game window in pixels.
    constexpr int HEIGHT = 900; ///< The height of the game window in pixels.
    constexpr float gravity = -981.0f; ///< The gravitational force applied to the player.
    constexpr float jumpSpd = -1000.0f; ///< The vertical speed of the player when jumping.
    constexpr float moveSpd = 300.0f; ///< The horizontal movement speed of the player.


}
#endif //GLOBALS_H
