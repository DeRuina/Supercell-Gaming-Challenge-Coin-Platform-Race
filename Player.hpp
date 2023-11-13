#pragma once

#include "Coins.hpp"


class Player
{
  private:
      sf::RectangleShape playerShape;
      float moveSpeed;

      void initVariables();
      void initShape(int i);


  public:
    //constructions
    Player(float x = 0.f, float y = 0.f, int i = 0);
    virtual ~Player();


    //Setters



    //Functions
    sf::RectangleShape &getPlayer();
    void updateInput(int i);
    void update(sf::RenderTarget &target, int i);
    void render(sf::RenderTarget &target);
    void updateBoundsCollision(sf::RenderTarget &target);

};