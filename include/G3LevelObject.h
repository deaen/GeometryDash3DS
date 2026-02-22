#pragma once
#include <ranges>
#include "G3Sprite.h"
#include "G3Random.h"

class G3LevelObject : public G3Sprite
{
public:
    static std::shared_ptr<G3LevelObject> create();
    void setupObject(std::string_view objectString);
    void draw() override;

    int getZLayer(); // b5 = -5, b4= -4... etc, t1=1 and like that
private:
    int m_objectID{};
    
    int m_zLayer{}; 
    bool m_shouldDraw{true};

    int getSpriteID(int objectID);
};
