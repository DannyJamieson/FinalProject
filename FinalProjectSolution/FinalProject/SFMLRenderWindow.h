#pragma once
#include "BaseUpdateBehaviour.h"
#include "BaseGameObject.h"
#include "SFML\Graphics.hpp"
class SFMLRenderWindow : public BaseUpdateBehaviour
{
public:
	SFMLRenderWindow();
	~SFMLRenderWindow();
	//static SFMLRenderWindow* instance;
	void Update() override;
	void DrawGameObjects();
	void DrawBackground();
	sf::RenderWindow *window;
};

