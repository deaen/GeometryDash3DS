#pragma once
#include <memory>
#include <vector>
#include <string_view>
#include <cassert>
#include <algorithm>

class G3Node
{
public:
    enum Screen
    {
        top,
        bottom
    };

    static std::shared_ptr<G3Node> create();
    virtual ~G3Node();

    virtual void update();
    virtual void draw();

    virtual G3Node &setTag(std::string_view tag) final;     // Set tag to be able to identify this node u really wanna do this!!
    virtual G3Node &setDrawOn(G3Node::Screen screen) final; // Set which screen to draw on. this is only considered when node is directly under the root scene, otherwise it will just follow the parent's screen. defaults to TOP

    virtual std::string_view getTag() final;
    virtual Screen getDrawOn() final;

    virtual void addChild(std::shared_ptr<G3Node> ptr) final;
    virtual void clearChildren() final;

protected:
    std::vector<std::shared_ptr<G3Node>> m_children{};
    std::shared_ptr<G3Node> parent{};

private:
    
    std::string_view m_tag{};
    Screen m_drawOn{Screen::top};

    /* Positing stuff */
    float posX{};
    float posY{};
    float posZ{};

    float scaleX{};
    float scaleY{};

    float RotDegree{};
};
