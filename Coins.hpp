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

  void initCoin();


  public:
    //constructions
    Coins();
    virtual ~Coins();


    //Getters


    //Functions
    void update();
    void render(sf::RenderTarget &target);

};