#include "CardItem.h"

CardItem::CardItem(string _title, string _effect, int _effectVal, string _description, Texture _texture, Font& _fontTitle, Font& _fontEffect, Font& _fontDescription)
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
	string effectInput;
	for (int i = 0; i < _effect.size(); i++)
	{
		effectInput += tolower(_effect[i]);
	}

	if (effectInput == "def")
	{
		m_effectVal = _effectVal;
		m_cardEffectStr = "DEF + " + to_string(m_effectVal);
	}
	else if (effectInput == "pwr")
	{
		m_effectVal = _effectVal;
		m_cardEffectStr = "PWR + " + to_string(m_effectVal);
	}
	else if (effectInput == "skip")
		m_cardEffectStr = "OPPONENT CAN'T PLAY ITEM";

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
	m_cardImageTexture = _texture;
	m_cardImageShape.setTexture(&m_cardImageTexture);
}