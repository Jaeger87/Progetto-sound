// DemoFmod.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//
#include "WrapperFMOD.h"
#include <iostream>
#include <chrono>
#include <thread>


void printMenu();
void ClearScreen();
void LoadSound();
void PauseChannel();
void StopChannel();
void PlaySound();
void SetVolume();
void SetPan();

WrapperFMOD wrapper(10);

int main()
{
	if (!wrapper.isWrapperOk())
	{
		std::cout << "Could not start FMOD, sorry :(" << std::endl;
		exit(0);
	}

	wrapper.LoadStatic("Media/Success.wav", "Success");

	wrapper.PlayOneShoot(0, "Success");

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
			StopChannel();
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			exit(0);
			break;
		default:
			std::cout << "Please enter a valid choice" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
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
	std::cout << "       ||    3 || Stop sound        ||" << std::endl;
	std::cout << "       ||    4 || Set channel volume ||" << std::endl;
	std::cout << "       ||    5 || Set channel pan    ||" << std::endl;
	std::cout << "       ||    6 || Exit               ||" << std::endl;
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
	std::string path;
	std::cin >> path;
	std::cout << "Please insert an alias for this file" << std::endl;
	std::string alias;
	std::cin >> alias;
	std::cout << "Press 0 for static loading, press 1 for streaming loading" << std::endl;
	int streaming = -1;
	while (!(std::cin >> streaming) || streaming < 0 || streaming > 1 ) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
	if (streaming)
		wrapper.LoadStreaming(path, alias);
	else
		wrapper.LoadStatic(path, alias);

}

void PauseChannel()
{
	std::cout << "Please insert channel number" << std::endl;
	int channel;
	while (!(std::cin >> channel)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
	wrapper.Pause(channel);
}

void StopChannel()
{
	std::cout << "Please insert channel number" << std::endl;
	int channel;
	while (!(std::cin >> channel)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
	wrapper.Stop(channel);
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
}

void SetVolume()
{
}

void SetPan()
{
}
