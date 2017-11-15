#include <ctime>
#include "SFMLRenderWindow.h"
#include "Physics.h"

bool DoPhysics = true;




short FixedUpdatesPerSecond = 50;//Updates per seconds

short  FixedUpdateSpeed = 1000/FixedUpdatesPerSecond;//time between FixedUpdates

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
	double LastFixedUpdate = clock();
	Physics *i = new Physics();
	while (true)
	{
		CallUpdate();
		if(clock()-LastFixedUpdate > FixedUpdateSpeed){
			LastFixedUpdate +=FixedUpdateSpeed;
			CallFixedUpdate();
		}
	}
}


int main() {
	SFMLRenderWindow *i = new SFMLRenderWindow();
	MainGameLoop();
	return 0;
}
