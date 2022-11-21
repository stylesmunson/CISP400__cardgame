#pragma once
#ifndef MONSTERCARD_H
#define MONSTERCARD_H

#include "Card.h"

class Monster : public Card
{
public:
	void set_power(int power);
	int get_power() const;
	void set_defense(int def);
	int get_defense() const;

	void death_check();

private:
	int defense;
	int power;
};

#endif