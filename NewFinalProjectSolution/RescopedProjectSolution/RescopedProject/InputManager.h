#pragma once
#include "SFML\Graphics.hpp"
#include "Client.h"
class InputManager
{
public:
	InputManager* instance;
	InputManager();
	~InputManager();
	void Update();
	void SetClientPointer(Client*);
private:
	bool upPressed;
	bool downPressed;
	bool leftPressed;
	bool rightPressed;
	void UpdateInputs();
	void UpPressed();
	void UpReleased();
	void DownPressed();
	void DownReleased();
	void LeftPressed();
	void LeftReleased();
	void RightPressed();
	void RightReleased();
	Client* clientPointer;
};

