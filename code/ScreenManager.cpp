#include "ScreenManager.h"


ScreenManager::ScreenManager(Vector2i _res)
{
	m_ptrScreens["Game"] = unique_ptr<GameScreen>(new GameScreen(this, _res));

	m_ptrScreens["Select"] = unique_ptr<GameScreen>(new GameScreen(this, _res));
}

void ScreenManager::handle_input(RenderWindow& _window)
{
	m_ptrScreens[m_currentScreen]->handle_input(_window);
}

void ScreenManager::update(float _fps)
{
	m_ptrScreens[m_currentScreen]->update(_fps);
}

void ScreenManager::draw(RenderWindow& _window)
{
	m_ptrScreens[m_currentScreen]->draw(_window);
}