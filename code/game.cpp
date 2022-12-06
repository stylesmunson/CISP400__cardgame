#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

#include "game.h"
#include "SoundEngine.h"
#include "TextureHolder.h"
#include "GameFontsLoader.h"

#include "Menu.h"
#include "GameScreen.h"
#include "BattleWindow.h"

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

	Event event;
	
	srand(time(0));

	enum class GameState {	MAINMENU, PLAYING_P1, PLAYING_P2, GAMEOVER };
	enum class PlayState  {	NOTPLAYING, GAME_BEGIN, BATTLE_PHASE,
							PLAYER1_MONSTERPHASE, PLAYER1_ITEMPHASE,
							PLAYER2_MONSTERPHASE, PLAYER2_ITEMPHASE };
	GameState gamestate;
	PlayState playstate;

	TextureHolder holder;
	GameFonts fonts;

	deque<CardBase*> deck;
	vector<CardBase*> player1hand;
	vector<CardBase*> player2hand;
	vector<CardBase*> player1_battlezone;
	vector<CardBase*> player2_battlezone;
	vector<CircleShape> player1_tokens;
	vector<CircleShape> player2_tokens;

	load_cards(deck, fonts.fontCardTitle, fonts.fontCardData, fonts.fontCardDescription);
	fill_tokens(player1_tokens, player2_tokens);
	
	gamestate = GameState::MAINMENU;
	playstate = PlayState::NOTPLAYING;

	Menu menu(resolution.x, resolution.y, fonts.fontCardTitle, fonts.fontCardData);
	GameScreen gamescreen(resolution.x, resolution.y, fonts.fontCardData);
	BattleWindow battlewindow(resolution.x, resolution.y);
	
	Music music;
	music.openFromFile("res/music/Rock song 1 (done i think).wav");

	music.play();
	music.setVolume(20.f);
	music.setLoop(true);
	

	/*********************************/
	/********** [GAME LOOP] **********/
	/*********************************/
	while (window.isOpen())
	{



		/********** [-MAIN MENU-] **********/
		if (gamestate == GameState::MAINMENU)
		{
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case Event::Closed:
					window.close();

				case Event::MouseMoved:
					if (menu.btnMenuStart.mouse_is_over(window))					//start button
						menu.btnMenuStart.set_style(2);
					else if (menu.btnMenuExit.mouse_is_over(window))				//exit button
					{
						menu.btnMenuExit.set_style(2);
						if (Mouse::isButtonPressed(Mouse::Left))
							window.close();
					}
					else
					{
						menu.btnMenuStart.set_style(0);
						menu.btnMenuExit.set_style(0);
						break;
					}
				case Event::MouseButtonPressed:
					if (Mouse::isButtonPressed(Mouse::Left))
					{
						playstate = PlayState::GAME_BEGIN;
						gamestate = GameState::PLAYING_P1;
						break;
					}
				}
			}
		}
		
		/********** [-PLAYING-] **********/
		if (gamestate == GameState::PLAYING_P1)
		{
			/********** [--GAME BEGIN--] **********/
			if (playstate == PlayState::GAME_BEGIN)
			{
				random_shuffle(deck.begin(), deck.end());				//shuffle deck
				cout << "deck shuffled" << endl;						//print (debug)

				for (int i = 0; i < 4; i++)								//draw 4 cards to player1hand 
				{
					player1hand.push_back(deck.front());				//copy top card from deck to hand
					deck.pop_front();									//remove top card from deck
					//card drawing animation to player 1
				}
				cout << "player 1 draws 4 cards" << endl;				//print (debug)

				for (int i = 0; i < 4; i++)								//draw 4 cards to player2hand
				{
					player2hand.push_back(deck.front());				//copy top card from deck to hand
					deck.pop_front();									//remove top card from deck
					//card drawing animation to player 2
				}
				cout << "player 2 draws 4 cards" << endl;				//print (debug)

				playstate = PlayState::PLAYER1_MONSTERPHASE;
			}

			/********** [--PLAYER 1 MONSTER PHASE--] **********/
			if (playstate == PlayState::PLAYER1_MONSTERPHASE)
			{
				gamescreen.update_phaseText("[PLAYER 1]\n     MONSTER PHASE");
				gamescreen.display_hand(player1hand, {203, 76, 78, 170});				//update hand
				gamescreen.display_tokens(player1_tokens);								//update tokens

				while (window.pollEvent(event))
				{
					switch (event.type)
					{
					case Event::Closed:
						window.close();

					case Event::MouseMoved:
						for (int i = 0; i < player1hand.size(); i++)
						{
							if (player1hand.at(i)->get_type() == "monster")
							{
								if (player1hand.at(i)->mouse_is_over(window))
									player1hand.at(i)->set_outline_color(Color::Red);
								else
									player1hand.at(i)->set_outline_color(Color::Black);
							}
						}

					case Event::MouseButtonPressed:
						for (int i = 0; i < player1hand.size(); i++)
						{
							if (player1hand.at(i)->get_type() == "monster")
							{
								if (Mouse::isButtonPressed(Mouse::Left) && player1hand.at(i)->mouse_is_over(window))
								{
									player1_battlezone.push_back(player1hand.at(i));					//add to player1_battlezone
									player1hand.erase(player1hand.begin() + i);							//remove from hand
									playstate = PlayState::PLAYER1_ITEMPHASE;							//switch to item phase
									break;
								}
							}
						}
					}
				}
			}

			/********** [--PLAYER 1 ITEM PHASE--] **********/
			if (playstate == PlayState::PLAYER1_ITEMPHASE)
			{
				gamescreen.update_phaseText("[PLAYER 1]\n     ITEM PHASE");
				gamescreen.display_hand(player1hand, { 203, 76, 78, 170 });
				gamescreen.display_tokens(player1_tokens);
				gamescreen.display_battleZone(player1_battlezone);

				while (window.pollEvent(event))
				{
					switch (event.type)
					{
					case Event::Closed:
						window.close();

					case Event::MouseMoved:
						for (int i = 0; i < player1hand.size(); i++)
						{
							if (player1hand.at(i)->get_type() == "item")
							{
								if (player1hand.at(i)->mouse_is_over(window))
									player1hand.at(i)->set_outline_color(Color::Cyan);
								else
									player1hand.at(i)->set_outline_color(Color::Black);
							}
						}
						if (gamescreen.m_btnNext.mouse_is_over(window))
							gamescreen.m_btnNext.set_outline_size(5.0f);
						else
							gamescreen.m_btnNext.set_outline_size(2.0f);


					case Event::MouseButtonPressed:
						for (int i = 0; i < player1hand.size(); i++)
						{
							if (player1hand.at(i)->get_type() == "item")
							{
								if (Mouse::isButtonPressed(Mouse::Left) && player1hand.at(i)->mouse_is_over(window))
								{
									player1_battlezone.push_back(player1hand.at(i));					//add to player1_battlezone
									player1hand.erase(player1hand.begin() + i);							//remove from hand
									gamestate = GameState::PLAYING_P2;
									playstate = PlayState::PLAYER2_MONSTERPHASE;						//switch to player2
									break;
								}
							}
						}
						if (Mouse::isButtonPressed(Mouse::Left) && gamescreen.m_btnNext.mouse_is_over(window))
						{
							gamestate = GameState::PLAYING_P2;
							playstate = PlayState::PLAYER2_MONSTERPHASE;
							break;
						}
					}
				}
			}
		}

		if (gamestate == GameState::PLAYING_P2)
		{
			/********** [--PLAYER 2 MONSTER PHASE--] **********/
			if (playstate == PlayState::PLAYER2_MONSTERPHASE)
			{
				gamescreen.update_phaseText("[PLAYER 2]\n     MONSTER PHASE");
				gamescreen.display_hand(player2hand, { 84, 175, 190, 170 });					//update hand
				gamescreen.display_tokens(player2_tokens);										//update tokens

				while (window.pollEvent(event))
				{
					switch (event.type)
					{
					case Event::Closed:
						window.close();

					case Event::MouseMoved:
						for (int i = 0; i < player2hand.size(); i++)
						{
							if (player2hand.at(i)->get_type() == "monster")
							{
								if (player2hand.at(i)->mouse_is_over(window))
									player2hand.at(i)->set_outline_color(Color::Red);
								else
									player2hand.at(i)->set_outline_color(Color::Black);
							}
						}

					case Event::MouseButtonPressed:
						for (int i = 0; i < player2hand.size(); i++)
						{
							if (player2hand.at(i)->get_type() == "monster")
							{
								if (Mouse::isButtonPressed(Mouse::Left) && player2hand.at(i)->mouse_is_over(window))
								{
									player2_battlezone.push_back(player2hand.at(i));					//add to player2_battlezone
									player2hand.erase(player2hand.begin() + i);							//remove from hand
									playstate = PlayState::PLAYER2_ITEMPHASE;							//switch to item phase
									break;
								}
							}
						}
					}
				}
			}

			/********** [--PLAYER 2 ITEM PHASE--] **********/
			if (playstate == PlayState::PLAYER2_ITEMPHASE)
			{
				gamescreen.update_phaseText("[PLAYER 2]\n     ITEM PHASE");
				gamescreen.display_hand(player2hand, { 84, 175, 190, 170 });
				gamescreen.display_tokens(player2_tokens);
				gamescreen.display_battleZone(player2_battlezone);

				while (window.pollEvent(event))
				{
					switch (event.type)
					{
					case Event::Closed:
						window.close();

					case Event::MouseMoved:
						for (int i = 0; i < player2hand.size(); i++)
						{
							if (player2hand.at(i)->get_type() == "item")
							{
								if (player2hand.at(i)->mouse_is_over(window))
									player2hand.at(i)->set_outline_color(Color::Cyan);
								else
									player2hand.at(i)->set_outline_color(Color::Black);
							}
						}
						if (gamescreen.m_btnNext.mouse_is_over(window))
							gamescreen.m_btnNext.set_outline_size(5.0f);
						else
							gamescreen.m_btnNext.set_outline_size(2.0f);

					case Event::MouseButtonPressed:
						for (int i = 0; i < player2hand.size(); i++)
						{
							if (player2hand.at(i)->get_type() == "item")
							{
								if (Mouse::isButtonPressed(Mouse::Left) && player2hand.at(i)->mouse_is_over(window))
								{
									player2_battlezone.push_back(player2hand.at(i));					//add to player1_battlezone
									player2hand.erase(player2hand.begin() + i);							//remove from hand
									playstate = PlayState::BATTLE_PHASE;								//switch to player2
									break;
								}
							}
						}
						if (Mouse::isButtonPressed(Mouse::Left) && gamescreen.m_btnNext.mouse_is_over(window))
						{
							playstate = PlayState::BATTLE_PHASE;
							break;
						}
					}
				}
			}

			/********** [--BATTLE PHASE--] **********/
			if (playstate == PlayState::BATTLE_PHASE)
			{
				gamescreen.update_phaseText("BATTLE PHASE");
				battlewindow.display_battle_window(player1_battlezone, player2_battlezone);

				while (window.pollEvent(event))
				{
					switch (event.type)
					{
					case Event::Closed:
						window.close();

					case Event::MouseMoved:
						if (gamescreen.m_btnNext.mouse_is_over(window))
							gamescreen.m_btnNext.set_outline_size(5.0f);
						else
							gamescreen.m_btnNext.set_outline_size(2.0f);

					case Event::MouseButtonPressed:
						if (Mouse::isButtonPressed(Mouse::Left) && gamescreen.m_btnNext.mouse_is_over(window))
						{
							string winner = battlewindow.battle_math(player1_battlezone, player2_battlezone);
							if (winner == "P1 WIN")
								player2_tokens.pop_back();
							else if (winner == "P2 WIN")
								player1_tokens.pop_back();
							else if (winner == "TIE")
							{
								player1_tokens.pop_back();
								player2_tokens.pop_back();
							}
							cout << winner << endl;

							//check for game over (shoddy I know)
							if (player1_tokens.size() == 0 || player2_tokens.size() == 0)
								window.close();

							//discard battling cards
							player1_battlezone.clear();
							player2_battlezone.clear();

							//fill hands back up
							while (player1hand.size() < 4)
							{
								player1hand.push_back(deck.front());				//copy top card from deck to hand
								deck.pop_front();									//remove top card from deck
								cout << "player 1 draws card" << endl;
							}
							while (player2hand.size() < 4)
							{
								player2hand.push_back(deck.front());				//copy top card from deck to hand
								deck.pop_front();									//remove top card from deck
								cout << "player 2 draws card" << endl;
							}
							playstate = PlayState::PLAYER1_MONSTERPHASE;
							gamestate = GameState::PLAYING_P1;
							break;
						}
					}
				}
			}
		}

		/****************************/
		/********** [DRAW] **********/
		/****************************/
		window.clear();

		/********** [-MAIN MENU-] **********/
		if (gamestate == GameState::MAINMENU)
		{
			window.draw(menu);
		}

		/********** [-PLAYING-] **********/
		if (gamestate == GameState::PLAYING_P1)
		{
			window.draw(gamescreen);

			for (auto const& i : player1hand)
				window.draw(*i);
			for (auto const& i : player1_battlezone)
				window.draw(*i);
			for (auto const& i : player1_tokens)
				window.draw(i);
		}

		if (gamestate == GameState::PLAYING_P2)
		{
			window.draw(gamescreen);

			for (auto const& i : player2hand)
				window.draw(*i);
			for (auto const& i : player2_battlezone)
				window.draw(*i);
			for (auto const& i : player2_tokens)
				window.draw(i);
		}

		if (playstate == PlayState::BATTLE_PHASE)
		{
			window.draw(battlewindow);

			for (auto const& i : player1_battlezone)
				window.draw(*i);
			for (auto const& i : player2_battlezone)
				window.draw(*i);
		}

		window.display();
	}
	return 0;
}
