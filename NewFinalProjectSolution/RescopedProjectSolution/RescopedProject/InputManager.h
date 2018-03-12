#pragma once
#include "SFML\Graphics.hpp"
class InputManager
{
public:
	InputManager* instance;
	InputManager();
	~InputManager();
	void Update();
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
};

