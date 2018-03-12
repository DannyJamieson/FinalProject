#include "LevelCreator.h"



LevelCreator::LevelCreator()
{
}


LevelCreator::~LevelCreator()
{
}

void LevelCreator::CreateLevel() {
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -100.0f);
	b2Body* groundBody = Physics::singleton->world.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);
	//groundBody->CreateFixture(&groundBox, 0.0f);
}


