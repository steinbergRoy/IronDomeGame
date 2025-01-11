#pragma once

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
    virtual EntityType type() const  = 0; // cancel the default value to avoid creating undefined entity from type EntityType::NONE;
    bool getIntersection() const { return is_intersect; }
    virtual bool validForIntersection() const = 0;
    virtual bool canIntersectWith(std::shared_ptr<Entity> & other) const = 0;
    bool isIntersectWith(std::shared_ptr<Entity> & other);
    virtual void drawOnGrid(Grid &grid) const = 0;

protected:
//    Trajectory trajectory;
    virtual Pos pos() const = 0;
    virtual const State & getState() const = 0;

private:
    bool is_intersect = false;
    BoundingBox boundingBox() const;
    virtual bool isStatic() const = 0;

};

class StaticEntity : public Entity{
public:
  StaticEntity(const State  & _state) : state(_state) {}

protected:
  const State & getState() const override { return state; }
  Pos pos() const override { return state.initialPos; }
  State state;
//  StaticEntity() = default;

private:


};

class DynamicEntity : public Entity{
public:
  DynamicEntity(const DynamicState  & _state) : state(_state) {}

protected:
  Pos pos() const override { return state.calculatePosition(); }
  const State & getState() const override { return state; }
  DynamicState state;
  DynamicEntity() = default;

private:

};

}
