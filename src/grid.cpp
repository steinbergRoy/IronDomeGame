#include <iostream>
#include "grid.hpp"
#include "entity.hpp"

namespace iron_dome_game
{

void Grid::draw() 
{
    for (int i = GRID_ROWS - 1; i >= 0; --i)
    {
        for (int j = 0; j < GRID_COLUMNS; ++j)
        {
            std::cout << m_grid[i][j];
        }
        std::cout << std::endl;
    }
}

//============================================================================//

void Grid::refresh() 
{
    // Draw background
    forEveryPixel(
        [this](int row, int col)
        {
            m_grid[row][col] = ' ';
        }
    );

    // Draw ground
    forEveryPixel(
        [this](int row, int col)
        {
            m_grid[row][col] = '_';
        },
        1
    );
    m_entities.remove_if([](std::shared_ptr<Entity> entity) { return entity->isIntersect;});


    for (auto entity : m_entities)
    {
        entity->drawOnGrid(*this);
    }
}

//============================================================================//

bool Grid::drawPixel(uint16_t row, uint16_t col, char pixel) 
{
    if (row >= 0 && row < rows() && col >= 0 && col < columns() && pixel != ' ')
    {
        m_grid[row][col] = pixel;
        return true;
    }
    return false;
}

//============================================================================//

void Grid::forEveryPixel(std::function<void(int row, int col)> function, const int rowCount, const int columnCount) 
{
    for (int i = 0; i < rowCount; ++i)
    {
        for (int j = 0; j < columnCount; ++j)
        {
            function(i, j);
        }
    }
}

//============================================================================//

uint16_t Grid::checkHits() 
{
    uint16_t hits = 0;
    for (auto & first : m_entities) {
      for (auto & second : m_entities) {
        if (first == second) { continue; } // avoid check entity with itself (comparable since it's pointer)
        if (first->isIntersect or second->isIntersect) { continue; } // avoid check entity that already intersected
        if (not first->validForIntersection() or not second->validForIntersection()) { continue; } // avoid removing pitcher/cannon
        if (intersects(first, second)) {
          first->isIntersect = second->isIntersect = true;
          hits++;
        }
      }
    }

    return hits;
}

//============================================================================//

bool Grid::intersects(std::shared_ptr<Entity> first, std::shared_ptr<Entity> second) 
{
  bool diverge_at_x  = first ->boundingBox().top_right.x < second->boundingBox().bottom_left.x;
       diverge_at_x |= second->boundingBox().top_right.x < first ->boundingBox().bottom_left.x;

   bool diverge_at_y  = first ->boundingBox().top_right.y < second->boundingBox().bottom_left.y;
        diverge_at_y |= second->boundingBox().top_right.y < first ->boundingBox().bottom_left.y;

    if (diverge_at_x or diverge_at_y) { return false; }
    return true;
}

}
