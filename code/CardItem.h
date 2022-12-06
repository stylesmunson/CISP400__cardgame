#pragma once
#include "CardBase.h"

class CardItem : public CardBase
{
public:
	CardItem(string _title, string _effect, int _effectVal, string _description, string _textureFile, Font& _fontTitle, Font& _fontEffect, Font& _fontDescription);
	
	virtual string get_title() const;
	virtual FloatRect get_bounds() const;
	virtual string get_type() const;

	virtual string get_effectType() const;
	virtual int get_effectVal() const;

	virtual void set_outline_color(Color _color);
	virtual void set_position(Vector2f _pos);

	virtual bool mouse_is_over(RenderWindow& _window);

private:
	Text m_cardEffect;
	string m_cardEffectStr = "";
	string m_effectType = "";
	int m_effectVal;

	virtual void draw(RenderTarget& target, RenderStates states) const;
};
