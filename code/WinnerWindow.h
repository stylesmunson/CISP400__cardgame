#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class WinnerWindow : public Drawable, public Transformable
{
public:
	WinnerWindow(float _width, float _height, Font& _winnerFont)
	{
		m_windowShape1.setSize({ _width - 400.0f, _height - 400.0f });
		m_windowShape1.setOrigin(m_windowShape1.getLocalBounds().left + m_windowShape1.getLocalBounds().width / 2,
			m_windowShape1.getLocalBounds().top + m_windowShape1.getLocalBounds().height / 2);
		m_windowShape1.setPosition(200, 200);
		m_windowShape1.setFillColor(Color::White);
		m_windowShape1.setOutlineColor(Color::Red);
		m_windowShape1.setOutlineThickness(2);

		m_winnerText.setCharacterSize(50);
		m_winnerText.setFillColor(Color::Black);
		m_winnerText.setFont(_winnerFont);
		m_windowShape1.setOrigin(m_winnerText.getLocalBounds().left + m_winnerText.getLocalBounds().width / 2,
			m_winnerText.getLocalBounds().top + m_winnerText.getLocalBounds().height / 2);
		m_winnerText.setPosition(_width / 2 - 200, _height / 2 - 100);
	}

	void display_winner_window(string _winner)
	{
		if (_winner == "P1 WIN")
		{
			m_winnerText.setString("P1 WINS BATTLE");
		}
		else if (_winner == "P2 WIN")
			m_winnerText.setString("P2 WINS BATTLE");
		else if (_winner == "TIE")
			m_winnerText.setString("IT WAS A TIE\n&\nYOU BOTH LOSE A LIFE TOKEN");
	}

private:
	RectangleShape m_windowShape1;
	Text m_winnerText;

	virtual void draw(RenderTarget& target, RenderStates states) const
	{
		states.transform *= getTransform();

		target.draw(m_windowShape1, states);
		target.draw(m_winnerText, states);
	}
};
