#include "Ball.h"
#include "Framework/Vector.h"

Ball::Ball()
{
	window = nullptr;
	float scale = 200;
	gravity = sf::Vector2f(0, 9.8) * scale;
	drag = false;
	dragStart = sf::Vector2f(0, 0);
	dragEnd = sf::Vector2f(0, 0);
	deceleration = sf::Vector2f(5, 50);
}

Ball::~Ball()
{

}

void Ball::handleInput(float dt)
{
	if (input->isMouseRDown() && drag == false)
	{
		dragStart = sf::Vector2f(input->getMouseX(), input->getMouseY());
		drag = true;
	}
	if (!input->isMouseRDown() && drag == true)
	{
		dragEnd = sf::Vector2f(input->getMouseX(), input->getMouseY());
		dragTotal = dragEnd - dragStart;
		drag = false;

		stepVelocity = dragTotal * -5.f;
	}
}

void Ball::update(float dt)
{
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt;
	stepVelocity += gravity * dt;
	setPosition(getPosition() + pos);

	sf::Vector2u windowSize = window->getSize();
	if (getPosition().y >= (windowSize.y - getSize().y))
	{
		setPosition(getPosition().x, (windowSize.y - getSize().y));
		stepVelocity.y *= -1;
		stepVelocity.y += deceleration.y;
		if (stepVelocity.x > 0)
		{
			stepVelocity.x -= deceleration.x;
			if (stepVelocity.x < 0)
			{
				stepVelocity.x = 0;
			}
		}
		else if (stepVelocity.x < 0)
		{
			stepVelocity.x += deceleration.x;
			if (stepVelocity.x > 0)
			{
				stepVelocity.x = 0;
			}
		}
	}
	if (getPosition().y <= 0)
	{
		setPosition(getPosition().x, 0);
		stepVelocity.y *= -1;
		stepVelocity.y -= deceleration.y;
	}
	if (getPosition().x >= (windowSize.x - getSize().x))
	{
		setPosition((windowSize.x - getSize().x), getPosition().y);
		stepVelocity.x *= -1;
		stepVelocity.x += deceleration.x;
	}
	if (getPosition().x <= 0)
	{
		setPosition(0, getPosition().y);
		stepVelocity.x *= -1;
		stepVelocity.x -= deceleration.x;
	}
}