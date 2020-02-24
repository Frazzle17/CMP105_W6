#include "Goomba.h"
#include "Framework/Vector.h"

Goomba::Goomba()
{
	window = nullptr;
	speed = 0;
	scale = 100;
}

Goomba::~Goomba()
{

}

void Goomba::handleInput(float dt)
{

}

void Goomba::update(float dt)
{
	if (Vector::magnitude(pointB - getPosition()) < 10.f)
	{
		scale = 0;
		velocity = sf::Vector2f(0,0);
		acceleration = sf::Vector2f(0, 0);
	}
	else
	{
		scale = 50;
	}
	pointA = sf::Vector2f(getPosition());
	pointB = sf::Vector2f(input->getMouseX() - getSize().x / 2, input->getMouseY() - getSize().y / 2);
	direction = pointB - pointA;
	direction = Vector::normalise(direction);
	speed = Vector::magnitude(velocity);
	velocity = direction * speed;
	acceleration = direction * scale;
	sf::Vector2f pos = velocity * dt + 0.5f * acceleration * dt * dt;
	setPosition(getPosition() + pos);
	velocity += acceleration * dt;
}