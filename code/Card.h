#pragma once
#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card
{
public:
	void set_name(string _name);
	string get_name() const;

protected:
	string name;
	//sprite_stuff?
};

#endif