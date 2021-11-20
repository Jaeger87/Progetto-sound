// WrapperFMOD.cpp : Definisce le funzioni per la libreria statica.
//

#include "pch.h"
#include "framework.h"
#include "WrapperFMOD.h"


WrapperFMOD::WrapperFMOD(int _CHANNELS) : CHANNELS(_CHANNELS)
{
	WrapperISOK = InitSystem();
}

bool WrapperFMOD::isWrapperOk()
{
	return WrapperISOK;
}

bool WrapperFMOD::InitSystem()
{
	FMOD_RESULT result;
	result = FMOD::System_Create(&system);

	if (result != FMOD_RESULT::FMOD_OK)
	{
		std::cout << "Something goes wrong..." << std::endl;
		return false;
	}

	system->init(100, FMOD_INIT_NORMAL, 0);
}

void WrapperFMOD::LoadStatic(int channel, std::string audioPath)
{
}

void WrapperFMOD::LoadStreaming(int channel, std::string audioPath)
{
}


void WrapperFMOD::Play(int channel, int sound)
{
	if (!system)
		return;
	std::cout << "bella" << std::endl;
}

void WrapperFMOD::Pause()
{
	std::cout << "bella" << std::endl;
}

void WrapperFMOD::Stop()
{
}

void WrapperFMOD::SetLoop()
{
}

void WrapperFMOD::SetOneShoot()
{
}

void WrapperFMOD::PanLeft(float pan)
{
}

void WrapperFMOD::PanRight(float pan)
{
}

void WrapperFMOD::SetVolume()
{
}

void WrapperFMOD::SetAudioChannel()
{
}
