#include "G3LevelObject.h"

std::shared_ptr<G3LevelObject> G3LevelObject::create()
{
    return std::make_shared<G3LevelObject>();
}

void G3LevelObject::setupObject(std::string_view objectString)
{
    constexpr std::string_view delim{","};
    int propKey{};
    int propCount{0};

    for (const auto prop : std::views::split(objectString, delim))
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
            m_objectID = std::atoi(str.data());
            break;
        case 2:
            m_posX = -(std::atof(str.data()));
            break;
        case 3:
            m_posY = std::atof(str.data());
            break;
        }
        ++propCount;
    }

    m_camPosX = m_posX;
    m_camPosY = m_posY;
}
