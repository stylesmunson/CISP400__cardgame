#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "CardBase.h"
#include "CardMonster.h"
#include "CardItem.h"
#include "Button.h"

using namespace sf;
using namespace std;

class BattleWindow : public Drawable, public Transformable	
{
public:
	BattleWindow(float _width, float _height)
	{
		m_windowShape1.setSize({ _width / 2.0f - 120.0f, _height - 200.0f });
		m_windowShape1.setPosition(50, 100);
		m_windowShape1.setFillColor(Color::White);
		m_windowShape1.setOutlineColor(Color::Red);
		m_windowShape1.setOutlineThickness(2);

		m_windowShape2.setSize({ _width / 2.0f - 120.0f, _height - 200.0f });
		m_windowShape2.setPosition(1030, 100);
		m_windowShape2.setFillColor(Color::White);
		m_windowShape2.setOutlineColor(Color::Cyan);
		m_windowShape2.setOutlineThickness(2);

		m_windowShape3.setSize({ 120 , _height - 200.0f });
		m_windowShape3.setPosition(900, 100);
		m_windowShape3.setFillColor(Color::Black);
		m_windowShape3.setOutlineColor(Color::Black);
		m_windowShape3.setOutlineThickness(2);
	}

	void display_battle_window(vector<CardBase*>& _p1battlers, vector<CardBase*>& _p2battlers)
	{
		if (_p1battlers.size() == 1)								//monster but no item
			_p1battlers.at(0)->setPosition(390, 200);
		else if (_p1battlers.size() == 2)							//monster & item
		{
			_p1battlers.at(0)->setPosition(390, 200);
			_p1battlers.at(1)->setPosition(390, 600);
		}

		if (_p2battlers.size() == 1)								//monster no item
			_p2battlers.at(0)->setPosition(1400, 200);
		else if (_p2battlers.size() == 2)							//monster & item
		{
			_p2battlers.at(0)->setPosition(1400, 200);
			_p2battlers.at(1)->setPosition(1400, 600);
		}
	}

	string battle_math(vector<CardBase*>& _p1battlers, vector<CardBase*>& _p2battlers)
	{
		int p1PWRtotal, p1DEFtotal;
		int p2PWRtotal, p2DEFtotal;

		//player 1 values
		p1PWRtotal = _p1battlers.at(0)->get_power();
		p1DEFtotal = _p1battlers.at(0)->get_defense();

		if (_p1battlers.size() == 2)
		{
			if (_p1battlers.at(1)->get_effectType() == "pwr")
				p1PWRtotal += _p1battlers.at(1)->get_effectVal();

			else if (_p1battlers.at(1)->get_effectType() == "def")
				p1DEFtotal += _p1battlers.at(1)->get_effectVal();
		}

		//player 2 values
		p2PWRtotal = _p2battlers.at(0)->get_power();
		p2DEFtotal = _p2battlers.at(0)->get_defense();

		if (_p2battlers.size() == 2)
		{
			if (_p2battlers.at(1)->get_effectType() == "PWR")
				p1PWRtotal += _p2battlers.at(1)->get_effectVal();

			else if (_p2battlers.at(1)->get_effectType() == "DEF")
				p1DEFtotal += _p2battlers.at(1)->get_effectVal();
		}

		if (p1PWRtotal >= p2DEFtotal && p2PWRtotal < p1DEFtotal)
			return "P1 WIN";

		else if (p1PWRtotal < p2DEFtotal && p2PWRtotal >= p1DEFtotal)
			return "P2 WIN";

		else if (p1PWRtotal == p2DEFtotal && p2PWRtotal == p1DEFtotal)
			return "TIE";

		else if (p1PWRtotal > p2DEFtotal && p2PWRtotal > p1DEFtotal)
			return "TIE";
	}

private:
	RectangleShape m_windowShape1;
	RectangleShape m_windowShape2;
	RectangleShape m_windowShape3;

	virtual void draw(RenderTarget& target, RenderStates states) const
	{
		states.transform *= getTransform();
		
		target.draw(m_windowShape1, states);
		target.draw(m_windowShape2, states);
		target.draw(m_windowShape3, states);

	}
};
