#include <G3Node.h>

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

G3Node &G3Node::setTag(std::string_view tag)
{
    m_tag = tag;
    return *this;
}

G3Node &G3Node::setDrawOn(G3Node::Screen screen)
{
    m_drawOn = screen;
    return *this;
}

std::string_view G3Node::getTag()
{
    return m_tag;
}

G3Node::Screen G3Node::getDrawOn()
{
    return m_drawOn;
}

void G3Node::addChild(std::shared_ptr<G3Node> ptr)
{
    if ((this != ptr.get()) && (std::find(m_children.begin(), m_children.end(), ptr) == m_children.end()))
    {
        m_children.push_back(ptr);
        ptr->parent.reset(this);
    }
}

void G3Node::clearChildren()
{
    m_children.clear();
}
