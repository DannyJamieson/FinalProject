#include "InputManager.h"
#include "Server.h"
#include "Client.h"
#include <ctime>
#include <thread>

int deltaTime = 1000/50;//50 times per second

void StartServer() {
	Server *server = new Server();
	server->func();
}

void StartClientReciever(Client *client) {
	client->Reciever();
}

int main() {
	//std::thread server(StartServer);
	Client *client = new Client();
	client->Init();
	std::thread reciever(StartClientReciever, client);
	InputManager* inputManager = new InputManager();//create the input pointer
	inputManager->SetClientPointer(client);
	double time = clock();//set the clock time
	while (true)
	{
		if (clock() - time > deltaTime) {//if delta time has passed
			inputManager->Update();//call update on input manager
			time += deltaTime;//update time
			client->CheckNewMessage();
			if (client->CloseProgram) {
				reciever.detach();
				break;
			}
		}
	}
	return 0;
}