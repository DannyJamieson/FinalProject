#include "Physics.h"

Physics* Physics::singleton;

Physics::Physics() : world(gravity)
{
	if (singleton == NULL) {
		singleton = this;
	}
	else {
		delete(this);
	}

	CreateWorld();
}


Physics::~Physics()
{ 
}

void Physics::CreateWorld() {

	world = b2World(gravity);


}

b2Body* Physics::getBody(b2BodyDef *bodyDef) {
	//bodyDef->type = b2BodyType::;
	//const b2BodyDef *i = new b2BodyDef();
	//return world->CreateBody(i);
	return NULL;
}
