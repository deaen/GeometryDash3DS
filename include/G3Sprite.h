#pragma once
#include <citro2d.h>
#include "G3Node.h"
#include "objects.h"

class G3Sprite : public G3Node
{
public:
    G3Sprite();
    static std::shared_ptr<G3Sprite> create();
    void setSprite(C2D_SpriteSheet spritesheet, int id);

    void draw() override;

    void update() override;

    void setPosX(float posX) override;
    void setPosY(float posY) override;
protected:
    C2D_Sprite m_spr{};
    bool m_flipH{false};
    bool m_flipV{false};
};
