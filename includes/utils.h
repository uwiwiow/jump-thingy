#ifndef UTILS_H
#define UTILS_H

#include <raylib.h>

/**
 * @brief Vector2 constructor.
 * @param x x component of the Vector2.
 * @param y y component of the Vector2.
 * @return The Vector2 with the values
 */
static inline Vector2 vector2(float x, float y) {
    Vector2 res = {x, y};
    return res;
}

/**
 * @brief Rectangle constructor.
 * @param x x component of the Rectangle.
 * @param y y component of the Rectangle.
 * @param width width component of the Rectangle.
 * @param height height component of the Rectangle.
 * @return The Rectangle with the values
 */
static inline Rectangle rectangle(float x, float y, float width, float height) {
    Rectangle res = {x, y, width, height};
    return res;
}

#endif //UTILS_H

