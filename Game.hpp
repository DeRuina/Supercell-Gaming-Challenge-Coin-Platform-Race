#pragma once

#include "Coins.hpp"
#include <vector>

class Coins;

class Game
{
  private: 
      sf::RenderWindow *window;
      sf::Event event;
      bool gameEnd;
      float xVelocity;
      float yVelocity;

      std::vector<Coins> coins;
      float coinTimerMax;
      float coinTimer;
      int maxCoins;


      void initVariables();
      void initWindow();


  public:
      //constructions
      Game();
      virtual ~Game();

      //Getters


      //Functions
      const bool running() const;
      void pollEvents();
      void spawnCoins();
      void updateCoins();
      void update();
      void render();

};