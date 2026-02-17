#pragma once
#include <citro2d.h>
#include "G3Node.h"

class G3Sprite : public G3Node
{
public:
    G3Sprite();
    static std::shared_ptr<G3Sprite> create();
    void draw() override;
};
