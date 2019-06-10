#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

class Pendulum
{
public:
	Pendulum(int m, float a0, int r, int x, int y);
	~Pendulum();
	void update();
	const sf::CircleShape *getBody();
	void addAngle(float da);
	void draw(sf::RenderWindow &window);

private:
	int getXPoint();
	int getYPoint();
	int mass, x, y, r;
	float va, angle;
	sf::CircleShape *body;
	sf::RectangleShape *arm;
};