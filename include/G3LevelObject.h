#pragma once
#include <ranges>
#include "G3Sprite.h"
#include "G3Random.h"

class G3LevelObject : public G3Sprite
{
public:
    G3LevelObject();
    static std::shared_ptr<G3LevelObject> create();
    void setupObject(std::string_view objectString);

    void update() override;
    void draw() override;

    int getZLayer(); // b5 = -5, b4= -4... etc, t1=1 and like that

    void setWorldPosX(float worldPosX);
    void setWorldPosY(float worldPosY);

    void setWorldScaleX(float worldScaleX);
    void setWorldScaleY(float worldScaleY);

private:
    float m_worldPosX{}; // actual real position that hitboxes and physics use
    float m_worldPosY{}; // actual real position that hitboxes and physics use

    float m_worldScaleX{1.0f}; // the inheritied scale is a visual one that changes n shit
    float m_worldScaleY{1.0f}; // the inheritied scale is a visual one that changes n shit

    int m_objectID{};

    int m_zLayer{};
    bool m_shouldDraw{true};

    int getSprites(int objectID);
};
