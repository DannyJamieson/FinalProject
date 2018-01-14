#include <ctime>
#include "SFMLRenderWindow.h"
#include "Physics.h"

bool doPhysics = true;

short fixedUpdatesPerSecond = 50;//Updates per seconds

short  fixedUpdateSpeed = 1000/fixedUpdatesPerSecond;//time between FixedUpdates

void CallFixedUpdate() { //Call all fixed updates
	for each(BaseUpdateBehaviour* Behaviour in BaseUpdateBehaviour::UpdateBehaviours) {
		Behaviour->FixedUpdate();
	} 
}

void CallUpdate() {  //call all updates
	for each(BaseUpdateBehaviour* Behaviour in BaseUpdateBehaviour::UpdateBehaviours) {
		Behaviour->Update();
	}
}

void MainGameLoop() {
	double lastFixedUpdate = clock();
	
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
	Physics *physics = new Physics();
	SFMLRenderWindow *renderWindow = new SFMLRenderWindow();

}


int main() {
	Init();
	MainGameLoop();
	return 0;
}
