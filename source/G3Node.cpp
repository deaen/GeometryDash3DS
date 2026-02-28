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
    child->setParent(this);
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

float G3Node::getRotDegree()
{
    return m_rotDegree;
}

float G3Node::getScaleX()
{
    return m_scaleX;
}

float G3Node::getScaleY()
{
    return m_scaleY;
}

void G3Node::setParent(G3Node *parent)
{
    m_parent = parent;
}
void G3Node::setPosX(float posX)
{
    m_posX = ((getParent()) ? getParent()->m_posX : 0) + posX;

    for (const auto &child : m_children)
    {
        child->setPosX(posX);
    }
}

void G3Node::setPosY(float posY)
{
    m_posY = ((getParent()) ? getParent()->m_posY : 0) + posY;

    for (const auto &child : m_children)
    {
        child->setPosY(posY);
    }
}

void G3Node::setScaleX(float scaleX)
{
    m_scaleX = ((getParent()) ? getParent()->m_scaleX : 0) * scaleX;

    for (const auto &child : m_children)
    {
        child->setScaleX(scaleX);
    }
}

void G3Node::setScaleY(float scaleY)
{
    m_scaleY = ((getParent()) ? getParent()->m_scaleY : 0) * scaleY;

    for (const auto &child : m_children)
    {
        child->setScaleY(scaleY);
    }
}

void G3Node::setRotDegree(float rotDegree)
{
    m_rotDegree = rotDegree;
    for (const auto &child : m_children)
    {
        child->setRotDegree(rotDegree);
    }
}

void G3Node::setWidth(float width)
{
    m_width = width;
    for (const auto &child : m_children)
    {
        child->setWidth(width);
    }
}

void G3Node::setHeight(float height)
{
    m_height = height;
    for (const auto &child : m_children)
    {
        child->setHeight(height);
    }
}

void G3Node::flipH()
{
    m_scaleX = -m_scaleX;
}

void G3Node::flipV()
{
    m_scaleY = -m_scaleY;
}
