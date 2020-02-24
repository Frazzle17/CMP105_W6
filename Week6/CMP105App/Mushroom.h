#pragma once
#include "Framework/GameObject.h"

class Mushroom:public GameObject
{
public:
	Mushroom();
	~Mushroom();

	virtual void handleInput(float dt);
	virtual void update(float dt);

	void setWindow(sf::RenderWindow* win) { window = win; };

protected:
	sf::RenderWindow* window;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	bool jumping;
	bool doublejump;
};

