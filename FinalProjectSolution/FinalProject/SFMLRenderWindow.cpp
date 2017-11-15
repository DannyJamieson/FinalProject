#include "SFMLRenderWindow.h"



SFMLRenderWindow::SFMLRenderWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(200, 200), "Game window!");
}


SFMLRenderWindow::~SFMLRenderWindow()
{
}


void SFMLRenderWindow::DrawGameObjects() {
	for each(BaseGameObject *gameObject in BaseGameObject::GameObjects) {//loop through gameobjects
		gameObject->Sprite.setPosition(gameObject->Position);
		window->draw(gameObject->Sprite);
	}
}

void SFMLRenderWindow::DrawBackground() {
	window->clear();
}

void SFMLRenderWindow::Update(){
	SFMLRenderWindow::DrawBackground();
	SFMLRenderWindow::DrawGameObjects();
	window->display();
}
