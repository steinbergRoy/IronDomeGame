#include <iostream>
#include <random>
#include <memory>
#include <math.h>

#include "game.hpp"
#include "globals.hpp"
#include "cannon.hpp"
#include "rocket.hpp"


namespace iron_dome_game
{

Game::Game() 
{
  grid.addEntity(std::make_shared<iron_dome_game::Pitcher>());
  grid.addEntity(std::make_shared<iron_dome_game::Cannon>());
}

//============================================================================//

void Game::keyboardListener() 
{
    while (gameIsActive)
    {
        // Block until a newline is entered
        char c = getchar();
        // std::cout << "Fired" << std::endl;
        isShotFired = true;
    }
}

//============================================================================//

void Game::play() 
{
    gameIsActive = true;

    // std::cout << "PLAYING" << std::endl;
    std::chrono::steady_clock::time_point t0 = std::chrono::steady_clock::now();
    std::thread keyboardThread(&Game::keyboardListener, this);

    std::chrono::steady_clock::time_point lastTimeRefreshed = std::chrono::steady_clock::now();

    while (gameIsActive)
    {
        if (isShotFired)
        {
            isShotFired = false;
            ++shotsFired;
            launchRocket();
        }

        if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - lastTimeRefreshed).count() > 100)
        {
            system("clear");
            grid.refresh();
            grid.draw();
            
            lastTimeRefreshed = std::chrono::steady_clock::now();
        }

        platesHit += grid.checkHits();

        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        auto gameTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - t0).count();
        if (gameTime > GAME_RUN_TIME_SEC)
        {
            gameIsActive = false;
        }
        else if (gameTime / 2 > platesFired)
        {
            spawnPlate();
            ++platesFired;
        }
    }

    std::cout << "Game over. Total hits: " << platesHit << ". Total shots fired: " << shotsFired << std::endl;
    std::cout << "Accuracy " << (float)platesHit /  shotsFired * 100 << "%" << std::endl;
    keyboardThread.join();
}

//============================================================================//

void Game::spawnPlate() 
{
    int firePower = std::rand() % 15 + 30;
    Velocity velocity;
    velocity.x = PlateGlobals::LAUNCH_ANGLE_COS * firePower;
    velocity.y = PlateGlobals::LAUNCH_ANGLE_SIN * firePower;
    grid.addEntity(std::make_shared<Plate>(velocity));
}

void Game::launchRocket()
{
    int firePower = 35; //std::rand() % 15 + 30;
    Velocity velocity;
    velocity.x = RocketGlobals::LAUNCH_ANGLE_COS * firePower;
    velocity.y = RocketGlobals::LAUNCH_ANGLE_SIN * firePower;
    grid.addEntity(std::make_shared<Rocket>(velocity));
}

}
