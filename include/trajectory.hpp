#pragma once
#include <stdint.h>
#include <chrono>
#include <math.h>
#include "config.hpp"

// I left the file name still to be called trajectory for the reviewing convenience

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

    int16_t x = 0;
    int16_t y = 0;
};

class State {
public:
  State(uint16_t x, uint16_t y, uint16_t w, uint16_t h) : initial_pos(x, y), _width(w), _height(h) {}
  State(const State & other) : initial_pos(other.initial_pos), _width(other._width), _height(other._height) {}
  virtual ~State() = default;

  virtual const Pos & getPos() const { return initial_pos; }
  const uint16_t & width()     const { return _width; }
  const uint16_t & height()    const { return _height; }

protected:
    Pos initial_pos;
    uint16_t _width = 0;
    uint16_t _height = 0;
};

class DynamicState : public State
{
public:
  DynamicState(const DynamicState & other) : State(other), velocity(other.velocity)  {}
  DynamicState(uint16_t x, uint16_t y, uint16_t w, uint16_t h, Velocity v) : State(x, y,w, h), velocity(v.x, v.y) {}
  virtual ~DynamicState() = default;

  const Pos & getPos() const override { return current_position; }
  void updatePosition(std::chrono::steady_clock::time_point = std::chrono::steady_clock::now());

private:

    Velocity velocity;
    Pos current_position;

    std::chrono::steady_clock::time_point t0 = std::chrono::steady_clock::now();
    std::chrono::duration<float> duration() const { return  std::chrono::steady_clock::now() - t0; }

};


}
