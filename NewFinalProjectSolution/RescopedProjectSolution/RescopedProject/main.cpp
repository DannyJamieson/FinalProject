#include "InputManager.h"
#include <ctime>

int deltaTime = 1000/50;//50 times per second
int main() {
	InputManager* inputManager = new InputManager();//create the input pointer
	double time = clock();//set the clock time
	while (true)
	{
		if (clock() - time > deltaTime) {//if delta time has passed
			inputManager->Update();//call update on input manager
			time += deltaTime;//update time
		}
	}
	return 0;
}