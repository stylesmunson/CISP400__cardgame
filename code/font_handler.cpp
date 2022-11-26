#include <iostream>
#include "game.h"

void font_handler()
{
	Font fontCardTitle;
	if (!fontCardTitle.loadFromFile("res/fonts/font_NicoPaint.ttf"))
		std::cout << "NO TITLE FONT FOUND";

	Font fontCardDescription;
	if (!fontCardDescription.loadFromFile("res/fonts/font_NicoPaint.ttf"))
		std::cout << "NO DESCRIPTION FONT FOUND";

	Font fontCardData;
	if (!fontCardData.loadFromFile("res/fonts/font_NicoPaint.ttf"))
		std::cout << "NO DATA FONT FOUND";

}