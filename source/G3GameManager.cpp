#include "G3GameManager.h"

G3GameManager::G3GameManager()
{
    // /* Load textures */
    // m_objectSheet = C2D_SpriteSheetLoad("romfs:/gfx/objects.t3x");
    // //...
    // if (!m_objectSheet) svcBreak(USERBREAK_PANIC);

    // Set first scene
    G3GameManager::setcurrentScene(G3LevelScene::create());
}

void G3GameManager::setcurrentScene(std::shared_ptr<G3Scene> scene)
{
    if (scene)
    {
        if (m_currentScene)
            m_currentScene->clearChildren();

        m_currentScene = scene;
    }
}

void G3GameManager::updateScene()
{
    if (m_currentScene)
    {
        m_currentScene->update();
    }
}

void G3GameManager::drawSceneAtTop()
{
    if (m_currentScene)
    {
        m_currentScene->drawTop();
    }
}

void G3GameManager::drawSceneAtBottom()
{
    if (m_currentScene)
    {
        m_currentScene->drawBottom();
    }
}
