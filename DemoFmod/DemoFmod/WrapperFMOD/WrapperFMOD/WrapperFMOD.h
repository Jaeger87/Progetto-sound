#pragma once

#include <fmod.hpp>
#include <iostream>

class WrapperFMOD {

	FMOD::System* m_FMODSystem = nullptr;
public:
	void play();
	void pause();
	void stop();

	void setVolume();
};
