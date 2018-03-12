#include <ctime>
#include "SFMLRenderWindow.h"
#include "Physics.h"
#include "CharacterControl.h"

bool doPhysics = true;

short fixedUpdatesPerSecond = 50;//Updates per seconds

short  fixedUpdateSpeed = 1000/fixedUpdatesPerSecond;//time between FixedUpdates

void CallFixedUpdate() { //Call all fixed updates
	for each(BaseUpdateBehaviour* behaviour in BaseUpdateBehaviour::UpdateBehaviours) {
		behaviour->FixedUpdate();
	} 

	
}

void CallUpdate() {  //call all updates
	for each(BaseUpdateBehaviour* behaviour in BaseUpdateBehaviour::UpdateBehaviours) {
		try
		{
			behaviour->Update();
		}
		catch (const std::exception&)
		{
			std::printf("Update Behaviour occoured");
		}
		
	}
}

void MainGameLoop() {
	double lastFixedUpdate = clock();
	float32 timeStep = 1.0f / 60.0f;
	int32 a = 6;
	int32 b = 2;
	Physics::singleton->world.Step(timeStep,a,b);
	
	while (true)
	{
		CallUpdate();
		if(clock()-lastFixedUpdate > fixedUpdateSpeed){
			lastFixedUpdate +=fixedUpdateSpeed;
			CallFixedUpdate();
		}
	}
}

void Init() {
	CharacterControl *cc = new CharacterControl(true);
	SFMLRenderWindow *renderWindow = new SFMLRenderWindow();
	Physics *physics = new Physics();
	
	

	SFML_SLEEP_HPP(1000);
	cc->DoPhysics();





	BaseUpdateBehaviour::UpdateBehaviours;
	b2BodyDef *groundBodyDef = new b2BodyDef();
	groundBodyDef->position.Set(0.0f, 10.0f);
	b2Body* groundBody;
	groundBody= Physics::singleton->getBody(groundBodyDef);
	b2PolygonShape *groundBox = new b2PolygonShape();
	
	groundBox->SetAsBox(5.0f, 10.0f);
	b2FixtureDef *fixtureDef = new b2FixtureDef();
	fixtureDef->density = 0;
	fixtureDef->shape = groundBox;
	groundBody->CreateFixture(fixtureDef);
	
	int i = 0;

	
	
}

void test() {
	SFMLRenderWindow *window = new SFMLRenderWindow();
	b2Vec2 gravity = b2Vec2(0, 0);
	b2World world = b2World(gravity);
	b2BodyDef bodyDef = b2BodyDef();
	bodyDef.position = gravity;
	b2Body *body = world.CreateBody(&bodyDef);
	b2FixtureDef fixtureDef = b2FixtureDef();
	b2PolygonShape groundBox;
	groundBox.SetAsBox(1, 1);
	fixtureDef.density = 0;
	fixtureDef.shape = &groundBox;
	body->CreateFixture(&fixtureDef);
	while (true) {
		window->window->clear();
		window->window->display();
	}
}


int main() {
	//test();
	Init();
	MainGameLoop();
	return 0;
}
