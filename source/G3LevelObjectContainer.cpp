#include "G3LevelObjectContainer.h"

G3LevelObjectContainer::G3LevelObjectContainer()
{
    m_posX = 0.0f;
    m_posY = 0.0f;
}

float G3LevelObjectContainer::topLeftPosX()
{
    return m_camPosX;
}

float G3LevelObjectContainer::bottomLeftPosX()
{
    return m_camPosX;
}

float G3LevelObjectContainer::topRightPosX(G3Consts::Screen screen = G3Consts::Screen::top)
{
    return m_camPosX - ((screen == G3Consts::Screen::top) ? G3Consts::topScreenWidth : G3Consts::bottomScreenWidth);
}

float G3LevelObjectContainer::bottomRightPosX(G3Consts::Screen screen = G3Consts::Screen::top)
{
    return m_camPosX - ((screen == G3Consts::Screen::top) ? G3Consts::topScreenWidth : G3Consts::bottomScreenWidth);
}

float G3LevelObjectContainer::centerPosX(G3Consts::Screen screen = G3Consts::Screen::top)
{
    // whew
    return m_camPosX - (((screen == G3Consts::Screen::top) ? G3Consts::topScreenWidth : G3Consts::bottomScreenWidth) / 2);
}

float G3LevelObjectContainer::topLeftPosY()
{
    return m_camPosY;
}

float G3LevelObjectContainer::topRightPosY()
{
    return m_camPosY;
}

float G3LevelObjectContainer::bottomLeftPosY()
{
    return m_camPosY - G3Consts::screenHeight;
}

float G3LevelObjectContainer::bottomRightPosY()
{
    return m_camPosY - G3Consts::screenHeight;
}
float G3LevelObjectContainer::centerPosY()
{
    return m_camPosY - (G3Consts::screenHeight / 2);
}

void G3LevelObjectContainer::setPos(float posX, float posY)
{
}

void G3LevelObjectContainer::setPosX(float posX)
{
}

void G3LevelObjectContainer::setPosY(float posY)
{
}

// void G3LevelObjectContainer::translatePosX(float posX)
// {
//     m_camPosX += posX;
//     C2D_ViewTranslate(posX, 0);
// }
// void G3LevelObjectContainer::translatePosY(float posY)
// {
//     m_camPosY += posY;
//     C2D_ViewTranslate(0, posY);
// };
