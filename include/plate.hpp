#pragma once

#include "entity.hpp"

namespace iron_dome_game
{
struct Plate : public Entity
{
    Plate(Velocity velocity);
    ~Plate() = default;

    void drawOnGrid(Grid &grid) override;

    EntityType type() override { return EntityType::PLATE; }
    bool validForIntersection() override { return true; }
    bool canIntersectWith(std::shared_ptr<Entity> & other) override { return other->type() == EntityType::ROCKET; }

    bool isStatic() { return false; }
};

}
