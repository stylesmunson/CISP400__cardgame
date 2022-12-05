#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "CardBase.h"
#include "GameFontsLoader.h"

using namespace sf;

class GameScreen : public Drawable, public Transformable
{
public:
	GameScreen(float _width, float _height, Font& _fontLabeling);

	void display_hand(vector<CardBase*>& _hand, Color _color);
	void display_battleZone(vector<CardBase*>& _battlers);
	void update_phaseText(string _phase);
	void dispay_tokens(vector<CircleShape>& _tokens);

	Vector2f get_monster_zone() const;
	Vector2f get_item_zone() const;

private:
	Vector2f m_resolution;
	RectangleShape m_screenBG;

	RoundedRectangleShape m_deckShape, deck2, deck3;
	Text m_labelDeck;

	FloatRect m_monsterZone;
	RoundedRectangleShape m_monsterZoneRect;
	Text m_labelMonsterZone;

	FloatRect m_itemZone;
	RoundedRectangleShape m_itemZoneRect;
	Text m_labelItemZone;

	FloatRect m_handZone;
	RoundedRectangleShape m_handZoneRect;
	Text m_labelHand;

	Text m_labelPhase;

	vector<CircleShape> m_player1tokens;
	vector<CircleShape> m_player2tokens;


	virtual void draw(RenderTarget& target, RenderStates states) const;
};
