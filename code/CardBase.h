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

	void set_title(string _title);
	string get_title() const;

	void set_position();
	Vector2f get_position() const;

protected:
	Vector2f CARD_SIZE = { 200, 320 };
	Vector2f CARD_IMG_SIZE = { 160, 160 };

	RoundedRectangleShape m_cardShape;
	RoundedRectangleShape m_cardImageShape;
	
	Text m_cardTitle;
	Text m_cardDescription;
	string m_cardTitleStr;
	string m_cardDescriptionStr;

	Sprite m_cardImage;
	Texture m_cardImageTexture;

	Vector2f m_position;

	virtual void draw(RenderTarget& target, RenderStates states) const;
};