#pragma once
#include <windows.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>

#include "Screen.h"
#include "Control.h"

#define screen_x 236
#define screen_y 62

class Menu
{
public:
	//Constructor/Deconstrucotr
	Menu();

	//Accessor
	bool isRunning();

	//Class
	Screen screen;

	//public variable
	std::string command;
	bool isEnter = 0;

	//Public function
	void setup();
	void inputcommand();
	void clearcommand();



private:
	bool runningStatus = 1;
	//Private variable
	bool click = 0;
	int mouse_x = 0;
	int mouse_y = 0;
	HANDLE rHnd;
	HANDLE wHnd;
	CHAR_INFO consoleBuffer[screen_x * screen_y];
	DWORD fdwMode;
	COORD bufferSize = { screen_x,screen_y };
	SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };
	DWORD numEvents = 0;
	DWORD numEventsRead = 0;
};