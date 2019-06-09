#include "Main.hpp"
#include "Pendulum.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Double Pendulum", sf::Style::Close, settings);
	sf::Event event;

	Arm *a1 = new Arm(150, 0, window.getSize().x / 2, 50);
	Pendulum p1(20, a1);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		window.draw(sf::RectangleShape(*a1->getBody()));
		window.draw(sf::CircleShape(*p1.getBody()));
		window.display();
		a1->addAngle(0.1f);
		p1.update();
	}

	return 0;
}
