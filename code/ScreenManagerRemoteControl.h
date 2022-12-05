#pragma once
#include <string>
#include <vector>
//#include "GameObject.h"

class ScreenManagerRemoteControl
{
public:
	virtual void switch_screens(std::string _screenToSwitchTo) = 0;
	virtual void load_level_in_play_mode(std::string _screenToLoad) = 0;
	//virtual std::vector<GameObject>& get_game_object() = 0;
	//virtual GameObjectSharer& share_GameObjectSharer() = 0;
};