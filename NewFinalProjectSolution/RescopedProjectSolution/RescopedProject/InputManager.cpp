#include "InputManager.h"



InputManager::InputManager()
{
	if (instance == nullptr)
		instance = this;
	else
		delete(this);
}


InputManager::~InputManager()
{
}

void InputManager::Update(){
	UpdateInputs();
}

void InputManager::UpdateInputs() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !upPressed) {
		UpPressed();
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && upPressed) {
		UpReleased();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !downPressed) {
		DownPressed();
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && downPressed) {
		DownReleased();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !leftPressed) {
		LeftPressed();
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && leftPressed) {
		LeftReleased();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !rightPressed) {
		RightPressed();
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && rightPressed){
		RightReleased();
	}
}

#pragma region Pressed and Release Functions
void InputManager::UpPressed(){
	upPressed = true;
	std::printf("Up Pressed\n");
}
void InputManager::UpReleased() {
	upPressed = false;
	std::printf("Up Released\n");
}

void InputManager::DownPressed() {
	downPressed = true;
	std::printf("Down Pressed\n");
}
void InputManager::DownReleased() {
	downPressed = false;
	std::printf("Down Released\n");
}

void InputManager::LeftPressed() {
	leftPressed = true;
	std::printf("Left Pressed\n");
}
void InputManager::LeftReleased() {
	leftPressed = false;
	std::printf("Left Released\n");
}

void InputManager::RightPressed() {
	rightPressed = true;
	std::printf("Right Pressed\n");
}
void InputManager::RightReleased() {
	rightPressed = false;
	std::printf("Right Released\n");
}
#pragma endregion

