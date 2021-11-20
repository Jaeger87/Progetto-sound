#pragma once

#include <fmod.hpp>
#include <iostream>

class WrapperFMOD {

	FMOD::System* system = nullptr;
private:
	const int CHANNELS;
	bool WrapperISOK = false;
public:
	WrapperFMOD(int CHANNELS);
	bool isWrapperOk();
	bool InitSystem();
	void LoadStatic(int channel, std::string audioPath);
	void LoadStreaming(int channel, std::string audioPath);
	void Play(int channel, int sound);
	void Pause();
	void Stop();

	void SetLoop();
	void SetOneShoot();
	void PanLeft(float pan);
	void PanRight(float pan);
	void SetVolume();
	void SetAudioChannel();
};
