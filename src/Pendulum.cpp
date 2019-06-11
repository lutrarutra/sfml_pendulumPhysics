#include "Pendulum.h"

#define LOG(x) std::cout << x << std::endl

void Pendulum::init(int m, float a0, int r)
{
	this->va = 0;
	this->mass = m;
	this->r = r;
	this->angle = a0 * PI / 180;
	this->va = 0;

	this->arm = new sf::RectangleShape(sf::Vector2f(5, r));
	this->arm->setOrigin(this->arm->getSize().x / 2, 0);
	this->arm->setPosition(sf::Vector2f(this->x, this->y));
	this->arm->setFillColor(sf::Color::Black);
	this->arm->setRotation(angle * 180 / PI);

	this->body = new sf::CircleShape(floor(m / 10));
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

Pendulum::Pendulum(int m, float a0, int r, Pendulum *attachedPendulum)
{
	//x and y position is arm's attachment point to other pendulum
	this->x = attachedPend->getXPoint();
	this->y = attachedPend->getXPoint();
	init(m, a0, r);
}

void Pendulum::draw(sf::RenderWindow &window)
{
	window.draw(sf::RectangleShape(*this->arm));
	window.draw(sf::CircleShape(*this->body));
}

int Pendulum::getXPoint()
{
	return arm->getPosition().x - r * sin(angle);
}

int Pendulum::getYPoint()
{
	return arm->getPosition().y + r * cos(angle);
}

float Pendulum::angularAcceleration()
{
	return (mass * 9.81 * cos(PI / 2 - angle)) / r;
}

void Pendulum::update(float dt)
{
	this->va += angularAcceleration() * dt;
	this->angle -= va * dt + 0.5f * angularAcceleration() * dt * dt;
	this->arm->setRotation(angle * 180 / PI);
	if (attachedPend != nullptr)
	{
		this->x = attachedPend->getXPoint();
		this->y = attachedPend->getYPoint();
		this->arm->setPosition(x, y);
	}
	this->body->setPosition(getXPoint(), getYPoint());
}

Pendulum::~Pendulum()
{
	delete this->body;
	delete this->arm;
}
