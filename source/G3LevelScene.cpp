#include "G3LevelScene.h"

std::shared_ptr<G3LevelScene> G3LevelScene::create()
{
    return std::make_shared<G3LevelScene>();
}

void G3LevelScene::drawTop()
{
    C2D_DrawCircleSolid(400 - 25, 240 - 25, 0, 25, C2D_Color32(0xED, 0x1C, 0x24, 0xFF));
}
