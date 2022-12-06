#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "RoundedRectangleShape.hpp"
using namespace sf;
using namespace std;


class CardBase : public Drawable, public Transformable
{
public:
	CardBase();
	virtual string get_title() const = 0;
	virtual FloatRect get_bounds() const = 0;
	virtual string get_type() const = 0;

	virtual int get_power() const;
	virtual int get_defense() const;

	virtual string get_effectType() const;
	virtual int get_effectVal() const;

	virtual void set_outline_color(Color _color) = 0;
	virtual void set_position(Vector2f _pos) = 0;

	virtual bool mouse_is_over(RenderWindow& _window) = 0;

protected:
	Vector2f CARD_SIZE = { 200, 320 };
	Vector2f CARD_IMG_SIZE = { 160, 160 };

	RoundedRectangleShape m_cardShape;
	RoundedRectangleShape m_cardImageShape;
	
	Text m_cardTitle;
	string m_cardTitleStr;

	Text m_cardDescription;
	string m_cardDescriptionStr;

	FloatRect m_titleBounds;
	RectangleShape m_titleBounds_debug;			//rectangle for bounds

	FloatRect m_descriptionBounds;
	RectangleShape m_descriptionBounds_debug;	//rectangle for bounds

	virtual void draw(RenderTarget& target, RenderStates states) const = 0;

	void calc_title_bounds();
	void calc_desc_bounds();
};