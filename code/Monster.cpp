#include "Monster.h"

void Monster::set_power(int power)
{
	this->power = power;
}

int Monster::get_power() const
{
	return power;
}

void Monster::set_defense(int def)
{
	this->defense = def;
}

int Monster::get_defense() const
{
	return defense;
}

void Monster::death_check()
{
	if (defense <= 0)
	{
		/*destroy monster */
	}
}
