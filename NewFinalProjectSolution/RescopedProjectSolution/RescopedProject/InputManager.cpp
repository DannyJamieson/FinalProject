#include "InputManager.h"



InputManager::InputManager()
{
	if (instance == nullptr)
		instance = this;
	else
		delete(this);
}

void InputManager::SetClientPointer(Client* client){
	clientPointer = client;
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
	std::printf("Input Manager : Up Pressed\n");
	clientPointer->AmmendMessage("Up Pressed");
}
void InputManager::UpReleased() {
	upPressed = false;
	std::printf("Input Manager : Up Released\n");
	clientPointer->AmmendMessage("Up Released");
}

void InputManager::DownPressed() {
	downPressed = true;
	std::printf("Input Manager : Down Pressed\n");
	clientPointer->AmmendMessage("Down Pressed");
}
void InputManager::DownReleased() {
	downPressed = false;
	std::printf("Input Manager : Down Released\n");
	clientPointer->AmmendMessage("Down Released");
}

void InputManager::LeftPressed() {
	leftPressed = true;
	std::printf("Input Manager : Left Pressed\n");
	clientPointer->AmmendMessage("Left Pressed");
}
void InputManager::LeftReleased() {
	leftPressed = false;
	std::printf("Input Manager : Left Released\n");
	clientPointer->AmmendMessage("Left Released");
}

void InputManager::RightPressed() {
	rightPressed = true;
	std::printf("Input Manager : Right Pressed\n");
	clientPointer->AmmendMessage("Right Pressed");
}
void InputManager::RightReleased() {
	rightPressed = false;
	std::printf("Input Manager : Right Released\n");
	clientPointer->AmmendMessage("Right Released");
}
#pragma endregion

