#pragma once

#include "entity.hpp"

namespace iron_dome_game
{
class Cannon : public Entity
{
public:
    Cannon();
    ~Cannon() = default;
    void drawOnGrid(Grid &grid) override;
    bool validForIntersection() override { return false; }
    bool canIntersectWith(std::shared_ptr<Entity> & other) override { return false; }

protected:
    EntityType type() override { return EntityType::CANNON; }
    bool isStatic() { return true; }

private:



};

}
