#pragma once
#include <SFML/Graphics.hpp>
#include "ScreenManager.h"
#include "SoundEngine.h"

using namespace sf;
using std::unique_ptr;

class GameEngine
{
public:
	GameEngine();
	
	void run();

	SoundEngine m_soundEngine;

private:
	void handle_input();
	void update();
	void draw();

	unique_ptr<ScreenManager> m_ptrScreenManager;

	Clock m_clock;
	Time m_DT;
	RenderWindow m_window;
	float m_FPS = 0;
	Vector2f m_resolution;
};
