#include <iostream>
#include <string>
#include <vector>

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

	Pendulum *p1 = new Pendulum(100, 90, 220, window.getSize().x / 2, 175);
	Pendulum p2(100, 90, 220, p1);

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

	std::vector<sf::Vertex> line;
	sf::Vertex *lineArr;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		line.push_back(sf::Vertex(p2.update(clock.getElapsedTime().asSeconds() * 20), sf::Color::Black));
		clock.restart();
		lineArr = &line[0];
		window.clear(sf::Color::White);
		window.draw(lineArr, line.size(), sf::Lines);
		p1->draw(window);
		p2.draw(window);
		window.display();
	}
	delete p1;
	return 0;
}
