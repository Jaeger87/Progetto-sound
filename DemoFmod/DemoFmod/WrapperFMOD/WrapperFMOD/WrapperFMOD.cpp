// WrapperFMOD.cpp : Definisce le funzioni per la libreria statica.
//

#include "pch.h"
#include "framework.h"
#include "WrapperFMOD.h"


void WrapperFMOD::play()
{
	FMOD_RESULT result;

	result = FMOD::System_Create(&m_FMODSystem);
	std::cout << "bella" << std::endl;
}

void WrapperFMOD::pause()
{
	std::cout << "bella" << std::endl;
}

void WrapperFMOD::stop()
{
}

void WrapperFMOD::setVolume()
{
}
