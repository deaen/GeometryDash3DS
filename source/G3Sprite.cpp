#include "G3Sprite.h"

G3Sprite::G3Sprite()
{
}

std::shared_ptr<G3Sprite> G3Sprite::create()
{
    return std::make_shared<G3Sprite>();
}

void G3Sprite::setSprite(C2D_SpriteSheet spritesheet, int id)
{
    C2D_SpriteFromSheet(&m_spr, spritesheet, id);
    
    setCenter(center::spriteCenter);

    C2D_SpriteSetPos(&m_spr, m_posX, m_posY);
    C2D_SpriteSetScale(&m_spr, m_scaleX, m_scaleY);
    C2D_SpriteSetRotationDegrees(&m_spr, m_rotDegree);

    // get width and height
    C2D_Image img = C2D_SpriteSheetGetImage(spritesheet, id);
    setWidth(img.subtex->width);
    setHeight(img.subtex->height);

    //filterz n shit
    setColor();
}

void G3Sprite::draw()
{
    G3Node::draw();

    C2D_DrawSpriteTinted(&m_spr, &m_sprTint);
}

void G3Sprite::setPosX(float posX)
{
    G3Node::setPosX(posX);

    C2D_SpriteSetPos(&m_spr, m_posX, m_posY);
}

void G3Sprite::setPosY(float posY)
{
    G3Node::setPosY(posY);

    C2D_SpriteSetPos(&m_spr, m_posX, m_posY);
}

void G3Sprite::setScaleX(float scaleX)
{
    G3Node::setScaleX(scaleX);

    C2D_SpriteSetScale(&m_spr, m_scaleX, m_scaleY);
}

void G3Sprite::setScaleY(float scaleY)
{
    G3Node::setScaleY(scaleY);

    C2D_SpriteSetScale(&m_spr, m_scaleX, m_scaleY);
}

void G3Sprite::setColor(float R, float G, float B, float A)
{
    C2D_PlainImageTint(&m_sprTint, C2D_Color32f(R, G, B, A), 1.0f);
}

void G3Sprite::setCenter(center center)
{
    if(center == center::topLeft)
    {
        C2D_SpriteSetCenter(&m_spr, 0.0f, 0.0f);
    }
    else if(center == center::topRight)
    {
        C2D_SpriteSetCenter(&m_spr, 1.0f, 0.0f);
    }
    else if(center == center::bottomLeft)
    {
        C2D_SpriteSetCenter(&m_spr, 0.0f, 1.0f);
    }
    else if(center == center::bottomRight)
    {
        C2D_SpriteSetCenter(&m_spr, 1.0f, 1.0f);
    }
    else if(center == center::spriteCenter)
    {
        C2D_SpriteSetCenter(&m_spr, 0.5f, 0.5f);
    }
}
