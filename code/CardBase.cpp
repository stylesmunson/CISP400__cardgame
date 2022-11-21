#include "CardBase.h"

void CardBase::set_title(string _title)
{
	m_cardTitleStr = _title;
}

string CardBase::get_title() const
{
	return m_cardTitleStr;
}