#pragma once
#include "BaseObject.h"
#define PI 3.14195
#define RAD_TO_DEG 57.2957f
#define DEG_TO_RAD 0.01745f

class PhysicsObject :
	public BaseObject
{
	void UpdateVelocity();
	float direction, speed,mass;

	void Move();
public:
	PhysicsObject();
	~PhysicsObject();

	void OnStart();
	void OnDisable();
	void Update();
	void Render(sf::RenderWindow * window);

#pragma region Setters
	void SetDirection(float d);
	void SetSpeed(float s);
	void SetVelocity(sf::Vector2f velocity);
#pragma endregion

#pragma region Getters
	float GetDirection();
	float GetSpeed();
#pragma endregion
};

