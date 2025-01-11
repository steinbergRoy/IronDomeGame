#pragma once

#include "entity.hpp"

namespace iron_dome_game
{
class Cannon : public StaticEntity
{
public:
    Cannon();
    ~Cannon() = default;
    void drawOnGrid(Grid &grid) const override;
    bool validForIntersection() const override { return false; }
    bool canIntersectWith(std::shared_ptr<Entity> & other) const override { return false; }

protected:
    EntityType type() const override { return EntityType::CANNON; }

private:



};

}
