#include "CharacterControl.h"
#include <stdio.h>

CharacterControl::CharacterControl(){
}


void CharacterControl::DoPhysics(){
	
	bodyDef = new b2BodyDef();
	bodyDef->type = b2BodyType::b2_dynamicBody;
	bodyDef->position = b2Vec2(5, 10);
	BaseGameObject *gameObject = new BaseGameObject(true, bodyDef);
	//gameObject->Sprite = sf::CircleShape(30);
	//gameObject->Sprite.setFillColor(sf::Color::Red);
	myBody = gameObject->myBody;
}
CharacterControl::CharacterControl(bool doPhysics)
{
	

	input = new InputManager();
	
}

CharacterControl::~CharacterControl()
{
}

void CharacterControl::FixedUpdate() {
	if (myBody == NULL) {
		return;
	}
	b2Vec2 pos = myBody->GetLinearVelocity();
	std::printf((char)pos.x + (char)pos.y + "\n");



	if (input->leftPressed) {
		std::printf("LEFT\n");
		if (myBody != NULL) {
			if (myBody->GetInertia() > -maxHorisontalVelocity) {
				myBody->ApplyForceToCenter(-horisontalForce, true);
			}
		}
	}
	else if (input->rightPressed){
		if (myBody != NULL) {
			if (myBody->GetInertia() < maxHorisontalVelocity) {
				myBody->ApplyForceToCenter(horisontalForce, true);
			}
		}
	}
	if (input->upPressed) {
		//std::printf("Jump\n");
		//myBody->ApplyForceToCenter(jumpForce, true);
		//myBody->ApplyLinearImpulseToCenter(jumpForce, true);
		//myBody->SetLinearVelocity(jumpForce);
		
		if (myBody != NULL) {
			const b2Vec2 i = myBody->GetLinearVelocity();

			if (i.y == 0) {
				std::printf("Jump\n");
				myBody->ApplyForceToCenter(jumpForce, false);
			}
		}
	}
}
