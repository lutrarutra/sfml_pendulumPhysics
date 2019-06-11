#include <iostream>
#include <string>

#include "Main.hpp"
#include "Pendulum.h"

#define PI 3.14159265
#define LOG(x) std::cout << x << std::endl

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Double Pendulum", sf::Style::Close, settings);
	sf::Event event;

	Pendulum *p1 = new Pendulum(350, 95, 200, window.getSize().x / 2, 50);
	Pendulum p2(350, 15, 200, p1);

	sf::Clock clock;
	sf::Font font;

	if (!font.loadFromFile("OpenSans-Regular.ttf"))
	{
		LOG("Could not load font file..");
		return 1;
	}

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Black);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		p1->update(clock.getElapsedTime().asSeconds());

		p2.update(clock.getElapsedTime().asSeconds());
		clock.restart();

		window.clear(sf::Color::White);
		text.setString(std::to_string(p1->angularAcceleration()));
		window.draw(text);
		p1->draw(window);
		p2.draw(window);
		window.display();
	}
	delete p1;
	return 0;
}
