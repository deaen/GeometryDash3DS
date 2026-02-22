#include "G3LevelScene.h"

G3LevelScene::G3LevelScene()
{
    m_objectContainer = std::make_shared<G3LevelObjectContainer>();
    this->addChild(m_objectContainer);

    // auto gameObj = G3LevelObject::create();
    // gameObj->setupObject("");
    // m_objectContainer->addChild(gameObj);

    loadLevel(14);
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
            // start object shit here
            ++objectCount;
            continue;
        }

        auto gameObj = G3LevelObject::create();
        gameObj->setupObject(str);
        m_objectContainer->addChild(gameObj);

        ++objectCount;
    }


    m_objectContainer->sortChildren();
    return 0;
}

void G3LevelScene::drawTop()
{
    m_objectContainer->draw();
    // player or sum here
    m_objectContainer->drawTopLayers();
}

void G3LevelScene::drawBottom()
{
    // MANUALLY DRAW BOTTOM UI HERE LATER
}
