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
}


PhysicsObject::~PhysicsObject()
{
}

void PhysicsObject::Update()
{
}

void PhysicsObject::Render(sf::RenderWindow * window)
{
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


