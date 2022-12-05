#pragma once
#include <SFML/Graphics.hpp>

using std::string;
using namespace sf;

class Button : public Drawable
{
public:
	//clickable rectangular button
	Button(Vector2f _size, string _buttonText, Color _textColor, Font& _buttonFont)
	{
		//button shape
		m_buttonShape.setCornerPointCount(2);
		m_buttonShape.setCornersRadius(5);
		m_buttonShape.setSize(_size);
		m_buttonShape.setFillColor(Color::White);
		m_buttonShape.setOutlineThickness(2);
		m_buttonShape.setOutlineColor(Color::Black);

		//button text
		m_buttonText.setFillColor(_textColor);
		m_buttonText.setString(_buttonText);
		m_buttonText.setFont(_buttonFont);
		m_buttonText.setCharacterSize(24);
		m_buttonText.setOrigin(m_buttonText.getLocalBounds().left + m_buttonText.getLocalBounds().width / 2,
			m_buttonText.getLocalBounds().top + m_buttonText.getLocalBounds().height);
	}

	//clickable text, no visible rectangle
	Button(string _buttonText, Color _textColor, Font& _buttonFont)
	{
		//button text
		m_buttonText.setFillColor(_textColor);
		m_buttonText.setString(_buttonText);
		m_buttonText.setFont(_buttonFont);
		m_buttonText.setCharacterSize(50);
		m_buttonText.setOrigin(m_buttonText.getLocalBounds().left + m_buttonText.getLocalBounds().width / 2,
			m_buttonText.getLocalBounds().top + m_buttonText.getLocalBounds().height / 2);

		//button shape (necessary for existing functions)
		m_buttonShape.setSize({ m_buttonText.getLocalBounds().width, m_buttonText.getLocalBounds().height });
		m_buttonShape.setCornerPointCount(2);
		m_buttonShape.setCornersRadius(5);
		m_buttonShape.setFillColor(Color::Transparent);
		m_buttonShape.setOrigin(m_buttonShape.getLocalBounds().left + m_buttonShape.getLocalBounds().width / 2,
			m_buttonShape.getLocalBounds().top + m_buttonShape.getLocalBounds().height / 2);

		//for debug
		//m_buttonShape.setOutlineColor(Color::White);
		//m_buttonShape.setOutlineThickness(1);
	}

	void set_outline_size(float _f)
	{
		m_buttonShape.setOutlineThickness(_f);
	}

	void set_style(int _i)
	{
		m_buttonText.setStyle(_i);
	}

	void set_position(Vector2f _pos)
	{
		m_buttonShape.setPosition(_pos);
		m_buttonText.setPosition(m_buttonShape.getGlobalBounds().left + m_buttonShape.getGlobalBounds().width / 2,
			m_buttonShape.getGlobalBounds().top + m_buttonShape.getGlobalBounds().height / 2);
	}

	bool mouse_is_over(RenderWindow& _window)
	{
		Vector2f mousePosFloat = static_cast<Vector2f>(Mouse::getPosition(_window));			//get mouse coords
		if (m_buttonShape.getGlobalBounds().contains(mousePosFloat))
		{
			return true;
		}
	}

private:
	RoundedRectangleShape m_buttonShape;
	Text m_buttonText;
	Vector2f m_position;

	virtual void draw(RenderTarget& target, RenderStates states) const
	{
		target.draw(m_buttonShape, states);
		target.draw(m_buttonText, states);
	}
};
