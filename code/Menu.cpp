#include "Menu.h"
#include "Button.h"

Menu::Menu(float _width, float _height, Font& _fontTitle, Font& _fontMenu)
	: btnMenuStart("START", Color::White, _fontMenu), btnMenuExit("EXIT", Color::White, _fontMenu)
{
	Vector2f resolution(1920, 1080);
	
	txt_gameTitle.setFont(_fontTitle);
	txt_gameTitle.setFillColor(Color::White);
	txt_gameTitle.setCharacterSize(120);
	txt_gameTitle.setString("Card Battler Deluxe III Jr.");
	txt_gameTitle.setOrigin(txt_gameTitle.getLocalBounds().left + txt_gameTitle.getLocalBounds().width / 2, txt_gameTitle.getLocalBounds().top + txt_gameTitle.getLocalBounds().height / 2);
	txt_gameTitle.setPosition(resolution.x / 2.0f, resolution.y / 3.0f);

	//BUTTONS
	btnMenuStart.set_position({ resolution.x / 2.0f, resolution.y / 2.0f });
	btnMenuExit.set_position({ resolution.x / 2.0f, resolution.y / 2.0f + resolution.y * 0.05f });
}

void Menu::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(txt_gameTitle, states);
	target.draw(btnMenuStart, states);
	target.draw(btnMenuExit, states);
}