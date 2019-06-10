#include <iostream>
#include <chrono>

#include "Main.hpp"
#include "Pendulum.h"

#define PI 3.14159265
#define LOG(x) std::cout << x << std::endl;


int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Double Pendulum", sf::Style::Close, settings);
	sf::Event event;

	Pendulum p1(20, 0, 200, window.getSize().x / 2, 50);

	auto dt = std::chrono::high_resolution_clock::now();
	auto delay = std::chrono::milliseconds(1);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if(std::chrono::high_resolution_clock::now() > dt)
		{
			dt = std::chrono::high_resolution_clock::now() + delay;

		}

		window.clear(sf::Color::White);
		p1.draw(window);
		window.display();
	}

	return 0;
}
