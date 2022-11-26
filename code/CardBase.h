#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace std;


class CardBase : public Drawable
{
public:
	CardBase();
	void assemble_card();

	string get_title() const;

	void set_position();
	Vector2f get_position() const;

	void calc_title_bounds();
	void calc_desc_bounds();

protected:
	Vector2f CARD_SIZE = { 200, 320 };
	Vector2f CARD_IMG_SIZE = { 160, 160 };

	RoundedRectangleShape m_cardShape;
	RoundedRectangleShape m_cardImageShape;
	
	Text m_cardTitle;
	Text m_cardDescription;
	string m_cardTitleStr;
	string m_cardDescriptionStr;

	Text m_cardPWR;
	int m_PWRval;

	Text m_cardDEF;
	int m_DEFval;

	Sprite m_cardImage;
	Texture m_cardImageTexture;

	Vector2f m_position;

	FloatRect titleBounds;
	RectangleShape titleBoundsRect_debug;

	FloatRect descriptionBounds;
	RectangleShape descriptionBoundsRect_debug;


	virtual void draw(RenderTarget& target, RenderStates states) const;
};