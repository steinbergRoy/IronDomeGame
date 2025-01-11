#include "plate.hpp"
#include "globals.hpp"

namespace iron_dome_game
{

Plate::Plate(Velocity velocity): DynamicEntity(DynamicState(PlateGlobals::POS_X, PlateGlobals::POS_Y, PlateGlobals::WIDTH, PlateGlobals::HEIGHT, velocity)) {}


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
