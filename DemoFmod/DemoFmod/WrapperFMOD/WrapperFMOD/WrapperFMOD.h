#pragma once

#include <fmod.hpp>
#include <iostream>
#include <map>

class WrapperFMOD {

	FMOD::System* system = nullptr;
private:
	const int CHANNELS_SIZE;
	bool WrapperISOK = false;
	FMOD::Channel** channels;
	std::map<std::string, FMOD::Sound*> resources;
	bool LoadAudio(std::string audioPath, std::string alias, bool streaming);
	void Play(int channel, std::string alias, bool loop);
	bool ChannelCheck(int channel);
public:
	WrapperFMOD(int CHANNELS);
	bool isWrapperOk();
	bool InitSystem();
	
	void LoadStatic(std::string audioPath, std::string alias);
	void LoadStreaming(std::string audioPath, std::string alias);

	void PlayOneShoot(int channel, std::string alias);
	void PlayLoop(int channel, std::string alias);
	void Pause(int channel);
	void Stop(int channel);

	void PanLeft(int channel, float pan);
	void PanRight(int channel, float pan);
	void SetVolume(int channel, float volume);
	~WrapperFMOD();
};
