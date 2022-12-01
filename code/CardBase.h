#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace std;


class CardBase : public Drawable
{
public:
	CardBase();
	virtual string get_title() const;

	virtual void set_position(Vector2f _pos);
	virtual Vector2f get_position() const;

protected:
	Vector2f CARD_SIZE = { 200, 320 };
	Vector2f CARD_IMG_SIZE = { 160, 160 };

	RoundedRectangleShape m_cardShape;
	RoundedRectangleShape m_cardImageShape;
	
	Text m_cardTitle;
	string m_cardTitleStr;

	Text m_cardDescription;
	string m_cardDescriptionStr;

	Vector2f m_position;

	FloatRect m_titleBounds;
	RectangleShape m_titleBounds_debug;			//rectangle for bounds

	FloatRect m_descriptionBounds;
	RectangleShape m_descriptionBounds_debug;	//rectangle for bounds

	virtual void draw(RenderTarget& target, RenderStates states) const = 0;

private:
	void calc_title_bounds();
	void calc_desc_bounds();
};