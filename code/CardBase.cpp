#include "CardBase.h"

CardBase::CardBase()
{
	assemble_card();
}

void CardBase::set_title(string _title)
{
	m_cardTitleStr = _title;
}

string CardBase::get_title() const
{
	return m_cardTitleStr;
}

 void CardBase::assemble_card()
{
	/* [ASSEMBLE SHAPES] */
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


	/* [PLACE TEXT] */
	
 }

void CardBase::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_cardShape, states);
	target.draw(m_cardImageShape, states);

	//target.draw(m_cardTitle, states);
	//target.draw(m_cardDescription, states);
	//target.draw(m_cardPWR, states);
	//target.draw(m_cardDEF, states);
}
