#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "CardBase.h"
#include "CardMonster.h"
#include "CardItem.h"
#include "game.h"

using namespace sf;
using namespace std;

int main()
{
	/********** [SETUP] **********/
	enum class GameState { MAINMENU, PLAYER1TURN, PLAYER2TURN, PAUSE };
	GameState gamestate = GameState::MAINMENU;

	Font fontCardTitle;
	if (!fontCardTitle.loadFromFile("res/fonts/font_NicoPaint.ttf"))
	{
		std::cout << "NO TITLE FONT FOUND \n";
		return EXIT_FAILURE;
	}
		
	Font fontCardDescription;
	if (!fontCardDescription.loadFromFile("res/fonts/font_NicoClean.ttf"))
	{
		std::cout << "NO DESCRIPTION FONT FOUND \n";
		return EXIT_FAILURE;
	}

	Font fontCardData;
	if (!fontCardData.loadFromFile("res/fonts/font_NicoBold.ttf"))
	{
		std::cout << "NO DATA FONT FOUND \n";
		return EXIT_FAILURE;
	}

	Vector2f mouseWorldPos;

	/********** [DISPLAY] **********/
	Vector2f resolution(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height);
	RenderWindow window(VideoMode(resolution.x, resolution.y), "CARD GAME TITLE", Style::Fullscreen);
	View mainView(FloatRect(0, 0, resolution.x, resolution.y));
	View HUDview(FloatRect(0, 0, resolution.x, resolution.y));


	CardMonster mon_MonsterTruck("Monster Truck", 6, 2, "The truck is alive...  and it's hungry.", fontCardTitle, fontCardData, fontCardDescription);



	/********** [GAME LOOP] **********/
	while (window.isOpen())
	{
		//if (Keyboard::isKeyPressed(Keyboard::Escape))
		//{
		//	//PAUSE & UNPAUSE
		//		//QUIT BUTTON
		//}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
			window.close();


		/********** [DRAW] **********/
		window.clear();
		window.setView(mainView);
		window.draw(mon_MonsterTruck);

		//played cards (from both players)
		//deck
		//discard pile


		window.display();

	}
	return 0;
}