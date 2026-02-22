#include "G3Sprite.h"

G3Sprite::G3Sprite()
{

}

std::shared_ptr<G3Sprite> G3Sprite::create()
{
    return std::make_shared<G3Sprite>();
}

void G3Sprite::setSprite(C2D_SpriteSheet spritesheet, int id = objects_square_01_001_idx)
{
    C2D_SpriteFromSheet(&m_spr, spritesheet, id);
    C2D_SpriteSetCenter(&m_spr, 0.5f, 0.5f);
    
    C2D_SpriteSetPos(&m_spr, m_posX, m_posY);

    C2D_SpriteSetRotationDegrees(&m_spr, m_rotDegree);

    // get width and height
    C2D_Image img = C2D_SpriteSheetGetImage(spritesheet, id);
    m_width = img.subtex->width;
    m_height = img.subtex->height;

    //Flip
    if(m_flipH) m_scaleX = -m_scaleX;
    if(m_flipV) m_scaleY = -m_scaleY;
    C2D_SpriteSetScale(&m_spr, m_scaleX, m_scaleY);
}

void G3Sprite::draw()
{
    C2D_DrawSprite(&m_spr);
    
    G3Node::draw();
}

void G3Sprite::update(){
    G3Node::update();

    C2D_SpriteMove(&m_spr, m_translationVelocityX + getParent()->getTranslationVelocityX(), m_translationVelocityY + getParent()->getTranslationVelocityY());
}
void G3Sprite::setPosX(float posX)
{
    G3Node::setPosX(posX);
    
    C2D_SpriteSetPos(&m_spr, posX, m_posY); 
}

void G3Sprite::setPosY(float posY)
{
    G3Node::setPosY(posY);

    C2D_SpriteSetPos(&m_spr, m_posX, posY);
}
