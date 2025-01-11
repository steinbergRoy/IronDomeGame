#pragma once

#include "entity.hpp"

namespace iron_dome_game
{
struct Rocket : public Entity
{
    Rocket(Velocity velocity);
    ~Rocket() = default;

    void drawOnGrid(Grid &grid) override;

    EntityType type() override { return EntityType::ROCKET; }
    bool validForIntersection() override { return true; }
    bool canIntersectWith(std::shared_ptr<Entity> & other) override { return other->type() == EntityType::PLATE; }

    bool isStatic() { return false; }
};

}
