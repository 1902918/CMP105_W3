#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	rect.setSize(sf::Vector2f(50, 25));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);

	speed = 100.f; 
	dir = RIGHT;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	if (rect.getPosition().x <= 0) // if past left window edge
	{
		dir = RIGHT;
	}
	else if(rect.getPosition().x >= window->getSize().x - rect.getSize().x) // if past right window edge
	{
		dir = LEFT;
	}

	if (dir == RIGHT) //if moving right
	{
		rect.move(dt * speed, 0);
	}
	else //moving left
	{
		rect.move(dt * -speed, 0);
	}
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(rect);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}