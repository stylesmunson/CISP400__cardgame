#pragma once
#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H

#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;
using namespace std;

class TextureHolder
{
public:
	TextureHolder();
	static Texture& GetTexture(string const& filename);

private:
	map<string, Texture> m_Textures;		//map holds pairs of string & texture
	static TextureHolder* m_s_Instance;		//ptr of the same type as class itself, the one and only instance
};

#endif // !TEXTURE_HOLDER_H
