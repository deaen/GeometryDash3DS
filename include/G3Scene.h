#pragma once
#include <format>
#include <citro2d.h>
#include "G3Node.h"

// G3Node with the ability to choose which screen to draw on basically
class G3Scene : public G3Node
{
public:
    static std::shared_ptr<G3Scene> create();

    void draw() override; // will just draw top, please use drawTop() instead!
    void update() override;
    virtual void drawTop();
    virtual void drawBottom();

    void drawText(std::string_view str); // make sure to always call G3Scene::update() first bro;
};
