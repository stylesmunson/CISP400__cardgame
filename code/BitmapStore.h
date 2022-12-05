#pragma once
#ifndef BITMAP_STORE_H
#define BITMAP_STORE_H

#include <SFML/Graphics.hpp>
#include <map>

class BitmapStore
{
public:
	BitmapStore();
	
	static sf::Texture& get_bitmap(std::string const& _filename);
	static void add_bitmap(std::string const& _filename);

private:
	std::map<std::string, sf::Texture> m_mapBitmaps;
	static BitmapStore* m_s_Instance;
};

#endif