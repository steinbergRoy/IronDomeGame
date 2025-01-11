#pragma once

#include "entity.hpp"

namespace iron_dome_game
{
class Pitcher : public StaticEntity
{
public:
    Pitcher();
    ~Pitcher() = default;
    void drawOnGrid(Grid &grid) const override;
    bool validForIntersection() const override { return false; }
    bool canIntersectWith(std::shared_ptr<Entity> & other) const override { return false; }

protected:
    EntityType type() const override { return EntityType::PITCHER; }
    bool isStatic() const { return true; }

private:

};

}
