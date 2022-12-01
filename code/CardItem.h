#pragma once
#include "CardBase.h"

class CardItem : public CardBase
{
public:
	CardItem(string _title, string _effect, int _effectVal, string _description, string _textureFile, Font& _fontTitle, Font& _fontEffect, Font& _fontDescription);
	
	virtual string get_title() const;

	virtual void set_position(Vector2f _pos);
	virtual Vector2f get_position() const;

private:
	Text m_cardEffect;
	string m_cardEffectStr = "";
	int m_effectVal;

	virtual void draw(RenderTarget& target, RenderStates states) const;
};
