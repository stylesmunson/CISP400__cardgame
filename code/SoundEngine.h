#pragma once
#ifndef SOUND_ENGINE_H
#define SOUND_ENGINE_H

#include <SFML/Audio.hpp>

using namespace sf;

class SoundEngine
{
public:
	SoundEngine();

	static void play_click();
	static void play_nextPhase();
	static void play_battlePhase();
	static void play_drawCard();
	static void play_monsterPlay();
	static void play_monsterDeath();
	
	static SoundEngine* m_s_Instance;

private:
	SoundBuffer m_clickBuffer;
	Sound m_click;

	SoundBuffer m_nextPhaseBuffer;
	Sound m_nextPhase;

	SoundBuffer m_battlePhaseBuffer;
	Sound m_battlePhase;

	SoundBuffer m_drawCardBuffer;
	Sound m_drawCard;

	SoundBuffer m_monsterPlayBuffer;
	Sound m_monsterPlay;

	SoundBuffer m_monsterDeathBuffer;
	Sound m_monsterDeath;
};

#endif
