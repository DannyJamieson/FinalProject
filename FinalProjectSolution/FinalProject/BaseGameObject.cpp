#include "BaseGameObject.h"

std::vector<BaseGameObject*> BaseGameObject::GameObjects;//List of GameObjects

BaseGameObject::BaseGameObject()
{
	GameObjects.push_back(this);
	
}


BaseGameObject::~BaseGameObject()
{
	for (int i = 0; i < GameObjects.size(); i++) {
		if (GameObjects[i] == this) {
			GameObjects.erase(GameObjects.begin()+i);
			break;
		}
	}
}

void BaseGameObject::SendDataThroughNetwork(){}
