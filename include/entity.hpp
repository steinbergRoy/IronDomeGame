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
    virtual ~Entity() = default;

    virtual EntityType type() const  = 0; // cancel the default value to avoid creating undefined entity from type EntityType::NONE;

    // Intersection methods:
    bool getIntersection() const { return is_intersect; }
    virtual bool validForIntersection() const = 0;                            // check the validity for intersection, implemented by the derived classes
    virtual bool canIntersectWith(std::shared_ptr<Entity> & other) const = 0; // given other entity, return the validity of intersection between the two
    bool isIntersectWith(std::shared_ptr<Entity> & other);                    // given other entity, check if there intersection

    // utilities:
    virtual void drawOnGrid(Grid &grid) const = 0;
    virtual void updatePosition() = 0;  // update the position once a refresh (to avoid multiple calculations)

protected:
    virtual const Pos & pos() const = 0;
    BoundingBox boundingBox() const;

private:
    virtual const State & getState() const = 0;
    bool is_intersect = false;
};

//============================================================================//

class StaticEntity : public Entity{
public:
  StaticEntity(const State  & _state) : state(_state) {}
  virtual ~StaticEntity() = default;
  void updatePosition() override {}

protected:
  const Pos & pos() const override;

private:
  const State & getState() const override { return state; }

  State state;

};

//============================================================================//

class DynamicEntity : public Entity{
public:
  DynamicEntity(const DynamicState  & _state) : state(_state) {}
  virtual ~DynamicEntity() = default;
  void updatePosition() override;

  static Velocity generateVelocity(EntityType type); // Generate velocity vector by type

protected:
  const Pos & pos() const override;

private:
  const State & getState() const override { return state; }

  DynamicState state;


};

}
