#pragma once
class BaseObject
{
protected:
	sf::Vector2f position, velocity;
	sf::Shape * shape;

public:
	BaseObject();
	~BaseObject();

	virtual void Update() = 0;
	virtual void Render(sf::RenderWindow * window) = 0;
	virtual void OnStart() = 0;
	virtual void OnDisable() = 0;
#pragma region Getters
	sf::Vector2f GetPosition();
	sf::Vector2f GetVelocity();
	sf::Shape * GetShape();
#pragma endregion

#pragma region Setters
	virtual void SetPosition(sf::Vector2f position);
	virtual void SetVelocity(sf::Vector2f velocity);
	virtual void SetShape(sf::Shape *shape);
#pragma endregion
};

