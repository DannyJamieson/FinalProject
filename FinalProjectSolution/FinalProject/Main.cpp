#include <ctime>
#include "BaseUpdateBehaviour.h"

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
	MainGameLoop();
	return 0;
}
