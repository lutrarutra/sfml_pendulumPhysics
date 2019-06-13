#include "Pendulum.h"

#define LOG(x) std::cout << x << std::endl

void Pendulum::init(int m, float a0, int r)
{
	this->va = 0;
	this->mass = m;
	this->r = r;
	this->a = a0 * PI / 180;
	this->va = 0;
	this->v = 0;

	this->arm = new sf::RectangleShape(sf::Vector2f(5, r));
	this->arm->setOrigin(this->arm->getSize().x / 2, 0);
	this->arm->setPosition(sf::Vector2f(this->x, this->y));
	this->arm->setFillColor(sf::Color::Black);
	this->arm->setRotation(a * 180 / PI);

	this->body = new sf::CircleShape(25);
	this->body->setOrigin(sf::Vector2f(this->body->getRadius(), this->body->getRadius()));
	this->body->setPosition(sf::Vector2f(getXPoint(), getYPoint()));
	this->body->setFillColor(sf::Color(244, 125, 66));
}

Pendulum::Pendulum(int m, float a0, int r, int x, int y)
{
	//x and y position is arm's attachment point
	this->x = x;
	this->y = y;
	init(m, a0, r);
}

Pendulum::Pendulum(int m, float a0, int r, Pendulum *upperPendulum)
{
	this->upperPendulum = upperPendulum;
	upperPendulum->lowerPendulum = this;
	//x and y position is arm's attachment point to other pendulum
	this->x = upperPendulum->getXPoint();
	this->y = upperPendulum->getXPoint();
	init(m, a0, r);
}

void Pendulum::draw(sf::RenderWindow &window)
{
	window.draw(sf::RectangleShape(*this->arm));
	window.draw(sf::CircleShape(*this->body));
}

int Pendulum::getXPoint()
{
	return arm->getPosition().x - r * sin(a);
}

int Pendulum::getYPoint()
{
	return arm->getPosition().y + r * cos(a);
}

sf::Vector2f Pendulum::updatePos(float dt)
{
	this->v += this->va * dt;
	this->a += this->v * dt;

	if (upperPendulum != nullptr)
	{
		this->x = upperPendulum->getXPoint();
		this->y = upperPendulum->getYPoint();
	}

	this->arm->setPosition(x, y);
	this->arm->setRotation(this->a * 180 / PI);
	this->body->setPosition(this->getXPoint(), this->getYPoint());
	return sf::Vector2f(this->getXPoint(), this->getYPoint());
}

void Pendulum::update()
{
	float m1 = upperPendulum->mass;
	float m2 = this->mass;
	float a1 = upperPendulum->a;
	float a2 = this->a;
	float r1 = upperPendulum->r;
	float r2 = this->r;
	float v1 = upperPendulum->v;
	float v2 = this->v;

	float num1 = -G * (2 * m1 + m2) * sin(a1);
	float num2 = -m2 * G * sin(a1 - 2 * a2);
	float num3 = -2 * sin(a1 - a2) * m2 * (v2 * v2 * r2 + v1 * v1 * r1 * cos(a1 - a2));
	float den = r1 * (2 * m1 + m2 - m2 * cos(2 * a1 - 2 * a2));

	upperPendulum->va = (num1 + num2 + num3) / den;

	num1 = 2 * sin(a1 - a2);
	num2 = v1 * v1 * r1 * (m1 + m2);
	num3 = G * (m1 + m2) * cos(a1) + v2 * v2 * r2 * m2 * cos(a1 - a2);
	den = r2 * (2 * m1 + m2 - m2 * cos(2 * a1 - 2 * a2));
	this->va = (num1 * (num2 + num3)) / den;
}

Pendulum::~Pendulum()
{
	delete this->body;
	delete this->arm;
}
