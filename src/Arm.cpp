#include "Arm.h"

Arm::Arm(int r, float angle, int x, int y)
{
	this->r = r;
	this->angle = angle;

	this->body = new sf::RectangleShape(sf::Vector2f(5, r));
	this->body->setOrigin(this->body->getSize().x / 2, 0);
	this->body->rotate(angle);
	this->body->setPosition(sf::Vector2f(x, y));
	this->body->setFillColor(sf::Color::Black);
}

int Arm::getXPoint()
{
	return body->getPosition().x;
}

int Arm::getYPoint()
{
	return  body->getPosition().y + r;
}

sf::RectangleShape* Arm::getBody()
{
	return this->body;
}

int Arm::getLength()
{
	return this->r;
}

void Arm::addAngle(float da)
{
	this->angle += da;
	this->body->setRotation(angle);
}

Arm::~Arm()
{
	delete this->body;
}