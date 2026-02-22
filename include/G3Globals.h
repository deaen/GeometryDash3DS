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

namespace G3Sheets{
    inline C2D_SpriteSheet objects;
}
