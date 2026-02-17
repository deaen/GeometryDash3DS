#include "G3LevelScene.h"

G3LevelScene::G3LevelScene()
{
    this->addChild(G3LevelObject::create());
    //loadLevel(1);
}

std::shared_ptr<G3LevelScene> G3LevelScene::create()
{
    return std::make_shared<G3LevelScene>();
}

int G3LevelScene::loadLevel(int id)
{
    std::ifstream inf{"romfs:/levels/" + std::to_string(id) + ".txt"};
    if (!inf)
        return 1;

    int objectCount{0};
    std::string levelString{};
    std::getline(inf, levelString);
    constexpr std::string_view delim{";"};

    for (const auto object : std::views::split(levelString, delim))
    {
        auto str = std::string_view(object);

        if (str.empty())
            continue;
        if (objectCount == 0)
        {
            // start obect shit here
            ++objectCount;
            continue;
        }

        auto gameObj = G3LevelObject::create();
        gameObj->setupObject(str);
        this->addChild(gameObj);

        ++objectCount;
    }

    return 0;
}
