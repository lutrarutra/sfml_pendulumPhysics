#include "Main.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Double Pendulum", sf::Style::Close);

	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		//window.draw(shape);
		window.display();
	}

	return 0;
}
