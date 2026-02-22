#include "G3Scene.h"



std::shared_ptr<G3Scene> G3Scene::create()
{
    return std::make_shared<G3Scene>();
}

void G3Scene::draw()
{
    drawTop();
}

void G3Scene::drawTop()
{
    for (const auto& child : m_children)
    {
        if (child->getDrawOn() == G3Consts::Screen::top)
            child->draw();
    }
}

void G3Scene::drawBottom()
{
    for (const auto& child : m_children)
    {
        if (child->getDrawOn() == G3Consts::Screen::bottom)
            child->draw();
    }

}

