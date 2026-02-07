#include <G3SceneManager.h>

void G3SceneManager::setcurrentScene(G3Scene* scene){
    if(m_currentScene.get() == scene) return;
    
    m_currentScene.reset(scene);
}


void G3SceneManager::updateScene(){
    if(m_currentScene){
        m_currentScene->update();
    }
}

void G3SceneManager::drawSceneAtTop(){
    if(m_currentScene){
        m_currentScene->drawTop();
    }
}

void G3SceneManager::drawSceneAtBottom(){
    if(m_currentScene){
        m_currentScene->drawBottom();
    }
}
