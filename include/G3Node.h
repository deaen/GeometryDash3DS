#pragma once
#include <memory>
#include <vector>
#include <string>
#include <string_view>
#include <cassert>
#include <algorithm>
#include "G3Globals.h"

class G3Node
{
public:
    static std::shared_ptr<G3Node> create();
    virtual ~G3Node();

    virtual void update();
    virtual void draw();

    void setTag(std::string_view tag);     // Set tag to be able to identify this node u really wanna do this!!
    void setDrawOn(G3Consts::Screen screen); // Set which screen to draw on. this is only considered when node is directly under the root scene, otherwise it will just follow the parent's screen. defaults to TOP

    std::string_view getTag();
    G3Consts::Screen getDrawOn();

    void addChild(std::shared_ptr<G3Node> ptr);
    void clearChildren();

    virtual void setPosX(float posX);
    virtual void setPosY(float posY);
    void setPosZ(float posZ);

    void setScaleX(float scaleX);
    void setScaleY(float scaleY);

    void setRotDegree(float rotDegree);

    void setWidth(float width);
    void setHeight(float height);

protected:
    std::vector<std::shared_ptr<G3Node>> m_children{};
    std::shared_ptr<G3Node> m_parent{};

    /* Positing stuff */
    float m_posX{};
    float m_posY{};
    float m_posZ{};

    float m_scaleX{};
    float m_scaleY{};

    float m_rotDegree{};

    float m_width{};
    float m_height{};

    std::string_view m_tag{};
    G3Consts::Screen m_drawOn{G3Consts::Screen::top};
};
