#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace std;


class CardBase
{
public:
	void set_title(string _title);
	string get_title() const;

protected:
	RectangleShape m_cardShape;
	RectangleShape m_cardImageShape;

	Text m_cardTitle;
	Text m_cardPWR;
	Text m_cardDEF;
	string m_cardTitleStr;
	string m_cardPWRStr;
	string m_cardDEFStr;

	Sprite m_cardImage;
	Texture m_cardImageTexture;

};