#pragma once
#include <citro2d.h>

namespace G3Consts
{
    /* screen dimensions */
    inline constexpr int topScreenWidth = 400;
    inline constexpr int screenHeight = 240;
    inline constexpr int bottomScreenWidth = 320;
    enum class Screen
    {
        top,
        bottom
    };
}

namespace G3Sheets
{
    inline C2D_SpriteSheet objects;
}

namespace G3PlayerData{
    // player colors 1 and 2
    inline float c1R{}, c1G{}, c1B{};
    inline float c2R{}, c2G{}, c2B{};
}
// this is a bad idea
namespace G3Camera
{
    inline float velocitySpeed = 10.0f;
    inline float cameraScale{0.8};
    inline float cameraVelocityX{};
    inline float cameraVelocityY{};
}