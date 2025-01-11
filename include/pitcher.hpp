#pragma once

#include "entity.hpp"

namespace iron_dome_game
{
class Pitcher : public Entity
{
public:
    Pitcher();
    ~Pitcher() = default;
    void drawOnGrid(Grid &grid) override;
    bool validForIntersection() override { return false; }
    bool canIntersectWith(std::shared_ptr<Entity> & other) override { return false; }

protected:
    EntityType type() override { return EntityType::PITCHER; }
    bool isStatic() { return true; }

private:

};

}
