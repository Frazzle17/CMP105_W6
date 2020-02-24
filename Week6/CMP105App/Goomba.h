#pragma once
#include "Framework/GameObject.h"
class Goomba:public GameObject
{
public:
	Goomba();
	~Goomba();

	virtual void handleInput(float dt);
	virtual void update(float dt);

	void setWindow(sf::RenderWindow* win) { window = win; };

protected:
	sf::RenderWindow* window;
	sf::Vector2f pointA;
	sf::Vector2f pointB;
	sf::Vector2f direction;
	sf::Vector2f acceleration;
	float speed;
	float scale;
};

