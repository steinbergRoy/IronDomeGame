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
    virtual void updatePosition() = 0;

protected:
//    Trajectory trajectory;
    virtual const Pos & pos() const = 0;
    virtual const State & getState() const = 0;

private:
    bool is_intersect = false;
    BoundingBox boundingBox() const;
    virtual bool isStatic() const = 0;

};

class StaticEntity : public Entity{
public:
  StaticEntity(const State  & _state) : state(_state) {}
  virtual ~StaticEntity() = default;

protected:
  const State & getState() const override { return state; }
  const Pos & pos() const override { return state.initialPos; }
  void updatePosition() override {}

  State state;

private:


};

class DynamicEntity : public Entity{
public:
  DynamicEntity(const DynamicState  & _state) : state(_state) {}
  virtual ~DynamicEntity() = default;

  static Velocity generateVelocity(EntityType type); // Generate velocity vector by type

protected:
  DynamicEntity() = default;
  const Pos & pos() const override;
  void updatePosition() override;
  const State & getState() const override { return state; }
  DynamicState state;

private:

};

}
