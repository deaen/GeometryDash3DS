#pragma once
#include <G3Node.h>
#include <citro2d.h>

// G3Node with the ability to choose which screen to draw on basically
class G3Scene: public G3Node{
    public:
    static std::shared_ptr<G3Scene> create();
    void draw() override; // will just draw top, please use drawTop() instead!
    // void update() override;
    virtual void drawTop();
    virtual void drawBottom();
};
