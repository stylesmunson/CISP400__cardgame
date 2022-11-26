#include "CardBase.h"

CardBase::CardBase()
{
	assemble_card();
}

string CardBase::get_title() const
{
	return m_cardTitleStr;
}

 void CardBase::assemble_card()
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

	FloatRect cardImageShape_bounds = m_cardImageShape.getLocalBounds();
	FloatRect cardShape_bounds = m_cardShape.getLocalBounds();

	//set origin to center of rectangle
	m_cardImageShape.setOrigin(cardImageShape_bounds.left + cardImageShape_bounds.width / 2, cardImageShape_bounds.top + cardImageShape_bounds.height / 2);
	//set position to desired position within cardShape
	m_cardImageShape.setPosition(cardShape_bounds.left + cardShape_bounds.width / 2, (cardShape_bounds.top + cardShape_bounds.height / 2) - ((cardShape_bounds.top + cardShape_bounds.height / 2) * 0.25));


	/********** [ PLACE TEXT ] **********/
	FloatRect titleBounds = { 20, 20, cardImageShape_bounds.width, 10 };
	RectangleShape titleBoundsRect({ titleBounds.width, titleBounds.height });

	//TITLE
	m_cardTitle.setCharacterSize(20);
	m_cardTitle.setFillColor(Color::Black);
	m_cardTitle.setPosition(m_cardImageShape.getGlobalBounds().left, 12);

	//POWER
	m_cardPWR.setCharacterSize(20);
	m_cardPWR.setFillColor(Color::Black);
	m_cardPWR.setPosition(m_cardImageShape.getGlobalBounds().left, m_cardShape.getGlobalBounds().height - (m_cardShape.getGlobalBounds().height * 0.10));

	//DEFENSE
	m_cardDEF.setCharacterSize(20);
	m_cardDEF.setFillColor(Color::Black);
	m_cardDEF.setPosition(m_cardPWR.getGlobalBounds().width + 122, m_cardPWR.getGlobalBounds().top);

	//DESCRIPTION
	m_cardDescription.setCharacterSize(14);
	m_cardDescription.setFillColor(Color::Black);
	m_cardDescription.setPosition(m_cardImageShape.getGlobalBounds().left, m_cardImageShape.getGlobalBounds().height + (m_cardImageShape.getLocalBounds().height * 0.27));

	calc_title_bounds();
	calc_desc_bounds();

 }



void CardBase::calc_title_bounds()
{
	titleBounds = { m_cardImageShape.getGlobalBounds().left, 15, m_cardImageShape.getLocalBounds().width, 19 };

	titleBoundsRect_debug.setSize({ titleBounds.width, titleBounds.height });
	titleBoundsRect_debug.setPosition(titleBounds.left, titleBounds.top);
	titleBoundsRect_debug.setOutlineColor(Color::Red);
	titleBoundsRect_debug.setOutlineThickness(1);
	titleBoundsRect_debug.setFillColor(Color::Transparent);
}

void CardBase::calc_desc_bounds()
{
	descriptionBounds = { m_cardImageShape.getGlobalBounds().left, 210, m_cardImageShape.getLocalBounds().width, 70 };

	descriptionBoundsRect_debug.setSize({ descriptionBounds.width, descriptionBounds.height });
	descriptionBoundsRect_debug.setPosition(descriptionBounds.left, descriptionBounds.top);
	descriptionBoundsRect_debug.setOutlineColor(Color::Red);
	descriptionBoundsRect_debug.setOutlineThickness(1);
	descriptionBoundsRect_debug.setFillColor(Color::Transparent);
}

void CardBase::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_cardShape, states);
	target.draw(m_cardImageShape, states);

	target.draw(m_cardTitle, states);
	target.draw(titleBoundsRect_debug, states);

	target.draw(m_cardDescription, states);
	target.draw(descriptionBoundsRect_debug, states);

	if (m_PWRval > 0)
		target.draw(m_cardPWR, states);

	if (m_DEFval > 0)
		target.draw(m_cardDEF, states);
}
