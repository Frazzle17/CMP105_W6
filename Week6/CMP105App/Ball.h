#pragma once
#include "Framework/GameObject.h"

class Ball:public GameObject
{
public:
	Ball();
	~Ball();

	virtual void handleInput(float dt);
	virtual void update(float dt);

	void setWindow(sf::RenderWindow* win) { window = win; };

protected:
	sf::RenderWindow* window;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	bool drag;
	sf::Vector2f dragStart;
	sf::Vector2f dragEnd;
	sf::Vector2f dragTotal;
	sf::Vector2f deceleration;
};

