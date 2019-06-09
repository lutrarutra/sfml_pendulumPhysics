#include <SFML/Graphics.hpp>

class Arm
{
public:
	Arm(int r, float angle, int x, int y);
	~Arm();
	int getLength();
	sf::RectangleShape *getBody();
	int getXPoint();
	int getYPoint();
	void addAngle(float angle);

	float angle;
private:
	sf::RectangleShape *body;
	int r;
};