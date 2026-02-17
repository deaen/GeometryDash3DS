#pragma once
#include "G3Node.h"
#include "G3LevelObject.h"
#include "G3Globals.h"

// a node that ONLY contains levelobject(s), and acts as a camera, children of THIS cool little node only render when they're on screen!!!!!!
class G3LevelObjectContainer : public G3Node
{
public:
    G3LevelObjectContainer();
    /* X position getters*/

    float topLeftPosX();
    float bottomLeftPosX();
    
    float topRightPosX(G3Consts::Screen screen);
    float bottomRightPosX(G3Consts::Screen screen);

    float centerPosX(G3Consts::Screen screen);

    /* Y position getters */

    float topLeftPosY();
    float bottomLeftPosY();

    float topRightPosY();
    float bottomRightPosY();

    float centerPosY();

    /* Position setters */

    void setPos(float posX, float posY);
    void setPosX(float posX) override;
    void setPosY(float posY) override;
    
    void translatePos(float posX, float posY);
    void translatePosX(float posX);
    void translatePosY(float posY);

private:
    std::vector<std::shared_ptr<G3LevelObject>> m_children{};
    
};
