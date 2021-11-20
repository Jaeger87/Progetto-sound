// DemoFmod.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//
#include "WrapperFMOD.h"
#include <iostream>

void printMenu();
void ClearScreen();

int main()
{
    WrapperFMOD wrapper(10);

    if (!wrapper.isWrapperOk())
    {

    }

    wrapper.LoadStatic("Media/Success.wav", "Success");



    wrapper.PlayOneShoot(0, "Success");
    printMenu();
    while (true)
    {
    }

}



void printMenu()
{
    std::cout << "______                      _________  ______________   _    _                                 "<< std::endl;
    std::cout << "|  _  \\                     |  ___|  \\/  |  _  |  _  \\ | |  | |                                "<< std::endl;
    std::cout << "| | | |___ _ __ ___   ___   | |_  | .  . | | | | | | | | |  | |_ __ __ _ _ __  _ __   ___ _ __ " << std::endl;
    std::cout << "| | | / _ \\ '_ ` _ \\ / _ \\  |  _| | |\\/| | | | | | | | | |/\\| | '__/ _` | '_ \\| '_ \\ / _ \\ '__|" << std::endl;
    std::cout << "| |/ /  __/ | | | | | (_) | | |   | |  | \\ \\_/ / |/ /  \\  /\\  / | | (_| | |_) | |_) |  __/ |   " << std::endl;
    std::cout << "|___/ \\___|_| |_| |_|\\___/  \\_|   \\_|  |_/\\___/|___/    \\/  \\/|_|  \\__,_| .__/| .__/ \\___|_|   " << std::endl;
    std::cout << "                                                                        | |   | |              " << std::endl;
    std::cout << "                                                                        |_|   |_|              " << std::endl;
    std::cout << "       //======[]====================\\\\"<< std::endl;
    std::cout << "       || Key  ||      Command       ||"<< std::endl;
    std::cout << "       |]======[]====================[|"<< std::endl;
    std::cout << "       ||    0 || Load sound         ||"<< std::endl;
    std::cout << "       ||    1 || Play sound         ||"<< std::endl;
    std::cout << "       ||    2 || Pause sound        ||"<< std::endl;
    std::cout << "       ||    3 || Set channel volume ||"<< std::endl;
    std::cout << "       ||    4 || Set channel pan    ||"<< std::endl;
    std::cout << "       ||    5 || Exit               ||"<< std::endl;
    std::cout << "       \\\\======[]====================//"<< std::endl;
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