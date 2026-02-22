#include "G3Node.h"

std::shared_ptr<G3Node> G3Node::create()
{
    return std::make_shared<G3Node>();
}

G3Node::~G3Node()
{
    clearChildren();
}

void G3Node::update()
{
    if(m_translationVelocityX) m_posX += m_translationVelocityX + getParent()->m_translationVelocityX;
    if(m_translationVelocityY) m_posY += m_translationVelocityY + getParent()->m_translationVelocityY;
    
    // update all the children
    for (const auto &child : m_children)
    {
        child->update();
    }
};

void G3Node::draw()
{
    // draw all the children
    for (const auto &child : m_children)
    {
        child->draw();
    }
}

void G3Node::setTag(std::string_view tag)
{
    m_tag = tag;
}

void G3Node::setDrawOn(G3Consts::Screen screen)
{
    m_drawOn = screen;
}

std::string_view G3Node::getTag()
{
    return m_tag;
}

G3Consts::Screen G3Node::getDrawOn()
{
    return m_drawOn;
}

void G3Node::addChild(const std::shared_ptr<G3Node> &child)
{
    child->m_parent = this;
    m_children.push_back(child);
}

void G3Node::clearChildren()
{
    m_children.clear();
}

G3Node *G3Node::getParent()
{
    return m_parent;
}

float G3Node::getPosX()
{
    return m_posX;
}

float G3Node::getPosY()
{
    return m_posY;
}

float G3Node::getTranslationVelocityX()
{
    return m_translationVelocityX;
}

float G3Node::getTranslationVelocityY()
{
    return m_translationVelocityY;
}

int G3Node::getZOrder()
{
    return m_zOrder;
}

float G3Node::getWidth()
{
    return m_width;
}

float G3Node::getHeight()
{
    return m_height;
}

void G3Node::setPosX(float posX)
{
    this->m_posX = posX;
}

void G3Node::setPosY(float posY)
{
    this->m_posY = posY;
}

// void G3Node::setScaleX(float scaleX)
// {
//     this->m_scaleX = scaleX;
//     for (const auto& child : m_children)
//     {
//         child->m_scaleX = child->m_scaleX + this->m_scaleX;
//     }

// }

// void G3Node::setScaleY(float scaleX)
// {
//     this->m_scaleX = scaleX;
//     for (const auto& child : m_children)
//     {
//         child->m_scaleX = child->m_scaleX + this->m_scaleX;
//     }

// }

// void G3Node::setRotDegree(float rotDegree)
// {
//     this->m_rotDegree = rotDegree;
//     for (const auto& child : m_children)
//     {
//         child->m_rotDegree = child->m_rotDegree + this->m_rotDegree;
//     }

// }

// void G3Node::setWidth(float width)
// {
//     this->m_width = width;
//     for (const auto& child : m_children)
//     {
//         child->m_width = child->m_width + this->m_width;
//     }

// }

// void G3Node::setHeight(float height)
// {
//     this->m_height = height;
//     for (const auto& child : m_children)
//     {
//         child->m_height = child->m_height + this->m_height;
//     }

// }
