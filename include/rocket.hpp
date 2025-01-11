#pragma once

#include "entity.hpp"

namespace iron_dome_game
{
class Rocket : public DynamicEntity
{
public:
    Rocket(Velocity velocity);
    ~Rocket() = default;
    void drawOnGrid(Grid &grid) const override;
    bool validForIntersection() const override { return true; }
    bool canIntersectWith(std::shared_ptr<Entity> & other) const override { return other->type() == EntityType::PLATE; }

protected:
    EntityType type() const override { return EntityType::ROCKET; }

private:

};

}
