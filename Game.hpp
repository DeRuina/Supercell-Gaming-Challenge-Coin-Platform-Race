#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <ctime>


class Game
{
  private: 
      sf::RenderWindow *window;
      sf::Event event;
      bool gameEnd;


      void initVariables();
      void initWindow();


  public:
      //constructions
      Game();
      virtual ~Game();

      //Getter


      //Functions
      void update();
      void render();
      const bool running() const;
      void pollEvents();

};
