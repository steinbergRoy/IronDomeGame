#include "rocket.hpp"

namespace iron_dome_game
{
Rocket::Rocket(Velocity velocity)
{
    trajectory.initialState.pos.x = GRID_COLUMNS - 52; // center of the cannon
    trajectory.initialState.pos.y = 5; // the height of the pitcher
    trajectory.initialState.velocity.x = velocity.x;
    trajectory.initialState.velocity.y = velocity.y;

    width   = 5;
    height  = 6;
}

//============================================================================//

void Rocket::drawOnGrid(Grid &grid)
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
