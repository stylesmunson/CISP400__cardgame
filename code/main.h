#include "Monster.h"

void power_boost(Monster& monster, int pwr)
{
	monster.set_power(monster.get_power() + pwr);
}

void damage_spell(Monster* monster, int num)
{
	monster->set_defense(monster->get_defense() - num);
	monster->death_check();
}

void defense_boost(Monster& monster, int def)
{
	monster.set_defense(monster.get_defense() + def);
}