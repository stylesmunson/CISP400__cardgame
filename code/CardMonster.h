#pragma once
#include "CardBase.h"

class CardMonster : public CardBase
{
public:
	CardMonster(string _title, int _power, int _defense, string _description, string _textureFile, Font& _fontTitle, Font& _fontData, Font& _fontDescription);
	
	virtual string get_title() const;
	virtual FloatRect get_bounds() const;
	virtual string get_type() const;

	virtual void set_outline_color(Color _color);
	virtual void set_position(Vector2f _pos);

	virtual bool mouse_is_over(RenderWindow& _window);

	virtual int get_power() const;
	virtual int get_defense() const;

private:
	Text m_cardPWR;
	Text m_cardDEF;
	int m_PWRval;
	int m_DEFval;

	virtual void draw(RenderTarget& target, RenderStates states) const;
};