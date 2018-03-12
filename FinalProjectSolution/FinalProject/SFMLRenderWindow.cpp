#include "SFMLRenderWindow.h"



SFMLRenderWindow::SFMLRenderWindow()
{
	
		//instance = this;
	
	window = new sf::RenderWindow(sf::VideoMode(1000, 550), "Game window!");
	//window->setVerticalSyncEnabled(true);
}


SFMLRenderWindow::~SFMLRenderWindow()
{
}


void SFMLRenderWindow::DrawGameObjects() {
	for each(BaseGameObject *gameObject in BaseGameObject::GameObjects) {//loop through gameobjects
		gameObject->UpdatePostition();
		sf::Vector2f i = gameObject->Sprite.getOrigin();
 		window->draw(gameObject->Sprite);
		sf::CircleShape l = sf::CircleShape();
		l.setFillColor(sf::Color(255, 0, 0, 255));
		l.setPosition(i);
		l.setRadius(10);
		window->draw(l);
	}
}

void SFMLRenderWindow::DrawBackground() {
	const sf::Color colour= sf::Color(0, 0, 0, 255);
//	window->clear(sf::Color(0,0,0,255));
}

void SFMLRenderWindow::Update(){
	SFMLRenderWindow::DrawBackground();
	SFMLRenderWindow::DrawGameObjects();
	window->display();
}
