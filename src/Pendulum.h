#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

class Pendulum
{
public:
	Pendulum(int m, float a0, int r, int x, int y);
	Pendulum(int m, float a0, int r, Pendulum *attachedPendulum);
	~Pendulum();
	void update(float dt);
	void draw(sf::RenderWindow &window);
	float angularAcceleration();

private:
	void init(int m, float a0, int r);
	const float  PI = 3.14159265358979f;
	int getXPoint();
	int getYPoint();
	int mass, x, y, r;
	float va, angle;
	Pendulum *attachedPend = nullptr;
	sf::CircleShape *body;
	sf::RectangleShape *arm;
};