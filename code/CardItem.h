#pragma once
#include "CardBase.h"

class CardItem : public CardBase
{
public:
	CardItem() {}
	CardItem(string _title, string _effect, int _effectVal, string _description, string _textureFile, Font& _fontTitle, Font& _fontEffect, Font& _fontDescription);
	
	//string get_title() const {}

private:
};
