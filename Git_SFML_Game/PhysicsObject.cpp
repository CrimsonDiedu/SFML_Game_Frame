#include "stdafx.h"
#include "PhysicsObject.h"


void PhysicsObject::UpdateVelocity()
{
	velocity.y = (sin(direction*DEG_TO_RAD)*speed)*.01f;
	velocity.x = (cos(direction*DEG_TO_RAD)*speed)*.01f;
}

void PhysicsObject::Move()
{
	position.x += velocity.x;
	position.y += velocity.y;
}

PhysicsObject::PhysicsObject()
{
	OnStart();
}


PhysicsObject::~PhysicsObject()
{
	OnDisable();
}

void PhysicsObject::OnStart()
{
	SetPosition(sf::Vector2f(0.f, 0.f));
	SetVelocity(sf::Vector2f(0.f, 0.f));
	sf::Vector2f size(128.f, 128.f);
	shape = new sf::RectangleShape(size);
	shape->setOrigin(64, 64);
	shape->setPosition(position);
}

void PhysicsObject::OnDisable()
{
	delete shape;
}

void PhysicsObject::Update()
{
	position.x += velocity.x;
	position.y += velocity.y;

	shape->setPosition(position);

}

void PhysicsObject::Render(sf::RenderWindow * window)
{
	if(shape != nullptr)
		window->draw(*shape);
}

float PhysicsObject::GetDirection()
{
	return direction;
}
float PhysicsObject::GetSpeed() {
	return speed;
}

void PhysicsObject::SetDirection(float d)
{
	direction = d;
	UpdateVelocity();
}
void PhysicsObject::SetSpeed(float s)
{
	speed = s;
	UpdateVelocity();
}

void PhysicsObject::SetVelocity(sf::Vector2f velocity)
{
	//BaseObject::SetVelocity(velocity);

	direction = asin(velocity.y / speed);
	speed = velocity.y / sin(direction);
}


