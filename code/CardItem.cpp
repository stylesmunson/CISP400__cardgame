#include <iostream>
#include "CardItem.h"
#include "TextureHolder.h"

CardItem::CardItem(string _title, string _effect, int _effectVal, string _description, string _textureFile, Font& _fontTitle, Font& _fontEffect, Font& _fontDescription)
{
	//TITLE
	m_cardTitleStr = _title;
	m_cardTitle.setFont(_fontTitle);
	m_cardTitle.setString(m_cardTitleStr);
	while (m_cardTitle.getGlobalBounds().width >= m_titleBounds.width)
	{
		m_cardTitle.setCharacterSize(m_cardTitle.getCharacterSize() - 1);
		m_cardTitle.setPosition(m_cardTitle.getPosition().x, m_cardTitle.getPosition().y + (m_titleBounds.height * 0.03));
	}
	
	//DATA (ITEM EFFECT)
	m_cardEffect.setCharacterSize(20);
	m_cardEffect.setFillColor(Color::Black);
	m_effectType = _effect;

	if (m_effectType == "DEF")
	{
		m_effectVal = _effectVal;
		m_cardEffectStr = "DEF + " + to_string(m_effectVal);
	}
	else if (m_effectType == "PWR")
	{
		m_effectVal = _effectVal;
		m_cardEffectStr = "PWR + " + to_string(m_effectVal);
	}

	m_cardEffect.setFont(_fontEffect);
	m_cardEffect.setString(m_cardEffectStr);
	m_cardEffect.setOrigin(m_cardEffect.getLocalBounds().left + m_cardEffect.getLocalBounds().width / 2, 0);
	m_cardEffect.setPosition(m_cardShape.getLocalBounds().left + m_cardShape.getLocalBounds().width / 2, m_cardShape.getGlobalBounds().height - (m_cardShape.getGlobalBounds().height * 0.10));

	//DESCRIPTION
	m_cardDescriptionStr = _description;
	m_cardDescription.setFont(_fontDescription);
	m_cardDescription.setString(m_cardDescriptionStr);
	//makeshift word wrap, inserts newline at letter instead of whole word so adjust description manually
	for (int i = 0; i < m_cardDescription.getString().getSize(); i++)
	{
		if (m_cardDescription.findCharacterPos(i).x >= m_descriptionBounds.width)
		{
			string str = m_cardDescription.getString();
			str.insert(i, "\n");
			m_cardDescription.setString(str);
		}
	}

	//IMAGE
	m_cardImageShape.setTexture(&TextureHolder::get_texture(_textureFile));
}

string CardItem::get_title() const
{
	return m_cardTitleStr;
}

FloatRect CardItem::get_bounds() const
{
	FloatRect cardBounds(getPosition(), CARD_SIZE);
	return cardBounds;
}

string CardItem::get_type() const
{
	return "item";
}

string CardItem::get_effectType() const
{
	return m_effectType;
}

int CardItem::get_effectVal() const
{
	return m_effectVal;
}

void CardItem::set_outline_color(Color _color)
{
	m_cardShape.setOutlineColor(_color);
}

bool CardItem::mouse_is_over(RenderWindow& _window)
{
	Vector2f mousePosFloat = static_cast<Vector2f>(Mouse::getPosition(_window));			//get mouse coords
	if (get_bounds().contains(mousePosFloat))
	{
		std::cout << "mouse is over " << this->get_title() << endl;
		return true;
	}
}

void CardItem::set_position(Vector2f _pos)
{
	setPosition(_pos);
	m_cardShape.setPosition(_pos);
}

void CardItem::draw(RenderTarget& target, RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(m_cardShape, states);
	target.draw(m_cardImageShape, states);

	target.draw(m_cardTitle, states);
	//target.draw(m_titleBounds_debug, states);

	target.draw(m_cardDescription, states);
	//target.draw(m_descriptionBounds_debug, states);

	target.draw(m_cardEffect, states);
}
