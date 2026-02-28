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

    void setTag(std::string_view tag);       // Set tag to be able to identify this node u really wanna do this!!
    void setDrawOn(G3Consts::Screen screen); // Set which screen to draw on. this is only considered when node is directly under the root scene, otherwise it will just follow the parent's screen. defaults to TOP

    std::string_view getTag();
    G3Consts::Screen getDrawOn();

    virtual void addChild(const std::shared_ptr<G3Node>& child) final;
    void clearChildren();

    virtual G3Node* getParent() final;

    virtual float getPosX() final;
    virtual float getPosY() final;

    virtual int getZOrder() final;

    virtual float getWidth() final;
    virtual float getHeight() final;

    virtual float getRotDegree() final;

    virtual float getScaleX() final;
    virtual float getScaleY() final;

    void setParent(G3Node *parent);

    virtual void setPosX(float posX);
    virtual void setPosY(float posY);

    virtual void setScaleX(float scaleX);
    virtual void setScaleY(float scaleY);

    void setRotDegree(float rotDegree);

    void setWidth(float width);
    void setHeight(float height);

    void flipH();
    void flipV();

protected:
    std::vector<std::shared_ptr<G3Node>> m_children{};
    G3Node* m_parent{nullptr};

    /* Positing stuff */
    float m_posX{}; // its offset of its parentntnt n stuff. i always forget this
    float m_posY{}; // its offset of its parentntnt n stuff. i always forget this

    float m_scaleX{1.0f};
    float m_scaleY{1.0f};

    float m_rotDegree{};

    float m_width{};
    float m_height{};
    
    int m_zOrder{};
    std::string_view m_tag{};

    G3Consts::Screen m_drawOn{G3Consts::Screen::top};
};
