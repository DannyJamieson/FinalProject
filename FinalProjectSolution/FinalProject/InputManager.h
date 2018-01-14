#pragma once
#include "BaseUpdateBehaviour.h"
#include "SFML\Graphics.hpp"
class InputManager :BaseUpdateBehaviour
{
public:
	InputManager();
	~InputManager();
	bool upPressed;
	bool downPressed;
	bool leftPressed;
	bool rightPressed;
	void Update() override;
private:
	sf::Keyboard::Key up;
	sf::Keyboard::Key down;
	sf::Keyboard::Key left;
	sf::Keyboard::Key right;
};

