#pragma once
#include "BaseUpdateBehaviour.h"
#include "SFML\Graphics.hpp"
#include "Physics.h"
#include <vector>
#include <string>
class BaseGameObject //: BaseUpdateBehaviour
{
public:
	BaseGameObject();
	BaseGameObject(bool,b2BodyDef*);
	~BaseGameObject();
	//!List of game objects
	static std::vector<BaseGameObject*> GameObjects;
	//!Sprite
	sf::CircleShape Sprite;
	//!Position
	sf::Vector2f Position;
	//public Physics* physics;
	Physics *physics;
	b2Body* myBody;
	b2BodyDef* bodyDef;
	void UpdatePostition();
};


struct RecievedSaveData
{
	int Source;
	int DataIdentifier;
	double SourceTimeSent;
	std::string Message;
	double LocalTimeRecieved;
	double AckRecieved;
};

struct SentSaveData
{
	int Destination;
	int DataIdentifier;
	double SourceTimeSent;
	std::string Message;
};




