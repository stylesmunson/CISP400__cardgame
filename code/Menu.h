#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

using namespace sf;

class Menu : public Drawable
{
public:
	Menu(float _width, float _height, Font& _fontTitle, Font& _fontMenu);

	Button btnMenuStart;
	Button btnMenuExit;
	
private:
	Text txt_gameTitle;

	virtual void draw(RenderTarget& target, RenderStates states) const;
};