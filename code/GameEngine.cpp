#include "GameEngine.h"

GameEngine::GameEngine()
{
	m_resolution.x = 1920;
	m_resolution.y = 1080;
	m_window.create(VideoMode(m_resolution.x, m_resolution.y), "Card Battler Deluxe III Jr.", Style::Default);

	m_ptrScreenManager = unique_ptr<ScreenManager>(new ScreenManager(Vector2i(m_resolution.x, m_resolution.y)));
}

void GameEngine::run()
{
	while (m_window.isOpen())
	{
		m_DT = m_clock.restart();
		m_FPS = m_DT.asSeconds();
		handle_input();
		update();
		draw();
	}
}

void GameEngine::handle_input()
{
	m_ptrScreenManager->handle_input(m_window);
}

void GameEngine::update()
{
	m_ptrScreenManager->update(m_FPS);
}

void GameEngine::draw()
{
	m_window.clear(Color::Black);
	m_ptrScreenManager->draw(m_window);
	m_window.display();
}