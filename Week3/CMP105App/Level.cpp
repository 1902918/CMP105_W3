#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	rect1.setSize(sf::Vector2f(50, 25));
	rect1.setPosition(100, 100);
	rect1.setFillColor(sf::Color::Red);

	rect2.setSize(sf::Vector2f(25, 25));
	rect2.setPosition(200, 150);
	rect2.setFillColor(sf::Color::Green);

	rect1speed = 100.f; 
	rect2speed = 200.f;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	//Rectangle 2
	if (input->isKeyDown(sf::Keyboard::W) && rect2.getPosition().y > 0)
	{
		rect2.move(0, dt * -rect2speed);
	}
	else if (input->isKeyDown(sf::Keyboard::A) && rect2.getPosition().x > 0)
	{
		rect2.move(dt * -rect2speed, 0);
	}
	else if (input->isKeyDown(sf::Keyboard::S) && rect2.getPosition().y < window->getSize().y - rect2.getSize().y)
	{
		rect2.move(0, dt * rect2speed); //Move Rect2 Down
	}
	else if (input->isKeyDown(sf::Keyboard::D) && rect2.getPosition().x < window->getSize().x - rect2.getSize().x)
	{
		rect2.move(dt * rect2speed, 0); //Move Rect2 Right
	}
}

// Update game objects
void Level::update(float dt)
{
	//Rectangle 1
	if (rect1.getPosition().x <= 0) // if past left window edge
	{
		rect1speed = abs(rect1speed);
	}
	else if(rect1.getPosition().x >= window->getSize().x - rect1.getSize().x) // if past right window edge
	{
		rect1speed = -abs(rect1speed);
	}

	rect1.move(dt * rect1speed, 0);

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(rect1);
	window->draw(rect2);

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