#pragma once
#include "BaseGameObject.h"
#include "BaseUpdateBehaviour.h"
#include "InputManager.h"
class CharacterControl : BaseGameObject,BaseUpdateBehaviour
{
public:
	CharacterControl();
	CharacterControl(bool);
	~CharacterControl();
	void FixedUpdate() override;
	void DoPhysics();
	//Pointer to input manager
	InputManager *input;
	//Force added per frame when nput is detected
	b2Vec2 horisontalForce = b2Vec2(1,0);
	//fore applied when jumping
	b2Vec2 jumpForce = b2Vec2(0,-1000000000);
	//maximum forisontal velocity
	float maxHorisontalVelocity;
};

