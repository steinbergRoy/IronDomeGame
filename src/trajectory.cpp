#include "trajectory.hpp"

namespace iron_dome_game
{

void DynamicState::updatePosition(std::chrono::steady_clock::time_point)
{
    current_position.x = round(initial_pos.x + velocity.x * duration().count());
    current_position.y = round(initial_pos.y + velocity.y * duration().count() + 0.5 * GRAVITY * pow(duration().count(), 2));
}

}






