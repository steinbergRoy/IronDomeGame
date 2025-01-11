#pragma once

#include "entity.hpp"

namespace iron_dome_game
{
class Plate : public Entity
{
public:
    Plate(Velocity velocity);
    ~Plate() = default;
    void drawOnGrid(Grid &grid) const override;
    bool validForIntersection() const override { return true; }
    bool canIntersectWith(std::shared_ptr<Entity> & other) const override { return other->type() == EntityType::ROCKET; }

protected:
    EntityType type() const override { return EntityType::PLATE; }
    bool isStatic() const { return false; }

private:


};

}
