#ifndef CONSOLE_ROGUELIKE_CPP_UTILITY_H
#define CONSOLE_ROGUELIKE_CPP_UTILITY_H

#include <string>
#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <vector>
#include <conio.h>


using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using namespace std;

#define TurnBlack SetConsoleTextAttribute(hConsole, 0)
#define TurnBlue SetConsoleTextAttribute(hConsole, 1)
#define TurnGreen SetConsoleTextAttribute(hConsole, 2)
#define TurnAqua SetConsoleTextAttribute(hConsole, 3)
#define TurnLightRed SetConsoleTextAttribute(hConsole, 4)
#define TurnMagenta SetConsoleTextAttribute(hConsole, 5)
#define TurnYellow SetConsoleTextAttribute(hConsole, 6)
#define TurnWhite SetConsoleTextAttribute(hConsole, 7)
#define TurnGrey   SetConsoleTextAttribute(hConsole, 8)        //BrightBlack
#define TurnBrightBlue SetConsoleTextAttribute(hConsole, 9)
#define TurnBrightGreen SetConsoleTextAttribute(hConsole, 10)
#define TurnBrightAqua SetConsoleTextAttribute(hConsole, 11)
#define TurnBrightWhite etConsoleTextAttribute(hConsole, 15)
// >15 changes font background add if u want

void InitializeSettings();



#endif //CONSOLE_ROGUELIKE_CPP_UTILITY_H
