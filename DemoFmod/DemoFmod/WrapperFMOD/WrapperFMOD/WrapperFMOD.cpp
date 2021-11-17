// WrapperFMOD.cpp : Definisce le funzioni per la libreria statica.
//

#include "pch.h"
#include "framework.h"
#include "WrapperFMOD.h"


void WrapperFMOD::InitSystem()
{
	FMOD::System_Create(&system);
	system->init(100, FMOD_INIT_NORMAL, 0);
}

void WrapperFMOD::LoadStatic(std::string audioPath)
{
}

void WrapperFMOD::LoadStreaming(std::string audioPath)
{
}

void WrapperFMOD::Play()
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

void WrapperFMOD::PanLeft()
{
}

void WrapperFMOD::PanRight()
{
}

void WrapperFMOD::SetVolume()
{
}

void WrapperFMOD::SetAudioChannel()
{
}
