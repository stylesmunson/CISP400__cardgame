#include <sstream>
#include <string>
#include "CardMonster.h"

CardMonster::CardMonster(string _title, int _power, int _defense, string _description, Font& _fontTitle, Font& _fontData, Font& _fontDescription)
{
	//TITLE
	m_cardTitleStr = _title;
	m_cardTitle.setFont(_fontTitle);
	m_cardTitle.setString(m_cardTitleStr);
	while (m_cardTitle.getGlobalBounds().width >= titleBounds.width)
	{
		m_cardTitle.setCharacterSize(m_cardTitle.getCharacterSize() - 1);
		m_cardTitle.setPosition(m_cardTitle.getPosition().x, m_cardTitle.getPosition().y + (titleBounds.height * 0.03));
	}

	//DATA (PWR)
	m_PWRval = _power;
	m_cardPWR.setFont(_fontData);
	stringstream PWRstream;
	PWRstream << "PWR " << m_PWRval;
	m_cardPWR.setString(PWRstream.str());

	//DATA (DEF)
	m_DEFval = _defense;
	m_cardDEF.setFont(_fontData);
	stringstream DEFstream;
	DEFstream << "DEF " << m_DEFval;
	m_cardDEF.setString(DEFstream.str());

	//DESCRIPTION
	m_cardDescriptionStr = _description;
	m_cardDescription.setFont(_fontDescription);
	m_cardDescription.setString(m_cardDescriptionStr);
	for (int i = 0; i < m_cardDescription.getString().getSize(); i++)
	{
		if (m_cardDescription.findCharacterPos(i).x >= descriptionBounds.width)
		{
			string str = m_cardDescription.getString();
			str.insert(i, "\n");
			m_cardDescription.setString(str);
		}
	}
}

int CardMonster::get_defense() const
{
	return m_DEFval;
}

int CardMonster::get_power() const
{
	return m_PWRval;
}

void CardMonster::death_check()
{
	if (m_DEFval <= 0)
	{
		/*destroy monster */
	}
}
