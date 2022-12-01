#include "Menu.h"

Menu::Menu(float _width, float _height, Font& _fontTitle, Font& _fontMenu)
{
	Vector2f resolution(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height);

	txt_gameTitle.setFont(_fontTitle);
	txt_gameTitle.setFillColor(Color::White);
	txt_gameTitle.setCharacterSize(120);
	txt_gameTitle.setString("Card Battler Deluxe III Jr.");
	txt_gameTitle.setOrigin(txt_gameTitle.getLocalBounds().left + txt_gameTitle.getLocalBounds().width / 2, txt_gameTitle.getLocalBounds().top + txt_gameTitle.getLocalBounds().height / 2);
	txt_gameTitle.setPosition(resolution.x / 2, resolution.y / 3);

	txt_menuStart.setFont(_fontMenu);
	txt_menuStart.setFillColor(Color::White);
	txt_menuStart.setCharacterSize(50);
	txt_menuStart.setString("START");
	txt_menuStart.setOrigin(txt_menuStart.getLocalBounds().left + txt_menuStart.getLocalBounds().width / 2, txt_menuStart.getLocalBounds().top + txt_menuStart.getLocalBounds().height / 2);
	txt_menuStart.setPosition(resolution.x / 2, resolution.y / 2);

	txt_menuExit.setFont(_fontMenu);
	txt_menuExit.setFillColor(Color::White);
	txt_menuExit.setCharacterSize(50);
	txt_menuExit.setString("EXIT");
	txt_menuExit.setOrigin(txt_menuExit.getLocalBounds().left + txt_menuExit.getLocalBounds().width / 2, txt_menuExit.getLocalBounds().top + txt_menuExit.getLocalBounds().height / 2);
	txt_menuExit.setPosition(resolution.x / 2, resolution.y / 2 + resolution.y * 0.05);
}

Menu::~Menu()
{

}

void Menu::draw(RenderWindow& _window)
{
	_window.draw(txt_gameTitle);
	_window.draw(txt_menuStart);
	_window.draw(txt_menuExit);
}