#pragma once
#include <vector>
class BaseGameObject
{
public:
	struct Vector2
	{
		float x;
		float y;
	};
	BaseGameObject();
	~BaseGameObject();
	static std::vector<BaseGameObject*> GameObjects;
	//!Sprite
	//SFML Sprite
	//!Position
	Vector2 Position;

	void SendDataThroughNetwork();


};

