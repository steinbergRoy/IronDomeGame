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

}