#pragma once
#ifndef GAMEFONTS_H
#define GAMEFONTS_H

#include <SFML/Graphics.hpp>
#include <iostream>

using sf::Font; using std::cout; using std::endl;

struct GameFonts
{
	GameFonts()
	{
		load_fonts(fontCardTitle, fontCardDescription, fontCardData);
	}
	
	int load_fonts(Font& _titleFont, Font& _descriptionFont, Font& _fontData)
	{
		cout << "Loading fonts..." << endl;
		if (!_titleFont.loadFromFile("res/fonts/font_NicoPaint.ttf"))
		{
			std::cout << "NO TITLE FONT FOUND \n";
			return EXIT_FAILURE;
		}
		else
			cout << "TItle font loaded successfully." << endl;

		if (!_descriptionFont.loadFromFile("res/fonts/font_NicoClean.ttf"))
		{
			std::cout << "NO DESCRIPTION FONT FOUND \n";
			return EXIT_FAILURE;
		}
		else
			cout << "Description font loaded successfully." << endl;

		if (!_fontData.loadFromFile("res/fonts/font_NicoBold.ttf"))
		{
			std::cout << "NO DATA FONT FOUND \n";
			return EXIT_FAILURE;
		}
		else
			cout << "Data font loaded successfully." << endl;
		
		return 1;
	}

	Font fontCardTitle;
	Font fontCardDescription;
	Font fontCardData;
};

#endif