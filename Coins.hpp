#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <ctime>

enum CoinType {DEFAULT = 0, POINTS5, MINUS3, NBROFTYPES};

class Coins
{
  private:
      sf::CircleShape coin;
      sf::Vector2f position;
      float xVelocity;
      float yVelocity;
      int type;

      
      void initCoin(const sf::RenderWindow &window);


  public:
    //constructions
    Coins(const sf::RenderWindow &window, int type);
    virtual ~Coins();


    //Getters
    float &getxVelocity();
    float &getyVelocity();
    int &getType();

    //Setters
    void setCoinPosition(float &x, float &y);


    //Functions
    void update();
    void render(sf::RenderTarget &target);
    sf::CircleShape &getCoin();


};