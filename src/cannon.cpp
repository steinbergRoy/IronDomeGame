#include "config.hpp"
#include "cannon.hpp"
#include "globals.hpp"

namespace iron_dome_game
{
Cannon::Cannon()
{
    trajectory.initialState.pos.x = CannonGlobals::POS_X;
    trajectory.initialState.pos.y = CannonGlobals::POS_Y;

    width    = CannonGlobals::WIDTH;
    height   = CannonGlobals::HEIGHT;
}

//============================================================================//

void Cannon::drawOnGrid(Grid &grid) const
{
    auto col = pos().x;
    auto row = pos().y;

    grid.drawPixel(row, col + 2, '-');
    grid.drawPixel(row, col + 1, '-');
    grid.drawPixel(row, col + 0, '-');
    grid.drawPixel(row, col + 3, '-');
    grid.drawPixel(row, col + 4, '-');

    grid.drawPixel(row + 1, col + 1, '|');
    grid.drawPixel(row + 1, col + 2, '|');
    grid.drawPixel(row + 1, col + 3, '|');

    grid.drawPixel(row + 2, col + 2, '|');

    grid.drawPixel(row + 3, col, 'o');
    grid.drawPixel(row + 3, col + 4, 'o');

    grid.drawPixel(row + 4, col, '_');
    grid.drawPixel(row + 4, col + 4, '_');
}

}
