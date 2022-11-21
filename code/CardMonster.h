#pragma once
#include <SFML/Graphics.hpp>
#include "CardBase.h"

class CardMonster : public CardBase
{
public:
	void set_power(int _power);
	void set_defense(int _def);
	int get_power() const;
	int get_defense() const;

	void death_check();

private:
	int defense;
	int power;
};