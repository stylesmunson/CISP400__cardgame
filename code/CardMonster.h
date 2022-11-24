#pragma once
#include <SFML/Graphics.hpp>
#include "CardBase.h"

class CardMonster : public CardBase
{
public:
	CardMonster(string _title, int _power, int _defense);
	
	void set_power(int _power);
	void set_defense(int _defense);
	int get_power() const;
	int get_defense() const;

	void death_check();

private:
	int m_PWRval;
	int m_DEFval;

	Text m_cardPWR;
	Text m_cardDEF;
	string m_cardPWRStr = "PWR ";
	string m_cardDEFStr = "DEF ";

};