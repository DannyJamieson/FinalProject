#include "InputManager.h"

InputManager::InputManager()
{
	//Set Keycodes
	up = sf::Keyboard::W;
	down = sf::Keyboard::S;
	left = sf::Keyboard::A;
	right = sf::Keyboard::D;
	
}


InputManager::~InputManager()
{
}

void InputManager::Update(){
	//Update the pressed buttons
	upPressed = sf::Keyboard::isKeyPressed(up);
	downPressed = sf::Keyboard::isKeyPressed(down);
	leftPressed = sf::Keyboard::isKeyPressed(left);
	rightPressed = sf::Keyboard::isKeyPressed(right);
}
