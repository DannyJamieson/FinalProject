#include "BaseGameObject.h"

std::vector<BaseGameObject*> BaseGameObject::GameObjects;//List of GameObjects

BaseGameObject::BaseGameObject(){
}

BaseGameObject::BaseGameObject(bool doPhysics, b2BodyDef *bodyDef)
{
	
	GameObjects.push_back(this);
	if (doPhysics) {
		physics = Physics::singleton;
		myBody = physics->getBody(bodyDef);
		this->Sprite;
		sf::CircleShape i = sf::CircleShape(Sprite);
		i.setFillColor(sf::Color(255, 0, 0, 255));
		Sprite = sf::CircleShape(20);
//		Sprite.setRadius(20);
		Sprite.setFillColor(sf::Color(255, 255, 255, 255));
	//	Sprite = i;
	}
	
}

BaseGameObject::~BaseGameObject()
{
	for (size_t i = 0; i < GameObjects.size(); i++) {
		if (GameObjects[i] == this) {
			GameObjects.erase(GameObjects.begin()+i);
			break;
		}
	}
	physics->world.DestroyBody(myBody);
}

void BaseGameObject::UpdatePostition() {
	
	b2Vec2 b2Pos = myBody->GetPosition();
	sf::Vector2f pos = sf::Vector2f(b2Pos.x,-b2Pos.y);
	Sprite.setPosition(pos);
}

