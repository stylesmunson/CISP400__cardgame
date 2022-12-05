#include <assert.h>
#include "SoundEngine.h"

using namespace sf;
using namespace std;

SoundEngine* SoundEngine::m_s_Instance = nullptr;

SoundEngine::SoundEngine()
{
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;

	//load sound into buffers
	m_clickBuffer.loadFromFile("");
	m_nextPhaseBuffer.loadFromFile("");
	m_battlePhaseBuffer.loadFromFile("");
	m_drawCardBuffer.loadFromFile("");
	m_monsterPlayBuffer.loadFromFile("");
	m_monsterDeathBuffer.loadFromFile("");

	m_click.setBuffer(m_clickBuffer);
	m_nextPhase.setBuffer(m_clickBuffer);
	m_battlePhase.setBuffer(m_clickBuffer);
	m_drawCard.setBuffer(m_clickBuffer);
	m_monsterPlay.setBuffer(m_clickBuffer);
	m_monsterDeath.setBuffer(m_clickBuffer);
}

void SoundEngine::play_click()
{
	m_s_Instance->m_click.play();
}

void SoundEngine::play_nextPhase()
{
	m_s_Instance->m_nextPhase.play();
}

void SoundEngine::play_battlePhase()
{
	m_s_Instance->m_battlePhase.play();
}

void SoundEngine::play_drawCard()
{
	m_s_Instance->m_drawCard.play();
}

void SoundEngine::play_monsterPlay()
{
	m_s_Instance->m_monsterPlay.play();
}

void SoundEngine::play_monsterDeath()
{
	m_s_Instance->m_monsterDeath.play();
}
