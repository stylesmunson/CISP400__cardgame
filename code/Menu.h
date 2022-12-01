#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Menu
{
public:
	Menu(float _width, float _height, Font& _fontTitle, Font& _fontMenu);
	~Menu();

	void draw(RenderWindow& _window);
private:
	Text txt_gameTitle;
	Text txt_menuStart;
	Text txt_menuExit;
};