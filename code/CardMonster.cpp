#include <sstream>
#include <string>
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
	m_cardDEF.setPosition(m_cardPWR.getGlobalBounds().width + 122, m_cardPWR.getGlobalBounds().top);
	m_DEFval = _defense;
	m_cardDEF.setFont(_fontData);
	stringstream DEFstream;
	DEFstream << "DEF " << m_DEFval;
	m_cardDEF.setString(DEFstream.str());

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
	m_cardImageShape.setTexture(&TextureHolder::GetTexture(_textureFile));
}

string CardMonster::get_title() const
{
	return m_cardTitleStr;
}

void CardMonster::set_position(Vector2f _pos)
{
	m_position = _pos;
}

Vector2f CardMonster::get_position() const
{
	return m_position;
}

int CardMonster::get_power() const
{
	return m_PWRval;
}

int CardMonster::get_defense() const
{
	return m_DEFval;
}


void CardMonster::death_check()
{
	if (m_DEFval <= 0)
	{
		/*destroy monster */
	}
}

void CardMonster::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_cardShape, states);
	target.draw(m_cardImageShape, states);

	target.draw(m_cardTitle, states);
	target.draw(m_titleBounds_debug, states);

	target.draw(m_cardDescription, states);
	target.draw(m_descriptionBounds_debug, states);
	
	target.draw(m_cardPWR, states);
	target.draw(m_cardDEF, states);
}
