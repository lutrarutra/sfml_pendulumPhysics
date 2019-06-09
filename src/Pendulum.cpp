#include "Pendulum.h"
#define PI 3.14159265

Pendulum::Pendulum(int m, Arm *arm)
{
	this->mass = m;
	this->arm = arm;
	this->x = arm->getXPoint();
	this->y = arm->getYPoint();
	this->body = new sf::CircleShape(m);
	this->body->setOrigin(sf::Vector2f(this->body->getRadius(), this->body->getRadius()));
	this->body->setPosition(sf::Vector2f(x, y));
	this->body->setFillColor(sf::Color(244, 125, 66));
}

const sf::CircleShape *Pendulum::getBody()
{
	return this->body;
}

void Pendulum::update()
{
	this->x += floor(arm->getLength() * sin(arm->angle * PI / 180));
	this->y += floor(arm->getLength() * cos(arm->angle * PI / 180));
	this->body->setPosition(x, y);
}

Pendulum::~Pendulum()
{
	delete this->body;
}
