#pragma once

#include <fmod.hpp>
#include <iostream>

class WrapperFMOD {

	FMOD::System* system = nullptr;
public:
	void InitSystem();
	void LoadStatic(std::string audioPath);
	void LoadStreaming(std::string audioPath);
	void Play();
	void Pause();
	void Stop();

	void SetLoop();
	void SetOneShoot();
	void PanLeft();
	void PanRight();
	void SetVolume();
	void SetAudioChannel();
};
