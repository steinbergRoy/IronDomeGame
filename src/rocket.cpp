#include "rocket.hpp"
#include "globals.hpp"

namespace iron_dome_game
{
Rocket::Rocket(Velocity velocity): DynamicEntity(DynamicState(RocketGlobals::POS_X, RocketGlobals::POS_Y, RocketGlobals::WIDTH, RocketGlobals::HEIGHT, velocity)) {}


//============================================================================//

void Rocket::drawOnGrid(Grid &grid) const
{
    auto col = pos().x;
    auto row = pos().y;

    grid.drawPixel(row, col + 2, '/');
    grid.drawPixel(row + 1, col + 1, '/');
    grid.drawPixel(row + 1, col + 2, '|');
    grid.drawPixel(row + 1, col + 3, '\\');

    grid.drawPixel(row + 2, col + 1, '|');
    grid.drawPixel(row + 2, col + 2, '|');
    grid.drawPixel(row + 2, col + 3, '|');

    grid.drawPixel(row + 3, col + 1, '|');
    grid.drawPixel(row + 3, col + 2, '|');
    grid.drawPixel(row + 3, col + 3, '|');

    grid.drawPixel(row + 4, col, '/');
    grid.drawPixel(row + 4, col + 4, '\\');

    grid.drawPixel(row + 5, col, '\\');
    grid.drawPixel(row + 5, col + 4, '/');

    grid.drawPixel(row + 6, col + 1, 'V');
    grid.drawPixel(row + 6, col + 2, 'V');
    grid.drawPixel(row + 6, col + 3, 'V');
}

}
