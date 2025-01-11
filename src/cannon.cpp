#include "config.hpp"
#include "cannon.hpp"

namespace iron_dome_game
{
Cannon::Cannon()
{
    trajectory.initialState.pos.x = GRID_COLUMNS - 50;
    trajectory.initialState.pos.y = 0;

    width    = 5;
    height   = 5;
}

//============================================================================//

void Cannon::drawOnGrid(Grid &grid)
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
