#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

class Pendulum
{
public:
	Pendulum(int m, float a0, int r, int x, int y);
	Pendulum(int m, float a0, int r, Pendulum *upperPendulum);
	~Pendulum();
	void update();
	void draw(sf::RenderWindow &window);
	void attachPendulum(Pendulum *lowerPendulum);
	sf::Vector2f updatePos(float dt);
private:
	void init(int m, float a0, int r);
	const float  PI = 3.14159265358979f;
	const float G = 9.81;
	int getXPoint();
	int getYPoint();
	int mass, x, y, r;
	//va is angular acceleration and v is angular velocity.
	float va, v, a;

	Pendulum *upperPendulum = nullptr;
	Pendulum *lowerPendulum = nullptr;
	sf::CircleShape *body;
	sf::RectangleShape *arm;
};