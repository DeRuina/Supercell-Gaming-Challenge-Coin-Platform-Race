#include "Game.hpp"

Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::initVariables()
{
	this->gameEnd = false;
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600),
	"Slime Platformer Wars", sf::Style::Close | sf::Style::Titlebar);
}

const bool Game::running() const
{
	return (this->window->isOpen());
}

void Game::pollEvents()
{
  while(this->window->pollEvent(this->event))
  {
    switch (this->event.type)
		{
		  case sf::Event::Closed:
			    this->window->close();
			    break;
		  case sf::Event::KeyPressed:
			    if (this->event.key.code == sf::Keyboard::Escape)
				    this->window->close();
			      break;
		}
  }
}

void Game::update()
{
  this->pollEvents();
}

void Game::render()
{
  this->window->clear();
  // this->window->draw();
  this->window->display();
}