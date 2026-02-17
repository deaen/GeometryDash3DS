#pragma once
#include <filesystem>
#include <fstream>
#include <ranges>
#include "G3Scene.h"
#include "G3LevelObject.h"

class G3LevelScene : public G3Scene
{
public:
    G3LevelScene();
    static std::shared_ptr<G3LevelScene> create();
    int loadLevel(int id = 0); // id: level id, if not valid or errors out it jus wont load anything
};
