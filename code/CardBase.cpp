#include "CardBase.h"
#include <iostream>

CardBase::CardBase()
{
	/********** [ ASSEMBLE SHAPES ] **********/
	m_cardShape.setCornerPointCount(2);
	m_cardShape.setCornersRadius(5);
	m_cardShape.setSize(CARD_SIZE);
	m_cardShape.setOutlineColor(Color::Blue);
	m_cardShape.setFillColor(Color::White);
	m_cardShape.setOutlineThickness(-2);

	m_cardImageShape.setCornerPointCount(2);
	m_cardImageShape.setCornersRadius(5);
	m_cardImageShape.setSize(CARD_IMG_SIZE);
	m_cardImageShape.setOutlineColor(Color::Black);
	m_cardImageShape.setFillColor(Color::White);
	m_cardImageShape.setOutlineThickness(2.0);

	FloatRect cardImageShape_locBounds = m_cardImageShape.getLocalBounds();
	FloatRect cardShape_locBounds = m_cardShape.getLocalBounds();

	//set origin to center of rectangle
	m_cardImageShape.setOrigin(cardImageShape_locBounds.left + cardImageShape_locBounds.width / 2, cardImageShape_locBounds.top + cardImageShape_locBounds.height / 2);
	//set position to desired position within cardShape
	m_cardImageShape.setPosition(cardShape_locBounds.left + cardShape_locBounds.width / 2, (cardShape_locBounds.top + cardShape_locBounds.height / 2) - ((cardShape_locBounds.top + cardShape_locBounds.height / 2) * 0.25));


	/********** [ PLACE TEXT ] **********/
	m_titleBounds = { 20, 20, cardImageShape_locBounds.width, 10 };
	//RectangleShape titleBoundsRect({ m_titleBounds.width, m_titleBounds.height });

	//TITLE
	m_cardTitle.setCharacterSize(20);
	m_cardTitle.setFillColor(Color::Black);
	m_cardTitle.setPosition(m_cardImageShape.getGlobalBounds().left, 12);

	//DESCRIPTION
	m_cardDescription.setCharacterSize(14);
	m_cardDescription.setFillColor(Color::Black);
	m_cardDescription.setPosition(m_cardImageShape.getGlobalBounds().left, m_cardImageShape.getGlobalBounds().height + (m_cardImageShape.getLocalBounds().height * 0.27));

	calc_title_bounds();
	calc_desc_bounds();
}

string CardBase::get_title() const
{
	return m_cardTitleStr;
}

void CardBase::set_position(Vector2f _pos)
{
	m_position = _pos;
}

Vector2f CardBase::get_position() const
{
	return m_position;
}

void CardBase::calc_title_bounds()
{
	m_titleBounds = { m_cardImageShape.getGlobalBounds().left, 15, m_cardImageShape.getLocalBounds().width, 19 };

	m_titleBounds_debug.setSize({ m_titleBounds.width, m_titleBounds.height });
	m_titleBounds_debug.setPosition(m_titleBounds.left, m_titleBounds.top);
	m_titleBounds_debug.setOutlineColor(Color::Red);
	m_titleBounds_debug.setOutlineThickness(1);
	m_titleBounds_debug.setFillColor(Color::Transparent);
}

void CardBase::calc_desc_bounds()
{
	m_descriptionBounds = { m_cardImageShape.getGlobalBounds().left, 210, m_cardImageShape.getLocalBounds().width, 70 };

	m_descriptionBounds_debug.setSize({ m_descriptionBounds.width, m_descriptionBounds.height });
	m_descriptionBounds_debug.setPosition(m_descriptionBounds.left, m_descriptionBounds.top);
	m_descriptionBounds_debug.setOutlineColor(Color::Red);
	m_descriptionBounds_debug.setOutlineThickness(1);
	m_descriptionBounds_debug.setFillColor(Color::Transparent);
}