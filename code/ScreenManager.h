#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "GameScreen.h"
#include "ScreenManagerRemoteControl.h"
#include "TextureHolder.h"
#include <iostream>

using namespace std;
using namespace sf;

class ScreenManager : public ScreenManagerRemoteControl
{
public:
	ScreenManager(Vector2i _res);

	void handle_input(RenderWindow& _window);
	void update(float _fps);
	void draw(RenderWindow& _window);

	//TextureHolder holder;

	/* from [IScreenManagerRemoteControl] below */
	virtual void ScreenManagerRemoteControl::switch_screens(string _screenToSwitchTo)
	{
		m_currentScreen = "" + _screenToSwitchTo;
	}

	void ScreenManagerRemoteControl::load_level_in_play_mode(string _screenToLoad)
	{
		//m_levelManager.getGameObjects().clear();
		//m_levelManager.load_game_objects_for_play_mode(_screenToLoad)
		switch_screens("Game");
	}

	//vector<GameObject>& ScreenManagerRemoteControl::get_game_objects()
	//{
	//	return m_levelManager
	//}

	//GameObjectSharer& share_GameObjectSharer()
	//{
	//	return m_levelManager;
	//}

protected:
	string m_currentScreen = "Select";

private:
	map <string, unique_ptr<Screen>> m_ptrScreens;




};