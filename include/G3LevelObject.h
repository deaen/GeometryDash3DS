#pragma once
#include <ranges>
#include "G3Sprite.h"

class G3LevelObject : public G3Sprite
{
public:
    static std::shared_ptr<G3LevelObject> create();
    void setupObject(std::string_view objectString);
private:
    int m_objectID{};
    
    float m_camPosX{};
    float m_camPosY{};
};
