#pragma once
#include <iostream> 
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

#define screen_x 236
#define screen_y 62

class Control
{
	
private:

	//Variable 
	HANDLE rHnd;
	HANDLE wHnd;
	CHAR_INFO consoleBuffer[screen_x * screen_y];// screen buffer 
	DWORD fdwMode;
	COORD bufferSize = { screen_x, screen_y };
	SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };
	DWORD numEvents = 0;
	DWORD numEventsRead = 0;

	//Funtion
	int setMode();
	int setConsole(int x, int y);

public:
	//Construct/Deconstruct
	Control();

	//Variable 
	std::string collectedData;
	int mouse_x, mouse_y;

	//Function
	bool input();
	std::string stringFromInput();
	
};

