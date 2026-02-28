#include "G3LevelScene.h"

G3LevelScene::G3LevelScene()
{
    m_background->setSprite(G3Sheets::objects, objects_game_bg_01_001_idx);
    m_background->setCenter(G3Sprite::bottomLeft);
    m_background->setPosY(G3Consts::screenHeight);
    this->addChild(m_background);

    this->addChild(m_objectContainer);
    loadLevel(13);
    // G3AudioManager::playAudio();
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
            setupStartObject(str);
            ++objectCount;
            continue;
        }

        auto gameObj = G3LevelObject::create();
        m_objectContainer->addChild(gameObj);
        gameObj->setupObject(str);

        ++objectCount;
    }

    m_objectContainer->sortChildren();
    return 0;
}

void G3LevelScene::drawTop()
{
    m_background->draw();
    m_objectContainer->draw(); // bottom layers
    // player or sum here
    m_objectContainer->drawTopLayers(); // top layers
}

void G3LevelScene::drawBottom()
{
    // MANUALLY DRAW BOTTOM UI HERE LATER
}

void G3LevelScene::setupStartObject(std::string_view startObjectString)
{
    constexpr std::string_view delim{","};
    std::string_view propKey{};
    int propCount{0};

    for (const auto prop : std::views::split(startObjectString, delim))
    {
        auto str = std::string_view(prop);
        if (!(propCount % 2))
        {
            propKey = str;
            ++propCount;
            continue;
        }

        //  || propKey == "kS30" || propKey == "kS31" || propKey == "kS32"
        if (propKey == "kS29")
        {
            auto bgColor = getColor(str);
            m_background->setColor(bgColor.at('r'), bgColor.at('g'), bgColor.at('b'));
        }

        ++propCount;
    }
}

std::map<char, float> G3LevelScene::getColor(std::string_view colorString)
{
    std::map<char, float> map{};
    constexpr std::string_view delim{"_"};
    int propKey{};
    int propCount{0};

    for (const auto prop : std::views::split(colorString, delim))
    {
        auto str = std::string_view(prop);
        if (!(propCount % 2))
        {
            propKey = std::atoi(str.data());
            ++propCount;
            continue;
        }

        switch (propKey)
        {
        case 1:
            map.insert_or_assign('r', (std::atof(str.data()) / 255.0f));
            break;
        case 2:
            map.insert_or_assign('g', (std::atof(str.data()) / 255.0f));
            break;
        case 3:
            map.insert_or_assign('b', (std::atof(str.data()) / 255.0f));
            break;
        }

        ++propCount;
    }

    return map;
}
