#pragma once
#include "CardBase.h"

class CardItem : public CardBase
{
public:
	CardItem(string _title, string _effect, int _effectVal, string _description, Texture _texture, Font& _fontTitle, Font& _fontEffect, Font& _fontDescription);

private:
	//spell effect?
};
