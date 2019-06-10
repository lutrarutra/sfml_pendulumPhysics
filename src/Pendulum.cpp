#include "Pendulum.h"
#define PI 3.14159265

Pendulum::Pendulum(int m, float a0, int r, int x, int y)
{
	this->va = 0;
	this->mass = m;
	this->r = r;
	this->angle = a0;

	//x and y position is arm's attachment point
	this->x =x;
	this->y = y;


	this->arm = new sf::RectangleShape(sf::Vector2f(5, r));
	this->arm->setOrigin(this->arm->getSize().x / 2, 0);
	this->arm->setPosition(sf::Vector2f(x, y));
	this->arm->setFillColor(sf::Color::Black);

	this->body = new sf::CircleShape(m);
	this->body->setOrigin(sf::Vector2f(this->body->getRadius(), this->body->getRadius()));
	this->body->setPosition(sf::Vector2f(getXPoint(), getYPoint()));
	this->body->setFillColor(sf::Color(244, 125, 66));
}

void Pendulum::draw(sf::RenderWindow &window)
{
	window.draw(sf::RectangleShape(*this->arm));
	window.draw(sf::CircleShape(*this->body));
}

void Pendulum::addAngle(float da)
{
	this->angle += da;
	this->arm->setRotation(angle);
}

int Pendulum::getXPoint()
{
	return arm->getPosition().x - r * sin(angle * PI / 180);
}

int Pendulum::getYPoint()
{
	return  arm->getPosition().y + r * cos(angle * PI / 180);
}

const sf::CircleShape *Pendulum::getBody()
{
	return this->body;
}

void Pendulum::update()
{
	this->body->setPosition(getXPoint(), getYPoint());
}

Pendulum::~Pendulum()
{
	delete this->body;
	delete this->arm;
}
