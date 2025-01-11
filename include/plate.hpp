#pragma once

#include "entity.hpp"

namespace iron_dome_game
{
class Plate : public Entity
{
public:
    Plate(Velocity velocity);
    ~Plate() = default;
    void drawOnGrid(Grid &grid) override;
    bool validForIntersection() override { return true; }
    bool canIntersectWith(std::shared_ptr<Entity> & other) override { return other->type() == EntityType::ROCKET; }

protected:
    EntityType type() override { return EntityType::PLATE; }
    bool isStatic() { return false; }

private:


};

}
