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
		buttonShape.setCornerPointCount(2);
		buttonShape.setCornersRadius(5);
		buttonShape.setSize(_size);
		buttonShape.setFillColor(Color::White);
		buttonShape.setOutlineThickness(2);
		buttonShape.setOutlineColor(Color::Black);


		//button text
		m_buttonText.setFillColor(_textColor);
		m_buttonText.setString(_buttonText);
		m_buttonText.setFont(_buttonFont);
		m_buttonText.setCharacterSize(24);
		m_buttonText.setOrigin(buttonShape.getGlobalBounds())
		
	}
	
	//creating an i n t e r f a c e to modify on a whim (for mouseover)
	void set_outline_size(float _f)
	{
		buttonShape.setOutlineThickness(_f);
	}

	void set_position(Vector2f _pos)
	{
		
		float xPos = 
	}

	

	~Button();

private:
	RoundedRectangleShape buttonShape;
	Text m_buttonText;
	Vector2f m_position;
};
