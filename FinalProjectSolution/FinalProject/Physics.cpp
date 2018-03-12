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

	Physics::CreateWorld();
}


Physics::~Physics()
{ 
}

void Physics::CreateWorld() {
	gravity = b2Vec2(0, -1);
	world = b2World(gravity);
}

b2Body* Physics::getBody(b2BodyDef *bodyDef) {
	//bodyDef->type = b2BodyType::b2_dynamicBody;
	b2Body* body = Physics::singleton->world.CreateBody(bodyDef);
	
	b2PolygonShape dynamicBox;
	
	dynamicBox.SetAsBox(10.0f, 1.0f);
	
	b2FixtureDef *fixtureDef = new b2FixtureDef();
	fixtureDef->shape = &dynamicBox;
	fixtureDef->density = 0.0f;
	fixtureDef->friction = 0.3f;
	const b2FixtureDef *fix =new  b2FixtureDef(*fixtureDef);
//	body->CreateFixture(&dynamicBox, 0);
	//body->CreateFixture(fix);
	int i = 0;
	try {
		return body;
	}
	catch(const std::exception&){
		std::printf("Body Error\n");
	}
	return NULL;
}
