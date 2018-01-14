#include "CharacterControl.h"



CharacterControl::CharacterControl(bool doPhysics)
{
	BaseGameObject(doPhysics);
}


CharacterControl::~CharacterControl()
{
}

void CharacterControl::FixedUpdate() {
	if (input->leftPressed) {
		if (myBody->GetInertia() > -maxHorisontalVelocity) {
			myBody->ApplyForceToCenter(-horisontalForce,true);
		}
	}
	else if (input->rightPressed){
		if (myBody->GetInertia() < maxHorisontalVelocity) {
			myBody->ApplyForceToCenter(horisontalForce, true);
		}
	}
	if (input->upPressed) {
		if (myBody->GetLinearVelocity.y == 0) {
			myBody->ApplyForceToCenter(jumpForce, true);
		}
	}
}
