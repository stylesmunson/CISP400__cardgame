#include "GameScreen.h"
#include "CardMonster.h"
#include "CardItem.h"

#include <iostream>
using std::cout; using std::endl;

GameScreen::GameScreen(float _width, float _height, Font& _fontLabeling)
{	
	m_resolution.x = _width;
	m_resolution.y = _height;

	//background color
	m_screenBG.setSize(m_resolution);
	m_screenBG.setFillColor({ 238, 238, 240, 255 });
	
	//hand placement
	m_handZone = FloatRect({ 450, 700 }, { 850 , 320 });
	m_handZoneRect.setCornerPointCount(8);
	m_handZoneRect.setCornersRadius(20);
	m_handZoneRect.setSize({ m_handZone.width + 25, m_handZone.height + 25 });
	m_handZoneRect.setPosition(m_handZone.left - 20, m_handZone.top - 12);

	//deck
	m_deckShape.setCornerPointCount(2);
	m_deckShape.setCornersRadius(5);
	m_deckShape.setSize({ 200, 320 });
	m_deckShape.setFillColor(Color::White);
	m_deckShape.setOutlineThickness(2);
	m_deckShape.setOutlineColor(Color::Black);
	m_deckShape.setOrigin(m_deckShape.getLocalBounds().left + m_deckShape.getLocalBounds().width / 2,
		m_deckShape.getLocalBounds().top + m_deckShape.getLocalBounds().height / 2);
	m_deckShape.setPosition(m_resolution.x - m_resolution.x * 0.15, m_resolution.y / 2);
	deck2 = m_deckShape;
	deck2.move(0, 10);
	deck3 = deck2;
	deck3.move(0, 10);

	m_labelDeck.setString("DECK");
	m_labelDeck.setFont(_fontLabeling);
	m_labelDeck.setFillColor(Color::Red);
	m_labelDeck.setCharacterSize(30);
	m_labelDeck.setOrigin(m_labelDeck.getLocalBounds().left + m_labelDeck.getLocalBounds().width / 2,
		m_labelDeck.getLocalBounds().top + m_labelDeck.getLocalBounds().height);
	m_labelDeck.setPosition(m_deckShape.getGlobalBounds().left + m_deckShape.getGlobalBounds().width / 2,
		m_deckShape.getGlobalBounds().top + m_deckShape.getGlobalBounds().height / 2);

	//monster zone
	m_monsterZone = FloatRect({ 640, 240 }, { 200, 200 });
	m_monsterZoneRect.setCornerPointCount(8);
	m_monsterZoneRect.setCornersRadius(20);
	m_monsterZoneRect.setSize({ m_monsterZone.width, m_monsterZone.height });
	m_monsterZoneRect.setPosition(m_monsterZone.left, m_monsterZone.top);
	m_monsterZoneRect.setOutlineColor(Color::Red);
	m_monsterZoneRect.setFillColor(Color::Transparent);
	m_monsterZoneRect.setOutlineThickness(1);

	//item zone
	m_itemZone = FloatRect({ 900, 240 }, { 200, 200 });
	m_itemZoneRect = m_monsterZoneRect;
	m_itemZoneRect.setPosition(m_itemZone.left, m_itemZone.top);

	//phase
	m_labelPhase.setFont(_fontLabeling);
	m_labelPhase.setCharacterSize(25);
	m_labelPhase.setFillColor(Color::Red);
	m_labelPhase.setPosition(50, 50);

	//tokens
	for (int i = 0; i < 20; i++)
	{
		m_player1tokens.push_back(CircleShape(25, 12));
		m_player1tokens.at(i).setPosition({ 1440 + i * 10, 755 });
		m_player1tokens.at(i).setOutlineColor(Color::Red);
		m_player1tokens.at(i).setOutlineThickness(2);
		m_player1tokens.at(i).setFillColor({ 203, 76, 78, 170 });
	}
	m_player2tokens = m_player1tokens;
}

void GameScreen::dispay_tokens(vector<CircleShape>& _tokens)
{

}

void GameScreen::display_hand(vector<CardBase*>& _hand, Color _color)
{	
	for (int i = 0; i < _hand.size(); i++)
		_hand.at(i)->setPosition({ m_handZone.left + m_handZone.width * 0.25f * i, m_handZone.top });

	m_handZoneRect.setFillColor(_color);
}

void GameScreen::display_battleZone(vector<CardBase*>& _battlezone)
{
	if (_battlezone.size() == 1)
		_battlezone.at(0)->setPosition(get_monster_zone().x - 100, get_monster_zone().y - 155);

	else if (_battlezone.size() == 2)
		_battlezone.at(1)->setPosition(get_item_zone().x - 100, get_item_zone().y - 155);
}

Vector2f GameScreen::get_monster_zone() const
{
	return { m_monsterZoneRect.getGlobalBounds().left + m_monsterZoneRect.getGlobalBounds().width / 2,
		m_monsterZoneRect.getGlobalBounds().top + m_monsterZoneRect.getGlobalBounds().height / 2 };
}

Vector2f GameScreen::get_item_zone() const
{
	return { m_itemZoneRect.getGlobalBounds().left + m_itemZoneRect.getGlobalBounds().width / 2,
		m_itemZoneRect.getGlobalBounds().top + m_itemZoneRect.getGlobalBounds().height / 2 };
}

void GameScreen::update_phaseText(string _phase)
{
	m_labelPhase.setString(_phase);
}

void GameScreen::draw(RenderTarget& target, RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(m_screenBG, states);
	target.draw(m_deckShape, states);
	target.draw(deck2, states);
	target.draw(deck3, states);
	target.draw(m_monsterZoneRect, states);
	target.draw(m_itemZoneRect, states);
	target.draw(m_handZoneRect, states);

	target.draw(m_labelDeck, states);
	target.draw(m_labelPhase, states);

	//if (player 1 turn)
	target.draw
}
