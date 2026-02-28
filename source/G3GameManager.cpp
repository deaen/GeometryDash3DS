#include "G3GameManager.h"

G3GameManager::G3GameManager()
{
    C2D_SetTintMode(C2D_TintMode::C2D_TintMult);
    /* Load textures */
    
    G3Sheets::objects = C2D_SpriteSheetLoad("romfs:/gfx/objects.t3x"); 
    if (!G3Sheets::objects) svcBreak(USERBREAK_PANIC);
    C3D_TexSetFilter(C2D_SpriteSheetGetImage(G3Sheets::objects, 0).tex, GPU_TEXTURE_FILTER_PARAM::GPU_LINEAR, GPU_TEXTURE_FILTER_PARAM::GPU_LINEAR);
    
    // /* Load textures */
    
    // // Set first scene
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
    hidScanInput();
    
    //temp
    if (hidKeysDown() & KEY_START) aptExit();
    
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
