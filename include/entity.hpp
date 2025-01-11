#pragma once

#include "config.hpp"
#include "grid.hpp"
#include "trajectory.hpp"

namespace iron_dome_game
{
enum EntityType
{
    NONE,
    PITCHER,
    CANNON,
    PLATE,
    ROCKET
};

class Entity
{
public:
    virtual EntityType type() { return EntityType::NONE; }
    bool getIntersection() const { return is_intersect; }
    virtual bool validForIntersection() = 0;
    virtual bool canIntersectWith(std::shared_ptr<Entity> & other) = 0;
    bool isIntersectWith(std::shared_ptr<Entity> & other);
    virtual void drawOnGrid(Grid &grid) = 0;

protected:
    Trajectory trajectory;
    Pos pos();
    uint16_t width = 0;
    uint16_t height = 0;

private:
    bool is_intersect = false;
    BoundingBox boundingBox();
    virtual bool isStatic() = 0;

};
}
