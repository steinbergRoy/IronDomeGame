#pragma once
#include <stdint.h>
#include <chrono>
#include <math.h>
#include "config.hpp"

namespace iron_dome_game
{
struct Pos
{
  Pos() = default;
  Pos(uint16_t _x, uint16_t _y) : x(_x), y(_y) {}
  Pos(const Pos & other) : x(other.x), y(other.y) {}
    uint16_t x = 0;
    uint16_t y = 0;
};

struct Velocity
{
  Velocity() = default;
  Velocity(uint16_t _x, uint16_t _y) : x(_x), y(_y) {}
  Velocity(const Pos & other) : x(other.x), y(other.y) {}

    int16_t x = 0;
    int16_t y = 0;
};

struct State {
  State(uint16_t x, uint16_t y, uint16_t w, uint16_t h) : initialPos(x, y), width(w), height(h) {}
  State(const Pos & pos, uint16_t w, uint16_t h) : initialPos(pos.x, pos.y), width(w), height(h) {}
  State(const State & other) : initialPos(other.initialPos), width(other.width), height(other.height) {}
    Pos initialPos;
    uint16_t width = 0;
    uint16_t height = 0;
};

struct DynamicState : State
{
  DynamicState(const DynamicState & other) : State(other), velocity(other.velocity)  {}
  DynamicState(uint16_t x, uint16_t y, uint16_t w, uint16_t h, Velocity v) : State(x, y,w, h), velocity(v.x, v.y) {}
  DynamicState(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t vx, uint16_t vy) : State(x, y,w, h), velocity(vx, vy) {}

    Velocity velocity;
    std::chrono::steady_clock::time_point t0 = std::chrono::steady_clock::now();
    std::chrono::duration<float> duration() const { return  std::chrono::steady_clock::now() - t0; }

    Pos calculatePosition(std::chrono::steady_clock::time_point = std::chrono::steady_clock::now()) const
    {
        Pos pos;
        pos.x = round(initialPos.x + velocity.x * duration().count());
        pos.y = round(initialPos.y + velocity.y * duration().count() + 0.5 * GRAVITY * pow(duration().count(), 2));

        return pos;
    }
};

//struct Trajectory
//{
//    InitialState initialState;
//
//};
}
