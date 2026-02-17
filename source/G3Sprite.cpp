#include "G3Sprite.h"

G3Sprite::G3Sprite()
{
    //TEMP
    m_width = 30.0f;
    m_height = 30.0f;

}

std::shared_ptr<G3Sprite> G3Sprite::create()
{
    return std::make_shared<G3Sprite>();
}

void G3Sprite::draw()
{
    C2D_DrawRectSolid(m_posX, m_posY, 0, m_width, m_height, C2D_Color32(0x00, 0x66, 0xFF, 0xFF));
}
