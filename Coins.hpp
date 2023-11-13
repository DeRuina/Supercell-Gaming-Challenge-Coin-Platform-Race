#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <ctime>
#include "Player.hpp"

class Coins
{
  private:
      sf::CircleShape coin;
      sf::Vector2f position;
      float xVelocity;
      float yVelocity;

      
      void initCoin(const sf::RenderWindow &window);


  public:
    //constructions
    Coins(const sf::RenderWindow &window);
    virtual ~Coins();


    //Getters

    //Setters
    void setCoinPosition(float &x, float &y);
    float &getxVelocity();
    float &getyVelocity();


    //Functions
    void update();
    void render(sf::RenderTarget &target);

};