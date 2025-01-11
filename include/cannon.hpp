#pragma once

#include "entity.hpp"

namespace iron_dome_game
{
struct Cannon : public Entity
{
    Cannon();
    ~Cannon() = default;

    EntityType type() override { return EntityType::CANNON; }

    void drawOnGrid(Grid &grid) override;
    bool validForIntersection() override { return false; }
    bool isStatic() { return true; }
};

}
