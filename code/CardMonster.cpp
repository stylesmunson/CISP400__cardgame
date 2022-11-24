#include "CardMonster.h"

CardMonster::CardMonster(string _title, int _power, int _defense)
{
	m_cardTitleStr = _title;
	m_PWRval = _power;
	m_DEFval = _defense;

}

void CardMonster::set_power(int _power)
{
	m_PWRval = _power;
}

void CardMonster::set_defense(int _defense)
{
	m_DEFval = _defense;
}

int CardMonster::get_defense() const
{
	return m_DEFval;
}

int CardMonster::get_power() const
{
	return m_PWRval;
}




void CardMonster::death_check()
{
	if (m_DEFval <= 0)
	{
		/*destroy monster */
	}
}
