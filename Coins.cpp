#include "Coins.hpp"

void Coins::initCoin(const sf::RenderWindow &window)
{
	this->coin.setRadius(30.f);
	sf::Color yellow(255, 255, 0);
	this->coin.setFillColor(yellow);
	this->position.x = static_cast<float>(rand() % window.getSize().x
			- this->coin.getGlobalBounds().width);
	this->position.y = static_cast<float>(rand() % window.getSize().y
			- this->coin.getGlobalBounds().height);
	this->coin.setPosition(position);
}

Coins::Coins(const sf::RenderWindow &window)
{
	this->initCoin(window);
}

Coins::~Coins()
{
}

void Coins::setCoinPosition(float &x, float &y)
{
  // if (this->position.x < 0 || this->position.x > 1280 - this->position.x)
  //   x *= -1;
  // if (this->position.y < 0 || this->position.y > 720 - this->position.y)
  //   y *= -1;
  sf::FloatRect coinBounds = this->coin.getGlobalBounds();
  if (coinBounds.left <= 0.f)
    x *= -1;
  if (coinBounds.left + coinBounds.width >= 1280)
    x *= -1;
  if (coinBounds.top <= 0.f)
    y *= -1;
  if (coinBounds.top + coinBounds.height >=  720)
    y *= -1;

  this->position.x += x;
  this->position.y += y;
  this->coin.setPosition(position);
}

void Coins::update()
{
}

void Coins::render(sf::RenderTarget &target)
{
	target.draw(this->coin);
}
