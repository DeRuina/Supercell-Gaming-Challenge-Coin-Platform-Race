#include "Coins.hpp"

void Coins::initCoin(const sf::RenderWindow &window)
{
	this->coin.setRadius(30.f);
	sf::Color yellow(255, 255, 0);
	this->coin.setFillColor(yellow);
	this->position.x = static_cast<float>(rand() % (window.getSize().x
				- static_cast<int>(this->coin.getGlobalBounds().width)));
	this->position.y = static_cast<float>(rand() % (window.getSize().y
				- static_cast<int>(this->coin.getGlobalBounds().height)));
	this->coin.setPosition(position);
	this->xVelocity = (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX
					/ 4)) - 2.f) * 1.5;
	this->yVelocity = (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX
					/ 4)) - 2.f) * 1.5;
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
	sf::FloatRect coinBounds = this->coin.getGlobalBounds();
	if (coinBounds.left <= 0.f)
		x *= -1;
	if (coinBounds.left + coinBounds.width >= 1280)
		x *= -1;
	if (coinBounds.top <= 0.f)
		y *= -1;
	if (coinBounds.top + coinBounds.height >= 720)
		y *= -1;
	this->position.x += x;
	this->position.y += y;
	this->coin.setPosition(position);
}

float &Coins::getxVelocity()
{
	return (this->xVelocity);
}

float &Coins::getyVelocity()
{
	return (this->yVelocity);
}

void Coins::update()
{
}

void Coins::render(sf::RenderTarget &target)
{
	target.draw(this->coin);
}


