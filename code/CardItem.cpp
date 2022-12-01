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
	m_cardImageShape.setTexture(&TextureHolder::GetTexture(_textureFile));
}

string CardItem::get_title() const
{
	return m_cardTitleStr;
}

void CardItem::set_position(Vector2f _pos)
{
	m_position = _pos;
}

Vector2f CardItem::get_position() const
{
	return m_position;
}

void CardItem::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_cardShape, states);
	target.draw(m_cardImageShape, states);

	target.draw(m_cardTitle, states);
	target.draw(m_titleBounds_debug, states);

	target.draw(m_cardDescription, states);
	target.draw(m_descriptionBounds_debug, states);

	target.draw(m_cardEffect, states);
}
