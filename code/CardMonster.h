#pragma once
#include "CardBase.h"

class CardMonster : public CardBase
{
public:
	CardMonster(string _title, int _power, int _defense, string _description, Font& _fontTitle, Font& _fontData, Font& _fontDescription);
	
	int get_power() const;
	int get_defense() const;

	void death_check();

private:


};