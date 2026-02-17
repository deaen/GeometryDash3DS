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
    // update all the children
    for (auto child : m_children)
    {
        child->update();
    }
};

void G3Node::draw()
{
    // draw all the children
    for (auto child : m_children)
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

void G3Node::addChild(std::shared_ptr<G3Node> ptr)
{
    if ((this != ptr.get()) && (std::find(m_children.begin(), m_children.end(), ptr) == m_children.end()))
    {
        m_children.push_back(ptr);
        ptr->m_parent.reset(this);
    }
}

void G3Node::clearChildren()
{
    m_children.clear();
}

void G3Node::setPosX(float posX)
{
    this->m_posX = posX;
    for (auto child : m_children)
    {
        child->m_posX = child->m_posX + this->m_posX;
    }

}

void G3Node::setPosY(float posY)
{
    this->m_posY = posY;
    for (auto child : m_children)
    {
        child->m_posY = child->m_posY + this->m_posY;
    }

}

void G3Node::setPosZ(float posZ)
{
    this->m_posZ = posZ;
    for (auto child : m_children)
    {
        child->m_posZ = child->m_posZ + this->m_posZ;
    }

}

void G3Node::setScaleX(float scaleX)
{
    this->m_scaleX = scaleX;
    for (auto child : m_children)
    {
        child->m_scaleX = child->m_scaleX + this->m_scaleX;
    }

}

void G3Node::setScaleY(float scaleX)
{
    this->m_scaleX = scaleX;
    for (auto child : m_children)
    {
        child->m_scaleX = child->m_scaleX + this->m_scaleX;
    }

}

void G3Node::setRotDegree(float rotDegree)
{
    this->m_rotDegree = rotDegree;
    for (auto child : m_children)
    {
        child->m_rotDegree = child->m_rotDegree + this->m_rotDegree;
    }

}

void G3Node::setWidth(float width)
{
    this->m_width = width;
    for (auto child : m_children)
    {
        child->m_width = child->m_width + this->m_width;
    }

}

void G3Node::setHeight(float height)
{
    this->m_height = height;
    for (auto child : m_children)
    {
        child->m_height = child->m_height + this->m_height;
    }

}
