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

	rect1Speed = 100.f; 
	rect2Speed = 200.f;

	cir1.setFillColor(sf::Color::Blue);
	cir1.setRadius(12.5);
	cir1.setPosition(50, 50);

	cir1Speed.x = 150;
	cir1Speed.y = 50;
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
		rect2.move(0, dt * -rect2Speed);
	}
	else if (input->isKeyDown(sf::Keyboard::A) && rect2.getPosition().x > 0)
	{
		rect2.move(dt * -rect2Speed, 0);
	}
	else if (input->isKeyDown(sf::Keyboard::S) && rect2.getPosition().y < window->getSize().y - rect2.getSize().y)
	{
		rect2.move(0, dt * rect2Speed); //Move Rect2 Down
	}
	else if (input->isKeyDown(sf::Keyboard::D) && rect2.getPosition().x < window->getSize().x - rect2.getSize().x)
	{
		rect2.move(dt * rect2Speed, 0); //Move Rect2 Right
	}
}

// Update game objects
void Level::update(float dt)
{
	//Rectangle 1
	if (rect1.getPosition().x <= 0) // if past left window edge
	{
		rect1Speed = abs(rect1Speed);
	}
	else if(rect1.getPosition().x >= window->getSize().x - rect1.getSize().x) // if past right window edge
	{
		rect1Speed = -abs(rect1Speed);
	}

	rect1.move(dt * rect1Speed, 0);

	//Circle 1
	if (cir1.getPosition().x <= 0) //if past left edge 
	{
		cir1Speed.x = abs(cir1Speed.x);
	}
	else if (cir1.getPosition().x >= window->getSize().x - (cir1.getRadius()*2)) //if past right edge
	{
		cir1Speed.x = -abs(cir1Speed.x);
	}

	if (cir1.getPosition().y <= 0) //if past top edge 
	{
		cir1Speed.y = abs(cir1Speed.y);
	}
	else if (cir1.getPosition().y >= window->getSize().y - (cir1.getRadius()*2)) //if past bottom edge
	{
		cir1Speed.y = -abs(cir1Speed.y);
	}

	cir1.move(dt * cir1Speed.x, dt * cir1Speed.y);

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(rect1);
	window->draw(rect2);
	window->draw(cir1);

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