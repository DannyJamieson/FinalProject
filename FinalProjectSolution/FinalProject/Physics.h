#pragma once
#include "Box2D\Box2D.h"

class Physics
{
public:
	Physics();
	~Physics();
	static Physics *singleton;
	void CreateWorld();
	b2World world;
	b2Vec2 gravity;
	b2Body* getBody(b2BodyDef*);
};

