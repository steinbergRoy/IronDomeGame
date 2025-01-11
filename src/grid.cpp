#include <iostream>
#include "grid.hpp"
#include "entity.hpp"
#include "globals.hpp"
#include "assert.h"

namespace iron_dome_game
{


void Grid::addEntity(std::shared_ptr<Entity> entity) {
  assert(m_entities.size() < GameGlobals::MAX_NUM_OF_ENTETIES);
  m_entities.push_back(entity);
}
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
    m_entities.remove_if([](std::shared_ptr<Entity> entity) { return entity->getIntersection();});


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
        if (first == second)                                                        { continue; } // avoid check entity with itself (comparable since it's pointer)
        if (first->getIntersection() or second->getIntersection())                  { continue; } // avoid check entity that already intersected
        if (not first->canIntersectWith(second))                                    { continue; } // avoid check entity that can't be intersect with each other
        if (not (first->validForIntersection() and second->validForIntersection())) { continue; } // avoid removing pitcher/cannon
        if (intersects(first, second)) {
          hits++;
        }
      }
    }

    // sanity check, number of hits must be less than half of the entities:
    // each hit composed of pair of rocket & plate, and the cannon and the pitcher are also entities
    assert(hits < (m_entities.size() >> 1));
    return hits;
}

//============================================================================//

bool Grid::intersects(std::shared_ptr<Entity> first, std::shared_ptr<Entity> second) 
{
  return first->isIntersectWith(second);
}

}
