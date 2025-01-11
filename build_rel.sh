#!/bin/bash

g++ src/*.cpp -I$(pwd)/include -lpthread -DNDEBUG -o iron_dome_game
