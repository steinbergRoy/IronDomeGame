#include "plate.hpp"
#include "globals.hpp"

namespace iron_dome_game
{
Plate::Plate(Velocity velocity)
{
    trajectory.initialState.pos.x = PlateGlobals::POS_X;
    trajectory.initialState.pos.y = PlateGlobals::POS_Y;
    trajectory.initialState.velocity.x = velocity.x;
    trajectory.initialState.velocity.y = velocity.y;

    width   = PlateGlobals::WIDTH;
    height  = PlateGlobals::HEIGHT;
}

//============================================================================//

void Plate::drawOnGrid(Grid &grid) const
{
    auto col = pos().x;
    auto row = pos().y;

    grid.drawPixel(row, col,   '\\');
    grid.drawPixel(row, col+1, '_');
    grid.drawPixel(row, col+2, '/');

    grid.drawPixel(row+1, col  , '|');
    grid.drawPixel(row+1, col+1, ' ');
    grid.drawPixel(row+1, col+2, '|');

    grid.drawPixel(row+2, col  , '/');
    grid.drawPixel(row+2, col+1, '^');
    grid.drawPixel(row+2, col+2, '\\');
}

}
