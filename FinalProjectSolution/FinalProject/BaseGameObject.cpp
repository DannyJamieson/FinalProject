#include "BaseGameObject.h"
#include "Physics.h"

std::vector<BaseGameObject*> BaseGameObject::GameObjects;//List of GameObjects

Physics* physics = Physics::singleton;

BaseGameObject::BaseGameObject(bool doPhysics)
{
	GameObjects.push_back(this);
	if (doPhysics) {
		physics = Physics::singleton;
		bodyDef->position.Set(0, 0);
		b2BodyDef i;
		i.position.Set(0, 0);
		myBody = physics->getBody(bodyDef);
	}
}

BaseGameObject::~BaseGameObject()
{
	for (int i = 0; i < GameObjects.size(); i++) {
		if (GameObjects[i] == this) {
			GameObjects.erase(GameObjects.begin()+i);
			break;
		}
	}
	//physics->world->DestroyBody(myBody);
}

void BaseGameObject::UpdatePostition() {
	Sprite.setPosition(Position);
}

