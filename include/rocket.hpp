#pragma once

#include "entity.hpp"

namespace iron_dome_game
{
class Rocket : public Entity
{
public:
    Rocket(Velocity velocity);
    ~Rocket() = default;
    void drawOnGrid(Grid &grid) override;
    bool validForIntersection() override { return true; }
    bool canIntersectWith(std::shared_ptr<Entity> & other) override { return other->type() == EntityType::PLATE; }

protected:
    EntityType type() override { return EntityType::ROCKET; }
    bool isStatic() { return false; }

private:

};

}
