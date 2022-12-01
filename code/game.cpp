#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <deque>
#include "TextureHolder.h"
#include "CardBase.h"
#include "CardMonster.h"
#include "CardItem.h"
#include "GameFontsLoader.h"
#include "game.h"
#include "Menu.h"

using namespace sf;
using namespace std;

int main()
{
	/*****************************/
	/********** [SETUP] **********/
	/*****************************/

	//display setup
	Vector2f resolution(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height);
	RenderWindow window(VideoMode(resolution.x, resolution.y), "Card Battler Deluxe III Jr.", Style::Default);
	View mainView(FloatRect(0, 0, resolution.x, resolution.y));
	View HUDview(FloatRect(0, 0, resolution.x, resolution.y));

	Event event;
	Vector2f mousePosFloat;
	srand(time(0));

	enum class GameScreen {	MAINMENU, LOADING, PLAYING, GAMEOVER };
	enum class PlayState {	NOTPLAYING, PAUSE, GAME_BEGIN, BATTLE_PHASE,
							PLAYER1_MONSTERPHASE, PLAYER1_ITEMPHASE,
							PLAYER2_MONSTERPHASE, PLAYER2_ITEMPHASE };
	GameScreen gamescreen;
	PlayState playstate;

	TextureHolder holder;
	GameFonts fonts;

	deque<CardBase*> deck;
	vector<CardBase*> player1hand;
	vector<CardBase*> player2hand;

	//CARDS
	deck.emplace_back(new CardMonster("Gary the Vampire", 3, 3, "He used to be Gary the Accountant. Still good at math, just needs blood to survive.", "res/graphics/temp.png", fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription));
	deck.emplace_back(new CardMonster("Monster Truck", 6, 2, "The truck is alive...  and it's hungry.", "res/graphics/monstertruck1.png", fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription));
	deck.emplace_back(new CardMonster("Skeleton Lawyer", 3, 1, "Brittle, but vicious in the courtroom", "res/graphics/temp.png", fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription));
	deck.emplace_back(new CardMonster("Angry Mom", 10, 5, "She's already said your full name twice. You're in for it now.", "res/graphics/temp.png", fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription));
	deck.emplace_back(new CardMonster("Coffee Cup", 2, 1, "Stronger than glass, but will still break if it falls off a table, probably. Hot !", "res/graphics/temp.png", fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription));
	deck.emplace_back(new CardMonster("Playwright", 3, 6, "Thick skin. Has definitely heard it all before.", "res/graphics/temp.png", fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription));
	deck.emplace_back(new CardMonster("Volcano (Nice)", 2, 8, "Pretty sleepy. Watch out for his twin.", "res/graphics/temp.png", fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription));
	deck.emplace_back(new CardMonster("Volcano (Evil)", 8, 5, "Hot-headed. Sorry.", "res/graphics/temp.png", fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription));
	deck.emplace_back(new CardMonster("Rat Pit", 4, 6, "A pit full of rats. Not advised to get in.", "res/graphics/temp.png", fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription));
	deck.emplace_back(new CardMonster("Sandwich", 5, 5, "Has mayo. If we had better mechanics you might be weak to it.", "res/graphics/temp.png", fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription));
	deck.emplace_back(new CardMonster("Hardcore Show Pit", 4, 8, "Nicest people you could meet, but will still mess you up.", "res/graphics/temp.png", fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription));
	deck.emplace_back(new CardMonster("Train Conductor", 7, 4, "This guy steers the train. It could go anywhere, but he keeps it on the tracks.", "res/graphics/temp.png", fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription));
	deck.emplace_back(new CardMonster("Baby", 1, 1, "Will never amount to anything unless it grows up.", "res/graphics/temp.png", fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription));
	deck.emplace_back(new CardMonster("Goblin Drummer", 2, 2, "How does she reach the kick pedal?", "res/graphics/temp.png", fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription));
	deck.emplace_back(new CardMonster("Cool Sun", 9, 9, "Nearly unstoppabe...", "res/graphics/temp.png", fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription));
	deck.emplace_back(new CardMonster("Wizard on Vacation", 2, 2, "Likely not paying attention.", "res/graphics/temp.png", fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription));
	deck.emplace_back(new CardMonster("The World (350 Years Ago)", 9, 6, "It was pretty bad back then.", "res/graphics/temp.png", fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription));
	deck.emplace_back(new CardMonster("Giant Hand", 5, 1, "Like a normal sized hand, but much bigger.", "res/graphics/temp.png", fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription));
	deck.emplace_back(new CardMonster("Dirty Dishes", 1, 3, "When are you finally gonna get around to doing these?", "res/graphics/temp.png", fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription));
	deck.emplace_back(new CardMonster("Magic Cockroach", 7, 10, "Unlikely to die. Sort of like a regular cockroach.", "res/graphics/temp.png", fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription));

	deck.emplace_back(new CardItem("Puppy", "DEF", 2, "She's here to lend a helping paw.", "res/graphics/temp.png", fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription));

	gamescreen = GameScreen::MAINMENU;
	playstate = PlayState::NOTPLAYING;

	Menu menu(resolution.x, resolution.y, fonts.fontCardTitle, fonts.fontCardData);


	/*********************************/
	/********** [GAME LOOP] **********/
	/*********************************/
	while (window.isOpen())
	{
		/********** [-MAIN MENU-] **********/
		if (gamescreen == GameScreen::MAINMENU)
		{
			mousePosFloat = static_cast<Vector2f>(Mouse::getPosition(window));			//get mouse coords

			//START -> mouseover
			//if (txt_menuStart.getGlobalBounds().contains(mousePosFloat))
			//{
			//	txt_menuStart.setStyle(2);
			//	if (Mouse::isButtonPressed(Mouse::Left))
			//	{
			//		gamescreen = GameScreen::PLAYING;
			//		playstate = PlayState::GAME_BEGIN;
			//		txt_menuStart;
			//	}
			//}
			//else
			//	txt_menuStart.setStyle(0);

			//EXIT -> mouseover
			//if (txt_menuExit.getGlobalBounds().contains(mousePosFloat))
			//{
			//	txt_menuExit.setStyle(2);
			//	if (Mouse::isButtonPressed(Mouse::Left))
			//		window.close();
			//}
			//else
			//	txt_menuExit.setStyle(0);

		}
		
		///********** [-PLAYING-] **********/
		//if (gamescreen == GameScreen::PLAYING)
		//{

			/********** [--GAME BEGIN--] **********/
			if (playstate == PlayState::GAME_BEGIN)
			{
				random_shuffle(deck.begin(), deck.end());		//shuffle deck

				for (int i = 0; i < 4; i++)						//draw 4 cards to player1hand 
				{
					player1hand.push_back(deck.front());
					deck.pop_front();
					//card drawing animation to player 1
				}
				cout << "player 1 draws 4 cards" << endl;		//print (debug)

				for (int i = 0; i < 4; i++)						//draw 4 cards to player2hand
				{
					player2hand.push_back(deck.front());
					deck.pop_front();
					//card drawing animation to player 2
				}
				cout << "player 2 draws 4 cards" << endl;		//print (debug)

				playstate == PlayState::PLAYER1_MONSTERPHASE;
			}

			/********** [--PLAYER 1 MONSTER PHASE--] **********/
			if (playstate == PlayState::PLAYER1_MONSTERPHASE)
			{

			}

			/********** [--PLAYER 1 ITEM PHASE--] **********/
			if (playstate == PlayState::PLAYER1_ITEMPHASE)
			{

			}

			/********** [--PLAYER 1 ITEM PHASE--] **********/
			if (playstate == PlayState::PLAYER2_MONSTERPHASE)
			{

			}

			/********** [--PLAYER 2 ITEM PHASE--] **********/
			if (playstate == PlayState::PLAYER2_ITEMPHASE)
			{

			}

			/********** [--BATTLE PHASE--] **********/
			if (playstate == PlayState::BATTLE_PHASE)
			{

			}
		//}




		/****************************/
		/********** [DRAW] **********/
		/****************************/
		window.clear();
		window.setView(mainView);

		/********** [-MAIN MENU-] **********/
		if (gamescreen == GameScreen::MAINMENU)
		{
			menu.draw(window);
		}

		/********** [-PLAYING-] **********/
		if (gamescreen == GameScreen::PLAYING)
		{
			//window.draw(exitButton);
			//played cards (from both players)
			//deck
			//discard pile

			if (playstate == PlayState::GAME_BEGIN)
			{

			}

			if (playstate == PlayState::PAUSE)
			{

			}

			if (playstate == PlayState::PLAYER1_MONSTERPHASE)
			{

			}

			if (playstate == PlayState::PLAYER1_ITEMPHASE)
			{

			}

			if (playstate == PlayState::PLAYER2_MONSTERPHASE)
			{

			}

			if (playstate == PlayState::PLAYER2_ITEMPHASE)
			{

			}

			if (playstate == PlayState::BATTLE_PHASE)
			{

			}
		}


		window.display();

	}
	return 0;
}