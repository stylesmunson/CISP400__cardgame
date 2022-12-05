#include <sstream>
#include <string>
#include <iostream>
#include "CardMonster.h"
#include "TextureHolder.h"

CardMonster::CardMonster(string _title, int _power, int _defense, string _description, string _textureFile, Font& _fontTitle, Font& _fontData, Font& _fontDescription)
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

	//DATA (PWR)
	m_cardPWR.setCharacterSize(20);
	m_cardPWR.setFillColor(Color::Black);
	m_cardPWR.setPosition(m_cardImageShape.getGlobalBounds().left, m_cardShape.getGlobalBounds().height - (m_cardShape.getGlobalBounds().height * 0.10));
	m_PWRval = _power;
	m_cardPWR.setFont(_fontData);
	stringstream PWRstream;
	PWRstream << "PWR " << m_PWRval;
	m_cardPWR.setString(PWRstream.str());

	//DATA (DEF)
	m_cardDEF.setCharacterSize(20);
	m_cardDEF.setFillColor(Color::Black);
	m_cardDEF.setPosition(m_cardImageShape.getGlobalBounds().left + 108, m_cardShape.getGlobalBounds().height - (m_cardShape.getGlobalBounds().height * 0.10));
	m_DEFval = _defense;
	m_cardDEF.setFont(_fontData);
	stringstream DEFstream;
	DEFstream << "DEF " << m_DEFval;
	m_cardDEF.setString(DEFstream.str());
	if (m_DEFval == 10)
		m_cardDEF.setPosition(m_cardImageShape.getGlobalBounds().left + 97, m_cardShape.getGlobalBounds().height - (m_cardShape.getGlobalBounds().height * 0.10));

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

string CardMonster::get_title() const
{
	return m_cardTitleStr;
}

int CardMonster::get_power() const
{
	return m_PWRval;
}

int CardMonster::get_defense() const
{
	return m_DEFval;
}

FloatRect CardMonster::get_bounds() const
{
	FloatRect cardBounds(getPosition(), CARD_SIZE);
	return cardBounds;
}

string CardMonster::get_type() const
{
	return "monster";
}

void CardMonster::set_position(Vector2f _pos)
{
	m_cardShape.setPosition(_pos);
	setPosition(_pos);
}

void CardMonster::set_outline_color(Color _color)
{
	m_cardShape.setOutlineColor(_color);
}


bool CardMonster::mouse_is_over(RenderWindow& _window)
{
	Vector2f mousePosFloat = static_cast<Vector2f>(Mouse::getPosition(_window));			//get mouse coords
	if (get_bounds().contains(mousePosFloat))
	{
		std::cout << "mouse is over " << this->get_title() << endl;
		return true;
	}
}

void CardMonster::draw(RenderTarget& target, RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(m_cardShape, states);
	target.draw(m_cardImageShape, states);

	target.draw(m_cardTitle, states);
	target.draw(m_titleBounds_debug, states);

	target.draw(m_cardDescription, states);
	target.draw(m_descriptionBounds_debug, states);
	
	target.draw(m_cardPWR, states);
	target.draw(m_cardDEF, states);
}
