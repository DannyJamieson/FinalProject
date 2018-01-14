#pragma once
#include "SFML\Graphics.hpp"
#include "Physics.h"
#include <vector>
class BaseGameObject
{
public:
	BaseGameObject();
	BaseGameObject(bool);
	~BaseGameObject();
	//!List of game objects
	static std::vector<BaseGameObject*> GameObjects;
	//!Sprite
	sf::Sprite Sprite;
	//!Position
	sf::Vector2f Position;
	static Physics *physics;
	b2Body* myBody;
	b2BodyDef* bodyDef;
	void UpdatePostition();
};

