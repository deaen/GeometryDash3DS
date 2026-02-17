#pragma once
#include <citro2d.h>
#include "G3Globals.h"
#include "G3Scene.h"

/*Scenes*/
#include "G3LevelScene.h"

class G3GameManager
{
public:
    G3GameManager(G3GameManager const &) = delete;
    void operator=(G3GameManager const &) = delete;
    static G3GameManager *getInstance()
    {
        static G3GameManager instance{};
        return &instance;
    }

    /* Scene Stuff */
    void updateScene();
    void drawSceneAtTop();
    void drawSceneAtBottom();

    void setcurrentScene(std::shared_ptr<G3Scene> scene);

    /* Texture Stuff */
    C2D_SpriteSheet m_objectSheet{};
    
private:
    G3GameManager();
    std::shared_ptr<G3Scene> m_currentScene{};
};
