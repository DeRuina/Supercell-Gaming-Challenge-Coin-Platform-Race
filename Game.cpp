#include "Game.hpp"
#include "Player.hpp"

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initFont();
	this->initText();
  this->initRec();
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

bool &Game::getEndGame()
{
	return (this->gameEnd);
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
	this->redCoinTimerMax = 50.f;
	this->coinTimer = this->coinTimerMax;
	this->maxCoins = 15;
	this->pointsPlayer1 = 0;
	this->pointsPlayer2 = 0;
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720),
										"Coin Platform Race",
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
	this->txt2.setFont(this->font);
	this->txt.setFillColor(sf::Color::White);
	this->txt2.setFillColor(sf::Color::White);
	this->txt.setCharacterSize(32);
	this->txt2.setCharacterSize(32);
	this->txt.setPosition(sf::Vector2f(0.f, 0.f));
	this->txt2.setPosition(sf::Vector2f(0.f, 50.f));
}

void Game::initRec()
{
  this->rec1.setSize(sf::Vector2f(150, 30));
  this->rec2.setSize(sf::Vector2f(150, 30));
  this->rec3.setSize(sf::Vector2f(150, 30));
  this->rec1.setPosition(sf::Vector2f(300, 300));
  this->rec2.setPosition(sf::Vector2f(800, 200));
  this->rec3.setPosition(sf::Vector2f(700, 550));
  this->rec1.setFillColor(sf::Color::White);
  this->rec2.setFillColor(sf::Color::White);
  this->rec3.setFillColor(sf::Color::White);
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
  if (this->player1.getPlayer().getGlobalBounds().intersects(this->rec1.getGlobalBounds()))
    this->player1 = Player(1000.f, 720.f, 0);
  if (this->player1.getPlayer().getGlobalBounds().intersects(this->rec2.getGlobalBounds()))
    this->player1 = Player(1000.f, 720.f, 0);
  if (this->player1.getPlayer().getGlobalBounds().intersects(this->rec3.getGlobalBounds()))
    this->player1 = Player(1000.f, 720.f, 0);
  if (this->player2.getPlayer().getGlobalBounds().intersects(this->rec1.getGlobalBounds()))
    this->player2 = Player(400.f, 720.f, 1);
  if (this->player2.getPlayer().getGlobalBounds().intersects(this->rec2.getGlobalBounds()))
    this->player2 = Player(400.f, 720.f, 1);
  if (this->player2.getPlayer().getGlobalBounds().intersects(this->rec3.getGlobalBounds()))
    this->player2 = Player(400.f, 720.f, 1);
	for (size_t i = 0; i < this->coins.size(); i++)
	{
		if (this->coins[i].getType() == MINUS3
			&& this->coinTimer == this->redCoinTimerMax)
			this->coins.erase(this->coins.begin() + i);
		if (this->player1.getPlayer().getGlobalBounds().intersects(this->coins[i].getCoin().getGlobalBounds()))
		{
			switch (this->coins[i].getType())
			{
			case CoinType::DEFAULT:
				this->gainPoints(1, 1);
				break ;
			case CoinType::POINTS5:
				this->gainPoints(5, 1);
				break ;
			case CoinType::MINUS3:
				this->gainPoints(-3, 1);
				break ;
			}
			this->coins.erase(this->coins.begin() + i);
		}
		if (this->player2.getPlayer().getGlobalBounds().intersects(this->coins[i].getCoin().getGlobalBounds()))
		{
			switch (this->coins[i].getType())
			{
			case CoinType::DEFAULT:
				this->gainPoints(1, 2);
				break ;
			case CoinType::POINTS5:
				this->gainPoints(5, 2);
				break ;
			case CoinType::MINUS3:
				this->gainPoints(-3, 2);
				break ;
			}
			this->coins.erase(this->coins.begin() + i);
		}
	}
}

void Game::updateText()
{
	std::stringstream ss;
	std::stringstream ss2;
	ss << "Player 1 points: " << this->getPlayer1Points() << "\n";
	this->txt.setString(ss.str());
	ss2 << "Player 2 points: " << this->getPlayer2Points() << "\n";
	this->txt2.setString(ss2.str());
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
	if (this->getPlayer1Points() >= 150)
		window->close();
	else if (this->getPlayer2Points() >= 150)
		window->close();
}

void Game::renderText(sf::RenderTarget &target)
{
	target.draw(this->txt);
	target.draw(this->txt2);
}

void Game::renderPlatforms(sf::RenderTarget &target)
{
  target.draw(this->rec1);
  target.draw(this->rec2);
  target.draw(this->rec3);
}

void Game::render()
{
	this->window->clear();
	for (auto i : this->coins)
	{
		i.render(*this->window);
	}
  this->renderPlatforms(*this->window);
	this->player1.render(*this->window);
	this->player2.render(*this->window);
	this->renderText(*this->window);
	this->window->display();
}