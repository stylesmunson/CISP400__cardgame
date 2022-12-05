#include "TextureHolder.h"
#include <assert.h>

TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder()
{
	assert(m_s_Instance == nullptr);		//makes sure m_s_Instance points to null
	m_s_Instance = this;					//assigns ptr m_s_Instance to 'this' (itself)
}

Texture& TextureHolder::get_texture(string const& filename)
{
	auto& m = m_s_Instance->m_Textures;						//reference map 'm' of map m_Textures
	auto keyValuePair = m.find(filename);					//create iterator to hold KVP & search for KVP using filename

	//if m.find(filename) finds a match (iterator doesn't reach the end of the map)
	if (keyValuePair != m.end())							
		return keyValuePair->second;						//return the map's second value (the texture)

	//if iterator *does* reach the end of the map (no match)
	else													
	{
		auto& texture = m[filename];						//create new key value pair using filename
		texture.loadFromFile(filename);						//load texture from filename
		return texture;
	}
}