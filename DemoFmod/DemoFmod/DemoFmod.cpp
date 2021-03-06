// DemoFmod.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//
#include "WrapperFMOD.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>


void printMenu();
void ClearScreen();
void LoadSound();
void PauseChannel();
void ResumeChannel();
void StopChannel();
void PlaySound();
void SetVolume();
void SetPan();
void SleepUI(int millis);

WrapperFMOD wrapper(10);

int main()
{
	if (!wrapper.isWrapperOk())
	{
		std::cout << "Could not start FMOD, sorry :(" << std::endl;
		exit(0);
	}

	while (true)
	{
		ClearScreen();
		printMenu();
		int command;
		while (!(std::cin >> command)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input.  Try again: ";
		}
		switch (command) {
		case 0:
			LoadSound();
			break;
		case 1:
			PlaySound();
			break;
		case 2:
			PauseChannel();
			break;
		case 3:
			ResumeChannel();
			break;
		case 4:
			StopChannel();
			break;
		case 5:
			SetVolume();
			break;
		case 6:
			SetPan();
			break;
		case 7:
			exit(0);
			break;
		default:
			std::cout << "Please enter a valid choice" << std::endl;
			SleepUI(2000);
			break;
		}
	}

}



void printMenu()
{
	std::cout << "______                      _________  ______________   _    _                                 " << std::endl;
	std::cout << "|  _  \\                     |  ___|  \\/  |  _  |  _  \\ | |  | |                                " << std::endl;
	std::cout << "| | | |___ _ __ ___   ___   | |_  | .  . | | | | | | | | |  | |_ __ __ _ _ __  _ __   ___ _ __ " << std::endl;
	std::cout << "| | | / _ \\ '_ ` _ \\ / _ \\  |  _| | |\\/| | | | | | | | | |/\\| | '__/ _` | '_ \\| '_ \\ / _ \\ '__|" << std::endl;
	std::cout << "| |/ /  __/ | | | | | (_) | | |   | |  | \\ \\_/ / |/ /  \\  /\\  / | | (_| | |_) | |_) |  __/ |   " << std::endl;
	std::cout << "|___/ \\___|_| |_| |_|\\___/  \\_|   \\_|  |_/\\___/|___/    \\/  \\/|_|  \\__,_| .__/| .__/ \\___|_|   " << std::endl;
	std::cout << "                                                                        | |   | |              " << std::endl;
	std::cout << "                                                                        |_|   |_|              " << std::endl;
	std::cout << "       //======[]====================\\\\" << std::endl;
	std::cout << "       || Key  ||      Command       ||" << std::endl;
	std::cout << "       |]======[]====================[|" << std::endl;
	std::cout << "       ||    0 || Load sound         ||" << std::endl;
	std::cout << "       ||    1 || Play sound         ||" << std::endl;
	std::cout << "       ||    2 || Pause sound        ||" << std::endl;
	std::cout << "       ||    3 || Resume sound       ||" << std::endl;
	std::cout << "       ||    4 || Stop sound         ||" << std::endl;
	std::cout << "       ||    5 || Set channel volume ||" << std::endl;
	std::cout << "       ||    6 || Set channel pan    ||" << std::endl;
	std::cout << "       ||    7 || Exit               ||" << std::endl;
	std::cout << "       \\\\======[]====================//" << std::endl;
}


void ClearScreen()
{
#if defined _WIN32
	system("cls");
#elif defined (LINUX) || defined(gnu_linux) || defined(linux)
	system("clear");
#elif defined (APPLE)
	system("clear");
#endif
}

void LoadSound()
{
	std::cout << "Please insert the file path" << std::endl;
	std::cin.ignore();
	std::string path;
	std::getline(std::cin, path);
	std::cout << "Please insert an alias for this file" << std::endl;
	std::string alias;
	std::getline(std::cin, alias);
	std::cout << "Press 0 for static loading, press 1 for streaming loading" << std::endl;
	int streaming = -1;
	while (!(std::cin >> streaming) || streaming < 0 || streaming > 1) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
	if (streaming)
		wrapper.LoadStreaming(path, alias);
	else
		wrapper.LoadStatic(path, alias);
	SleepUI(2000);
}

void PauseChannel()
{
	std::cout << "Please insert channel number" << std::endl;
	std::cin.ignore();
	int channel;
	while (!(std::cin >> channel)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
	wrapper.Pause(channel);
	SleepUI(2000);
}

void ResumeChannel()
{
	std::cout << "Please insert channel number" << std::endl;
	std::cin.ignore();
	int channel;
	while (!(std::cin >> channel)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
	wrapper.Resume(channel);
	SleepUI(2000);

}

void StopChannel()
{
	std::cout << "Please insert channel number to stop" << std::endl;
	int channel;
	while (!(std::cin >> channel)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
	wrapper.Stop(channel);
	SleepUI(2000);
}

void PlaySound()
{
	std::cout << "Please insert channel number" << std::endl;
	int channel;
	while (!(std::cin >> channel)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
	std::cout << "Please insert the alias of the sound to play" << std::endl;
	std::string alias;
	std::cin >> alias;

	std::cout << "Press 0 for oneShoot play, press 1 for loop play" << std::endl;
	int loop = -1;
	while (!(std::cin >> loop) || loop < 0 || loop > 1) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
	if (loop)
		wrapper.PlayLoop(channel, alias);
	else
		wrapper.PlayOneShoot(channel, alias);

	SleepUI(2000);
}

void SetVolume()
{
	std::cout << "Please insert which channel to set the volume" << std::endl;
	int channel;
	while (!(std::cin >> channel)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}

	float volume;
	while (!(std::cin >> volume)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
	wrapper.SetVolume(channel, volume);
	SleepUI(2000);
}

void SetPan()
{
	std::cout << "Please insert which channel to set the pan" << std::endl;
	int channel;
	while (!(std::cin >> channel)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}

	float pan;
	while (!(std::cin >> pan)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}


	std::cout << "Press 0 for left pan, press 1 for right pan" << std::endl;

	int left = -1;
	while (!(std::cin >> left) || left < 0 || left > 1) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
	if (left)
		wrapper.PanLeft(channel, pan);
	else
		wrapper.PanRight(channel, pan);
	SleepUI(2000);
}

void SleepUI(int millis)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(millis));
}
