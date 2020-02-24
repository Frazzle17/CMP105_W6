#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	mushroom.setInput(input);
	mushroom.setWindow(window);
	mushTexture.loadFromFile("gfx/MushroomTrans.png");
	mushroom.setTexture(&mushTexture);
	mushroom.setPosition(100, 100);
	mushroom.setSize(sf::Vector2f(100, 100));

	ball.setInput(input);
	ball.setWindow(window);
	ballTexture.loadFromFile("gfx/Beach_Ball.png");
	ball.setTexture(&ballTexture);
	ball.setPosition(300, 100);
	ball.setSize(sf::Vector2f(100, 100));

	goomba.setInput(input);
	goomba.setWindow(window);
	goombaTexture.loadFromFile("gfx/GoombaT.png");
	goomba.setTexture(&goombaTexture);
	goomba.setSize(sf::Vector2f(100, 100));
	goomba.setPosition(0, (window->getSize().y - goomba.getSize().y));
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	mushroom.handleInput(dt);
	ball.handleInput(dt);
	goomba.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	mushroom.update(dt);
	ball.update(dt);
	goomba.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(mushroom);
	window->draw(ball);
	window->draw(goomba);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}