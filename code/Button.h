#pragma once
#include <SFML/Graphics.hpp>

using std::string;
using namespace sf;

class Button
{
public:
	Button();

	Button(Vector2f _size, string _buttonText, Color _textColor, Font& _buttonFont)
	{
		//button shape
		button.setCornerPointCount(2);
		button.setCornersRadius(5);
		button.setSize(_size);
		button.setFillColor(Color::White);
		button.setOutlineThickness(2);
		button.setOutlineColor(Color::Black);


		//button text
		m_buttonText.setFillColor(_textColor);
		m_buttonText.setString(_buttonText);
		m_buttonText.setFont(_buttonFont);
		m_buttonText.setCharacterSize(24);
		m_buttonText.setOrigin(button.getGlobalBounds())
		
	}
	
	//creating an i n t e r f a c e to modify on a whim (for mouseover)
	void set_outline_size(float _f)
	{
		button.setOutlineThickness(_f);
	}

	void set_position(Vector2f _pos)
	{
		
		float xPos = 
	}

	

	~Button();

private:
	RoundedRectangleShape button;
	Text m_buttonText;
	Vector2f m_position;
};
