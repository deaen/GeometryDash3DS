#pragma once
#include <typeinfo>
#include "G3Node.h"
#include "G3LevelObject.h"
#include "G3Globals.h"

// a node that ONLY contains levelobject(s) (or anything honestly), and acts as a camera, children of THIS cool little node only render when they're on screen!!!!!!
class G3LevelObjectContainer : public G3Node
{
public:
    G3LevelObjectContainer();
    static std::shared_ptr<G3LevelObjectContainer> create();
    void sortChildren();
    /* X position getters*/

    float topLeftPosX();
    float bottomLeftPosX();

    float topRightPosX();
    float bottomRightPosX();

    float centerPosX();

    /* Y position getters */

    float topLeftPosY();
    float bottomLeftPosY();

    float topRightPosY();
    float bottomRightPosY();

    float centerPosY();

    void update() override;
    bool overlaps(G3Node *child);
    void draw() override; // draw bottom layers
    void drawTopLayers();
private:
    // std::vector<std::shared_ptr<G3LevelObject>> m_b5{};
    // std::vector<std::shared_ptr<G3LevelObject>> m_b4{};
    // std::vector<std::shared_ptr<G3LevelObject>> m_b3{};
    std::vector<std::shared_ptr<G3LevelObject>> m_b2{};
    std::vector<std::shared_ptr<G3LevelObject>> m_b1{};
    std::vector<std::shared_ptr<G3LevelObject>> m_playerLayer{};
    std::vector<std::shared_ptr<G3LevelObject>> m_t1{};
    // std::vector<std::shared_ptr<G3LevelObject>> m_t2{};
    // std::vector<std::shared_ptr<G3LevelObject>> m_t3{};
    // std::vector<std::shared_ptr<G3LevelObject>> m_t4{};

    void drawLayer(const std::vector<std::shared_ptr<G3LevelObject>> &layer);
    void sortLayer(std::vector<std::shared_ptr<G3LevelObject>> &layer);
};
