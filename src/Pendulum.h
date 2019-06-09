#include <SFML/Graphics.hpp>
#include <math.h>
#include "Arm.h"

class Pendulum
{
public:
	Pendulum(int m, Arm *arm);
	~Pendulum();
	void update();
	const sf::CircleShape *getBody();

private:
	int mass, x, y;
	sf::CircleShape *body;
	Arm *arm;
};