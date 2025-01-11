#include "entity.hpp"

namespace iron_dome_game
{

Pos Entity::pos() 
{
    if (isStatic())
    {
        return trajectory.initialState.pos;
    }
    else
    {
        return trajectory.calculatePosition();
    }
}

//============================================================================//

BoundingBox Entity::boundingBox() 
{
    BoundingBox bbox;
    bbox.bottom_left = pos();
    bbox.top_right.x = pos().x + width - 1;
    bbox.top_right.y = pos().y + height - 1;

    return bbox;
}


bool Entity::isIntersectWith(std::shared_ptr<Entity> & other) {
    bool diverge_at_x  =        boundingBox().top_right.x < other->boundingBox().bottom_left.x;
         diverge_at_x |= other->boundingBox().top_right.x <        boundingBox().bottom_left.x;

   bool diverge_at_y  =        boundingBox().top_right.y < other->boundingBox().bottom_left.y;
        diverge_at_y |= other->boundingBox().top_right.y <        boundingBox().bottom_left.y;

    bool intersection_result = not diverge_at_x and not diverge_at_y;

    is_intersect = other->is_intersect = intersection_result;


    return intersection_result;
}


}
