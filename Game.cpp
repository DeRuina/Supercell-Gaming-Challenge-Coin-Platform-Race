#include "Game.hpp"
#include "Player.hpp"

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initFont();
	this->initText();
}

Game::~Game()
{
	delete this->window;
}

int &Game::getPlayer1Points()
{
	return (this->pointsPlayer1);
}

int &Game::getPlayer2Points()
{
	return (this->pointsPlayer2);
}

void Game::setPlayer1(Player &player)
{
  this->player1 = player;
}

void Game::setPlayer2(Player &player)
{
  this->player2 = player;
}

void Game::initVariables()
{
	this->gameEnd = false;
	this->coinTimerMax = 10.f;
	this->coinTimer = this->coinTimerMax;
	this->maxCoins = 10;
	this->pointsPlayer1 = 0;
	this->pointsPlayer2 = 0;
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720),
										"Slime Platformer Wars",
										sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::initFont()
{
	if (!this->font.loadFromFile("belagio/BelagioFont.ttf"))
		std::cout << "Error loadinf font" << std::endl;
}

void Game::initText()
{
	this->txt.setFont(this->font);
	this->txt.setFillColor(sf::Color::White);
	this->txt.setCharacterSize(32);
	this->txt.setPosition(sf::Vector2f(10.f, 10.f));
}

void Game::gainPoints(int points, int player)
{
	if (player == 1)
		this->pointsPlayer1 += points;
	if (player == 2)
		this->pointsPlayer2 += points;
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
			this->coins.push_back(Coins(*this->window, rand()
						% CoinType::NBROFTYPES));
			this->coinTimer = 0.f;
		}
	}
}

void Game::updateCoins()
{
	for (int i = 0; i < this->coins.size(); i++)
	{
		this->coins[i].setCoinPosition(this->coins[i].getxVelocity(),
										this->coins[i].getyVelocity());
	}
}

void Game::updateCollision()
{
	for (size_t i = 0; i < this->coins.size(); i++)
	{
		if (this->player1.getPlayer().getGlobalBounds().intersects(this->coins[i].getCoin().getGlobalBounds()))
		{
      switch (this->coins[i].getType())
      {
          case CoinType::DEFAULT:
            this->gainPoints(1, 1);
            break;
          case CoinType::POINTS5:
            this->gainPoints(5, 1);
            break;
          case CoinType::MINUS3:
            this->gainPoints(-3, 1);
            break;
      }
			this->coins.erase(this->coins.begin() + i);
		}
    if (this->player2.getPlayer().getGlobalBounds().intersects(this->coins[i].getCoin().getGlobalBounds()))
		{
      switch (this->coins[i].getType())
      {
          case CoinType::DEFAULT:
            this->gainPoints(1, 2);
            break;
          case CoinType::POINTS5:
            this->gainPoints(5, 2);
            break;
          case CoinType::MINUS3:
            this->gainPoints(-3, 2);
            break;
      }
			this->coins.erase(this->coins.begin() + i);
		}
	}
}

void Game::updateText()
{
  std::stringstream ss;
  ss << "Player 1 points: " << this->getPlayer1Points() << "\n";
	this->txt.setString(ss.str());
}

void Game::update()
{
	this->pollEvents();
	this->spawnCoins();
	this->updateCoins();
	this->player1.update(*this->window, 0);
	this->player2.update(*this->window, 1);
	this->updateCollision();
	this->updateText();
}

void Game::renderText(sf::RenderTarget &target)
{
	target.draw(this->txt);
}

void Game::render()
{
	this->window->clear();
	for (auto i : this->coins)
	{
		i.render(*this->window);
	}
	this->player1.render(*this->window);
	this->player2.render(*this->window);
	this->renderText(*this->window);
	this->window->display();
}