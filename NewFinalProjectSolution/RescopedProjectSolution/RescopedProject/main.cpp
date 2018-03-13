#include "InputManager.h"
#include "Server.h"
#include "Client.h"
#include <ctime>
#include <thread>

int deltaTime = 1000/50;//50 times per second

void func() {
	Server *server = new Server();
	server->func();
}
int main() {
	
	system("PAUSE");
	std::thread first(func);
	//server->func();
	Client *client = new Client();
	client->Init();
	client->func();
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