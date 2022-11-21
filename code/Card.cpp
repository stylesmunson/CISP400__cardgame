#include "Card.h"
//#include <SFML/Graphics>

void Card::set_name(string _name)
{
	name = _name;
}

string Card::get_name() const
{
	return name;
}