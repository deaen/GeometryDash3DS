#pragma once
#include <G3Scene.h>
#include <memory>
class G3SceneManager
{
private:
    G3SceneManager() {};

    std::unique_ptr<G3Scene> m_currentScene{};

public:
    G3SceneManager(G3SceneManager const &) = delete;
    void operator=(G3SceneManager const &) = delete;
    static G3SceneManager &getInstance()
    {
        static G3SceneManager instance;
        return instance;
    }

    void setcurrentScene(G3Scene *Scene);
    void updateScene();
    void drawSceneAtTop();
    void drawSceneAtBottom();
};
