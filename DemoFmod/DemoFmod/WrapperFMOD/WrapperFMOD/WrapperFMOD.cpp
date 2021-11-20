// WrapperFMOD.cpp : Definisce le funzioni per la libreria statica.
//

#include "pch.h"
#include "framework.h"
#include "WrapperFMOD.h"


WrapperFMOD::WrapperFMOD(int _CHANNELS) : CHANNELS_SIZE(_CHANNELS)
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

	system->init(CHANNELS_SIZE, FMOD_INIT_NORMAL, 0);
	channels = new FMOD::Channel*[CHANNELS_SIZE];
	return true;
}

bool WrapperFMOD::LoadAudio(std::string audioPath, std::string alias, bool streaming)
{
	FMOD::Sound* sound;
	FMOD_RESULT result;
	if(streaming)
		result = system->createStream(audioPath.c_str(), FMOD_DEFAULT, 0, &sound);
	else
		result = system->createSound(audioPath.c_str(), FMOD_DEFAULT, 0, &sound);
	
	if (result != FMOD_RESULT::FMOD_OK)
	{
		std::cout << "Something goes wrong..." << std::endl;
		return false;
	}
	resources[alias] = sound;
	return true;
}

void WrapperFMOD::LoadStatic(std::string audioPath, std::string alias)
{
	LoadAudio(audioPath, alias, false);
}

void WrapperFMOD::LoadStreaming(std::string audioPath, std::string alias)
{
	LoadAudio(audioPath, alias, true);
}


void WrapperFMOD::Play(int channel, std::string alias, bool loop)
{
	if (!system)
		return;
	if (!ChannelCheck(channel))
		return;
	
	FMOD::Sound* sound = resources[alias];
	if (!sound)
	{
		std::cout << "Sound not found" << std::endl;
		return;
	}

	FMOD::Channel* fmodChannel = channels[channel];

	if (loop) 
		sound->setMode(FMOD_LOOP_NORMAL);
	else 
		sound->setMode(FMOD_LOOP_OFF);
	
	fmodChannel->stop();
	FMOD_RESULT result = system->playSound(sound, 0, false, &channels[channel]);
}

bool WrapperFMOD::ChannelCheck(int channel)
{
	if (channel < 0 || channel >= CHANNELS_SIZE)
	{
		std::cout << "Channel not found" << std::endl;
		return false;
	}

	return true;
}

void WrapperFMOD::PlayOneShoot(int channel, std::string alias)
{
	Play(channel, alias, false);
}

void WrapperFMOD::PlayLoop(int channel, std::string alias)
{
	Play(channel, alias, true);
}

void WrapperFMOD::Pause(int channel)
{
	if (!ChannelCheck(channel))
		return;
	channels[channel]->setPaused(true);
}

void WrapperFMOD::Stop(int channel)
{
	if (!ChannelCheck(channel))
		return;
	channels[channel]->stop();
}

void WrapperFMOD::PanLeft(int channel, float pan)
{
	if (!ChannelCheck(channel))
		return;
	channels[channel]->setPan(-pan);
}

void WrapperFMOD::PanRight(int channel, float pan)
{
	if (!ChannelCheck(channel))
		return;
	channels[channel]->setPan(pan);
}

void WrapperFMOD::SetVolume(int channel, float volume)
{
	if (!ChannelCheck(channel))
		return;
	channels[channel]->setVolume(volume);
}

WrapperFMOD::~WrapperFMOD()
{
	system->release();
	delete[] channels;
}
