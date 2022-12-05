#include "BitmapStore.h"
#include <assert.h>

using namespace sf;
using namespace std;

BitmapStore* BitmapStore::m_s_Instance = nullptr;

BitmapStore::BitmapStore()
{
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

void BitmapStore::add_bitmap(string const& _filename)
{
	map<string, Texture>& bitmapsMap = m_s_Instance->m_mapBitmaps;		//get ref to m_textures using m_s_Instance

	auto keyValuePair = bitmapsMap.find(_filename);						//auto = iterator, search for kvp using filename

	if (keyValuePair == bitmapsMap.end())								//if iterator reaches finds no match
	{
		auto& texture = bitmapsMap[_filename];							//create new kvp using filename
		texture.loadFromFile(_filename);								//load texture from file
	}
}

Texture& BitmapStore::get_bitmap(string const& _filename)
{
	map<string, Texture>& m = m_s_Instance->m_mapBitmaps;

	auto keyValuePair = m.find(_filename);

	if (keyValuePair != m.end())
		return keyValuePair->second;
	else
	{
		#ifdef console_debug
			cout << "BitmapStore::get_bitmap() -- Texture not found -- *CRASHING*" << endl;
		#endif
		return keyValuePair->second;
	}
}