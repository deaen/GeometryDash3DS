#pragma once
#include <citro2d.h>
#include "G3Node.h"
#include "objects.h"

class G3Sprite : public G3Node
{
public:
    G3Sprite();
    static std::shared_ptr<G3Sprite> create();
    void setSprite(C2D_SpriteSheet spritesheet, int id = objects_square_01_001_idx);

    void draw() override;

    void setPosX(float posX) override;
    void setPosY(float posY) override;

    void setScaleX(float scaleX) override;
    void setScaleY(float scaleY) override;

    void setColor(float R = 1.0f, float G = 1.0f, float B = 1.0f, float A = 1.0f);

    enum center{
      topLeft,
      topRight,
      bottomLeft,
      bottomRight,
      spriteCenter  
    };

    void setCenter(center center);
protected:
    C2D_Sprite m_spr{};
    C2D_ImageTint m_sprTint{};
};
