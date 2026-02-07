#include <G3Scene.h>
#include <citro2d.h>

G3Scene *G3Scene::create(u32 c)
{
    G3Scene *ret = new G3Scene(c);
    if (!ret && !ret->init())
    {
        delete ret;
        ret = nullptr;
    }

    return ret;
}

int G3Scene::init()
{

    return 0;
}

void G3Scene::update() {};

void G3Scene::drawTop()
{
    C2D_DrawCircleSolid(200.0f, 120.0f, 0, 50.0f, m_temp_color);
}

void G3Scene::drawBottom() {}
