#pragma once
#include <SFML/Graphics.hpp>
#include "spells.h"

void power_boost(Monster& _monster, int _pwr)
{
	_monster.set_power(_monster.get_power() + _pwr);
}

void damage_spell(Monster* _monster, int _num)
{
	_monster->set_defense(_monster->get_defense() - _num);
	_monster->death_check();
}

void defense_boost(Monster& _monster, int _def)
{
	_monster.set_defense(_monster.get_defense() + _def);
}