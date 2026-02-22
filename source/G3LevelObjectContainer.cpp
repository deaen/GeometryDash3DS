#include "G3LevelObjectContainer.h"

G3LevelObjectContainer::G3LevelObjectContainer()
{
    setTag("G3LevelObjectContainer");
}

void G3LevelObjectContainer::sortChildren()
{
    // sort into z layers
    for (const auto &obj : m_children)
    {
        auto child = std::static_pointer_cast<G3LevelObject>(obj);

        switch (child->getZLayer())
        {
        case -5:
            m_b5.push_back(child);
            break;
        case -4:
            m_b4.push_back(child);
            break;
        case -3:
            m_b3.push_back(child);
            break;
        case -2:
            m_b2.push_back(child);
            break;
        case -1:
            m_b1.push_back(child);
            break;
        case 1:
            m_t1.push_back(child);
            break;
        case 2:
            m_t2.push_back(child);
            break;
        case 3:
            m_t3.push_back(child);
            break;
        case 4:
            m_t4.push_back(child);
            break;
        default:
            m_playerLayer.push_back(child);
            break;
        }
    }

    // sort z order
    sortLayer(m_b5);
    sortLayer(m_b4);
    sortLayer(m_b3);
    sortLayer(m_b2);
    sortLayer(m_b1);
    sortLayer(m_playerLayer);
    sortLayer(m_t1);
    sortLayer(m_t2);
    sortLayer(m_t3);
    sortLayer(m_t4);
}

void G3LevelObjectContainer::update()
{
    G3Node::update();

    u32 kHeld = hidKeysHeld();
    u32 kLifted = hidKeysUp();
    if (kHeld & KEY_LEFT)
        m_translationVelocityX = 10.0f;
    if (kHeld & KEY_RIGHT)
        m_translationVelocityX = -10.0f;
    if (kHeld & KEY_UP)
        m_translationVelocityY = 10.0f;
    if (kHeld & KEY_DOWN)
        m_translationVelocityY = -10.0f;
    if (kLifted & (KEY_LEFT | KEY_RIGHT)){
        m_translationVelocityX = 0.0f;
    }
    if (kLifted & (KEY_UP | KEY_DOWN)){
        m_translationVelocityY = 0.0f;
    }
}

bool G3LevelObjectContainer::overlaps(G3Node *child)
{
    return (topLeftPosX() < (child->getPosX() + child->getWidth()) || (child->getPosX() - child->getWidth()) > bottomRightPosX() || topLeftPosY() < (child->getPosY() + child->getHeight()) || (child->getPosY() - child->getHeight()) > bottomRightPosY());
}

void G3LevelObjectContainer::draw()
{
    drawLayer(m_b5);
    drawLayer(m_b4);
    drawLayer(m_b3);
    drawLayer(m_b2);
    drawLayer(m_b1);
    drawLayer(m_playerLayer);
}

void G3LevelObjectContainer::drawTopLayers()
{
    drawLayer(m_t1);
    drawLayer(m_t2);
    drawLayer(m_t3);
    drawLayer(m_t4);
}

float G3LevelObjectContainer::topLeftPosX()
{
    return m_posX;
}

float G3LevelObjectContainer::bottomLeftPosX()
{
    return m_posX;
}

float G3LevelObjectContainer::topRightPosX()
{
    return m_posX + ((m_drawOn == G3Consts::Screen::top) ? G3Consts::topScreenWidth : G3Consts::bottomScreenWidth);
}

float G3LevelObjectContainer::bottomRightPosX()
{
    return m_posX + ((m_drawOn == G3Consts::Screen::top) ? G3Consts::topScreenWidth : G3Consts::bottomScreenWidth);
}

float G3LevelObjectContainer::centerPosX()
{
    return m_posX + (((m_drawOn == G3Consts::Screen::top) ? G3Consts::topScreenWidth : G3Consts::bottomScreenWidth) / 2);
}

float G3LevelObjectContainer::topLeftPosY()
{
    return m_posY;
}

float G3LevelObjectContainer::topRightPosY()
{
    return m_posY;
}

float G3LevelObjectContainer::bottomLeftPosY()
{
    return m_posY + G3Consts::screenHeight;
}

float G3LevelObjectContainer::bottomRightPosY()
{
    return m_posY + G3Consts::screenHeight;
}

float G3LevelObjectContainer::centerPosY()
{
    return m_posY + (G3Consts::screenHeight / 2);
}