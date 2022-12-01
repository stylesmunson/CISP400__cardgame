#pragma once
#include "CardBase.h"

class CardMonster : public CardBase
{
public:
	CardMonster(string _title, int _power, int _defense, string _description, string _textureFile, Font& _fontTitle, Font& _fontData, Font& _fontDescription);
	
	virtual string get_title() const;

	virtual void set_position(Vector2f _pos);
	virtual Vector2f get_position() const;

	int get_power() const;
	int get_defense() const;

	void death_check();

private:
	Text m_cardPWR;
	int m_PWRval;

	Text m_cardDEF;
	int m_DEFval;

	virtual void draw(RenderTarget& target, RenderStates states) const;
};