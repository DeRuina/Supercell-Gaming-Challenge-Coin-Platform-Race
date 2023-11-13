#include "Player.hpp"

void Player::initVariables()
{
	this->moveSpeed = 10.f;
}

void Player::initShape(int i)
{
  if (i == 0)
  {
	  this->playerShape.setFillColor(sf::Color::Blue);
	  this->playerShape.setSize(sf::Vector2f(60.f, 100.f));
  }
  else
  {
    this->playerShape.setFillColor(sf::Color::Magenta);
	  this->playerShape.setSize(sf::Vector2f(60.f, 100.f));
  }
}

Player::Player(float x, float y, int i)
{
	this->playerShape.setPosition(x, y);
	this->initVariables();
	this->initShape(i);
}

Player::~Player()
{
}

sf::RectangleShape &Player::getPlayer()
{
  return(this->playerShape);
}

void Player::updateInput(int i)
{
  //Movemnt
	//left
  if (i == 0)
  {
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      this->playerShape.move(-this->moveSpeed, 0.f);
	  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      this->playerShape.move(this->moveSpeed, 0.f);
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      this->playerShape.move(0.f, -this->moveSpeed);
	  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      this->playerShape.move(0.f, this->moveSpeed);
  }
  else
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
      this->playerShape.move(-this->moveSpeed, 0.f);
	  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
      this->playerShape.move(this->moveSpeed, 0.f);
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
      this->playerShape.move(0.f, -this->moveSpeed);
	  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      this->playerShape.move(0.f, this->moveSpeed);

  }

}

void Player::updateBoundsCollision(sf::RenderTarget &target)
{
  
	if (this->playerShape.getGlobalBounds().left <= 0.f)
		this->playerShape.setPosition(0.f, this->playerShape.getGlobalBounds().top);
	if (this->playerShape.getGlobalBounds().left + this->playerShape.getGlobalBounds().width >= 1280)
		this->playerShape.setPosition(1280 - this->playerShape.getGlobalBounds().width, this->playerShape.getGlobalBounds().top);
	if (this->playerShape.getGlobalBounds().top <= 0.f)
		this->playerShape.setPosition(this->playerShape.getGlobalBounds().left, 0.f);
	if (this->playerShape.getGlobalBounds().top + this->playerShape.getGlobalBounds().height >= 720)
		this->playerShape.setPosition(this->playerShape.getGlobalBounds().left, 720 - this->playerShape.getGlobalBounds().height);
}

void Player::update(sf::RenderTarget &target, int i)
{
	this->updateInput(i);
  this->updateBoundsCollision(target);
}

void Player::render(sf::RenderTarget &target)
{
	target.draw(this->playerShape);
}

