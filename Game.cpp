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
	this->coinTimerMax = 10.f;
	this->coinTimer = this->coinTimerMax;
	this->maxCoins = 3;
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720),
										"Slime Platformer Wars",
										sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

const bool Game::running() const
{
	return (this->window->isOpen());
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break ;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break ;
		}
	}
}

void Game::spawnCoins()
{
	//Timer
	if (this->coinTimer < this->coinTimerMax)
		this->coinTimer += 1.f;
	else
	{
		if (this->coins.size() < this->maxCoins)
		{
			this->coins.push_back(Coins(*this->window));
			this->coinTimer = 0.f;
		}
	}
}

void Game::updateCoins()
{
  for (int i = 0; i < this->coins.size(); i++)
  {
    this->coins[i].setCoinPosition(this->coins[i].getxVelocity(), this->coins[i].getyVelocity());
  }
}

void Game::update()
{
	this->pollEvents();
	this->spawnCoins();
	this->updateCoins();
}

void Game::render()
{
	this->window->clear();
	for (auto i : this->coins)
	{
		i.render(*this->window);
	}

	this->window->display();
}