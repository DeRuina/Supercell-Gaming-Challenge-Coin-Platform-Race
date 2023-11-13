#include "Coins.hpp"

void Coins::initCoin()
{
  this->coin.setRadius(30.f);
  sf::Color yellow(255,255,0);
  this->coin.setFillColor(yellow);
}

Coins::Coins()
{
  this->initCoin();
}

Coins::~Coins()
{
}

void Coins::update()
{
}

void Coins::render(sf::RenderTarget &target)
{
  target.draw(this->coin);
}
