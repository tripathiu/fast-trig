/* This work is licensed under the Creative Commons CC BY-SA 3.0 license
 * authored by milianw and edited by Peter O. at Stack Overflow forum.
 *
 * https://stackoverflow.com/a/28050328
 *
 * Modified by Utkarsh Tripathi to add static constexpr specifiers, change the
 * return type to float and add helper functions.
 *
 * [CC BY-SA 3.0](https://creativecommons.org/licenses/by-sa/3.0/)
 */

#pragma once

#include <cstdint>
#include <cmath>

#ifndef M_PI
#define M_PI 3.1415
#endif

// template <typename T = uint16_t>
struct Position
{
    uint16_t x, y;
};

struct Trig
{
    static constexpr auto Pi = M_PI;

    static constexpr float cos(float x) noexcept
    {
        constexpr auto tp = 1. / (2. * Pi);
        x *= tp;
        x -= .25 + std::floor(x + .25);
        x *= 16. * (std::abs(x) - .5);
        return x + .225 * x * (std::abs(x) - 1.);
    }

    static constexpr float sin(float x) noexcept { return cos(Pi / 2. - x); }

    static constexpr auto polar(float theta, uint16_t rho, Position center = {})
    {
        return Position({center.x + rho * cos(theta), center.y + rho * sin(theta)});
    }
};