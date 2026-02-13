#pragma once
#include <G3Scene.h>

class G3LevelScene : public G3Scene
{
    public:
    static std::shared_ptr<G3LevelScene> create();
    void drawTop() override;
};
