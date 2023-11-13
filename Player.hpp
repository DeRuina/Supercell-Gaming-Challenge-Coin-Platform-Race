#pragma once

#include "Coins.hpp"


class Player
{
  private:
      sf::RectangleShape playerShape;
      float moveSpeed;

      void initVariables();
      void initShape();


  public:
    //constructions
    Player(float x = 0.f, float y = 0.f);
    virtual ~Player();


    //Getters


    //Functions
    sf::RectangleShape &getPlayer();
    void updateInput();
    void update(sf::RenderTarget &target);
    void render(sf::RenderTarget &target);
    void updateBoundsCollision(sf::RenderTarget &target);

};