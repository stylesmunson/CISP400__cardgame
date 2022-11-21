#include "CardMonster.h"

void CardMonster::set_power(int _power)
{
	this->power = _power;
}

void CardMonster::set_defense(int _def)
{
	this->defense = _def;
}

int CardMonster::get_defense() const
{
	return defense;
}

int CardMonster::get_power() const
{
	return power;
}

void CardMonster::death_check()
{
	if (defense <= 0)
	{
		/*destroy monster */
	}
}
