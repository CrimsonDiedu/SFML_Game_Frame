#include "stdafx.h"
#include "BaseObject.h"


BaseObject::BaseObject()
{
}


BaseObject::~BaseObject()
{
}

sf::Vector2f BaseObject::GetPosition()
{
	return position;
}

sf::Vector2f BaseObject::GetVelocity()
{
	return velocity;
}

sf::Shape * BaseObject::GetShape()
{
	return shape;
}

void BaseObject::SetPosition(sf::Vector2f position)
{
	this->position = position;
}

void BaseObject::SetVelocity(sf::Vector2f velocity)
{
	this->velocity = velocity;
}

void BaseObject::SetShape(sf::Shape * shape)
{
	this->shape = shape;
}


