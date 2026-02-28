#pragma once
#include <filesystem>
#include <fstream>
#include <ranges>
#include <map>
#include "G3Scene.h"
#include "G3LevelObject.h"
#include "G3LevelObjectContainer.h"

class G3LevelScene : public G3Scene
{
public:
    G3LevelScene();
    static std::shared_ptr<G3LevelScene> create();
    int loadLevel(int id = 0); // id: level id, if not valid or errors out it jus wont load anything
    
    void drawTop() override;
    void drawBottom() override;

private:
    void setupStartObject(std::string_view startObjectString);
    std::map<char, float> getColor(std::string_view colorString);

    std::shared_ptr<G3LevelObjectContainer> m_objectContainer{G3LevelObjectContainer::create()};
    std::shared_ptr<G3Sprite> m_background{G3Sprite::create()}; // temp bg
};
