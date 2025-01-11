#pragma once

#include "entity.hpp"

namespace iron_dome_game
{
struct Pitcher : public Entity
{
    Pitcher();
    ~Pitcher() = default;

    EntityType type() override { return EntityType::PITCHER; }

    void drawOnGrid(Grid &grid) override;
    bool validForIntersection() override { return false; }
    bool canIntersectWith(std::shared_ptr<Entity> & other) override { return false; }

    bool isStatic() { return true; }
};

}
