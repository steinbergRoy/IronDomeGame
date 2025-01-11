#include "entity.hpp"
#include "globals.hpp"
#include "assert.h"

namespace iron_dome_game
{


BoundingBox Entity::boundingBox() const
{
    BoundingBox bbox;
    bbox.bottom_left = pos();
    bbox.top_right.x = pos().x + getState().width - 1;
    bbox.top_right.y = pos().y + getState().height - 1;

    return bbox;
}

//============================================================================//

bool Entity::isIntersectWith(std::shared_ptr<Entity> & other) {
    bool diverge_at_x  =        boundingBox().top_right.x < other->boundingBox().bottom_left.x;
         diverge_at_x |= other->boundingBox().top_right.x <        boundingBox().bottom_left.x;

   bool diverge_at_y  =        boundingBox().top_right.y < other->boundingBox().bottom_left.y;
        diverge_at_y |= other->boundingBox().top_right.y <        boundingBox().bottom_left.y;

    bool intersection_result = not diverge_at_x and not diverge_at_y;

    is_intersect = other->is_intersect = intersection_result;


    return intersection_result;
}

//============================================================================//

void DynamicEntity::updatePosition() {
     state.updatePosition();
}

//============================================================================//


const Pos & DynamicEntity::pos() const {
  return state.currentPosition;
}

//============================================================================//

Velocity DynamicEntity::generateVelocity(EntityType type) {
  int firePower = GameGlobals::DEFAULT_FIRE_POWER;

  switch(type) {
    case EntityType::PLATE: {
      firePower = std::rand() % 15 + 30;
      return Velocity(PlateGlobals::LAUNCH_ANGLE_COS * firePower, PlateGlobals::LAUNCH_ANGLE_SIN * firePower);
      break;
    }
    case EntityType::ROCKET: {
      firePower = RocketGlobals::FIRE_POWER;
      return Velocity(RocketGlobals::LAUNCH_ANGLE_COS * firePower, RocketGlobals::LAUNCH_ANGLE_SIN * firePower);
      break;

    }
    case EntityType::NONE:
    case EntityType::PITCHER:
    case EntityType::CANNON:
    default: { assert(false); }
  }
  return Velocity();
}


}
