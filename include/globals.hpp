#pragma once

#define DEG_TO_RAD(x)   (x * 0.0174533)

namespace iron_dome_game
{

namespace GameGlobals {
static const int MAX_NUM_OF_ENTETIES = 100;
static const int DEFAULT_FIRE_POWER = 30;
}


namespace CannonGlobals {
static const uint16_t POS_X  = GRID_COLUMNS - 100;
static const uint16_t POS_Y  = 0;
static const uint16_t WIDTH  = 5;
static const uint16_t HEIGHT = 5;
}

namespace PitcherGlobals {
static const uint16_t POS_X  = GRID_COLUMNS - 7;
static const uint16_t POS_Y  = 0;
static const uint16_t WIDTH  = 5;
static const uint16_t HEIGHT = 6;
}


namespace RocketGlobals {
static const uint16_t POS_X  = (CannonGlobals::POS_X  - (CannonGlobals::WIDTH >> 1)); // the rocket launches from the middle X of the cannon
static const uint16_t POS_Y  = CannonGlobals::HEIGHT; // the rocket launches from the top of the cannon
static const uint16_t WIDTH  = 6;
static const uint16_t HEIGHT = 6;

// since the angle is constant to all items, we will us static variables calculate only once (trigonometric calculations are expensive)
static const int LAUNCH_ANGLE_DEG = 30;
static const float LAUNCH_ANGLE_RAD = DEG_TO_RAD(LAUNCH_ANGLE_DEG);
static const float LAUNCH_ANGLE_COS = std::cos(LAUNCH_ANGLE_RAD);
static const float LAUNCH_ANGLE_SIN = std::sin(LAUNCH_ANGLE_RAD);
static const int   FIRE_POWER       = 40;
}

namespace PlateGlobals {
static const uint16_t POS_X  = (PitcherGlobals::POS_X  - (PitcherGlobals::WIDTH >> 1));  // the plate launches from the middle X of the pitcher
static const uint16_t POS_Y  = PitcherGlobals::HEIGHT;  // the plate launches from the top of the pitcher
static const uint16_t WIDTH  = 3;
static const uint16_t HEIGHT = 3;


// since the angle is constant to all items, we will us static variables calculate only once (trigo calc are expensive)
static const int LAUNCH_ANGLE_DEG = 120;
static const float LAUNCH_ANGLE_RAD = DEG_TO_RAD(LAUNCH_ANGLE_DEG);
static const float LAUNCH_ANGLE_COS = std::cos(LAUNCH_ANGLE_RAD);
static const float LAUNCH_ANGLE_SIN = std::sin(LAUNCH_ANGLE_RAD);
}



}
