#pragma once

#include "Coins.hpp"
#include "Player.hpp"
#include <vector>
#include <sstream>

class Coins;

class Game
{
  private: 
      sf::RenderWindow *window;
      sf::Event event;
      bool gameEnd;
      Player player1;
      Player player2;
      int pointsPlayer1;
      int pointsPlayer2;

      std::vector<Coins> coins;
      float coinTimerMax;
      float coinTimer;
      int maxCoins;

      sf::Font font;
      sf::Text txt;
      sf::Text txt2;


      void initVariables();
      void initWindow();
      void initFont();
      void initText();


  public:
      //constructions
      Game();
      virtual ~Game();

      //Getters
      int &getPlayer1Points();
      int &getPlayer2Points();

      //Setter
      void setPlayer1(Player &player);
      void setPlayer2(Player &player);


      //Functions
      void gainPoints(int points, int player);
      const bool running() const;
      void pollEvents();
      void spawnCoins();
      void updateCoins();
      void updateCollision();
      void updateText();
      void update();
      void renderText(sf::RenderTarget &target);
      void render();

};
