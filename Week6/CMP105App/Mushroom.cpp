#include "Mushroom.h"
#include <iostream>

Mushroom::Mushroom()
{
	window = nullptr;
	float scale = 200;
	gravity = sf::Vector2f(0, 9.8) * scale;
	jumping = false;
	doublejump = false;
}

Mushroom::~Mushroom()
{

}

void Mushroom::handleInput(float dt)
{
	//jump/double jump
	if (input->isKeyDown(sf::Keyboard::Up) && jumping == false)
	{
		stepVelocity = sf::Vector2f(0, -1000);
		jumping = true;
	}
	if (!input->isKeyDown(sf::Keyboard::Up) && jumping == true && doublejump == false)
	{
		jumping = false;
		doublejump = true;
	}

	if (input->isMouseLDown())
	{
		setPosition(sf::Vector2f(input->getMouseX() - (getSize().x / 2), input->getMouseY() - (getSize().y / 2)));
		stepVelocity = sf::Vector2f(0, 0);
	}
}

void Mushroom::update(float dt)
{
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt;
	stepVelocity += gravity * dt;
	setPosition(getPosition() + pos);

	sf::Vector2u windowSize = window->getSize();
	if (getPosition().y >= (windowSize.y-getSize().y))
	{
		doublejump = false;
		setPosition(getPosition().x, (windowSize.y - getSize().y));
		stepVelocity = sf::Vector2f(0, 0);
	}
}