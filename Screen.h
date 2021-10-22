#pragma once

#include <iostream> 
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

#include "Control.h"

#define screen_x 236
#define screen_y 62



class Screen
{
private:
	//Variable
	HANDLE rHnd;
	HANDLE wHnd;
	CHAR_INFO consoleBuffer[screen_x * screen_y];
	DWORD fdwMode;
	COORD bufferSize = { screen_x,screen_y };
	SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };
	DWORD numEvents = 0;
	DWORD numEventsRead = 0;

public:
	//Constructor/Deconstructor
	Screen();
	
	//Class
	Control control;

	//Variable
	std::string collectedText;
	
	//setup
	COORD characterPos;
	
	//Cursor
	struct Cursor
	{
		COORD pos;
		int fg;
		int bg;
		bool isVisible;
	};
	Cursor cursor{{0,0},0,0,0 };

	//Ship
	struct Ship
	{
		char chr[8] =
		{
			'|',
			'-','o',
			'+','>',
			'-','o',
			'|'
		};
		int fg[8] =
		{
			7,
			7,7,
			7,7,
			7,7,
			7
		};
		int bg[8] =
		{
			0,
			0,0,
			0,0,
			0,0,
			0
		};

	};
	Ship ship;
	int shipLevel = 0;
	int id = 0;
	char chrship[3][8] =
	{
		{
			'|',
			'-','o',
			'+','>',
			'-','o',
			'|'
		},
		{
			'\\',
			'-','>',
			'|',' ',
			'-','>',
			'/'
		},
		{
			'/',
			'+','>',
			'>',' ',
			'+','>',
			'\\'
		}

	};
	int fgship[3][8] =
	{
		{
			7,
			7,7,
			7,4,
			7,7,
			7
		},
		{
			7,
			7,4,
			7,7,
			7,4,
			7
		},
		{
			7,
			7,4,
			4,7,
			7,4,
			7
		}
	};
	int bgship[3][8] =
	{
		{
			0,
			0,0,
			0,0,
			0,0,
			0
		},
		{
			0,
			0,0,
			0,0,
			0,0,
			0
		},
		{
			0,
			0,0,
			0,0,
			0,0,
			0
		}
	};

	//Colour code
	const int black = 0;
	const int blue = 1;
	const int greem = 2;
	const int aqua = 3;
	const int red = 4;
	const int purple = 5;
	const int yellow = 6;
	const int white = 7;
	const int gray = 8;
	const int light_blue = 9;
	const int light_green = 10;
	const int lgiht_aqua = 11;
	const int lgiht_red = 12;
	const int light_purple = 13;
	const int light_yellow = 14;
	const int ligth_white = 15;

	//Function
	
	//Function set mode
	int setMode();
	int setConsole(int x, int y);

	//Function screen management
	void char_to_buffer(int x, int y, char chr, int fg, int bg);
	void string_to_buffer(int x, int y, std::string word, int fg, int bg);
	void buffer_to_console();
	void erase_char_from_buffer(int x, int y, int fg, int bg);
	void erase_string_from_buffer(int x, int y, int lenght, int fg, int bg);
	char char_from_console(int x, int y);
	void drawSquare(int x, int y, int lenght, int breath, int fg, int bg);
	void clearbuffer();

	//Function about cursor
	void set_cursor_pos(int x, int y);
	void set_cursor_color(int fg, int bg);
	void set_cursor_visible(bool visible);

	//Function about menu 
	void drawLogo(int x, int y, int fg, int bg);
	void openTextbox(int x,int y);
	void writeTextbox();
	void closeTextbox();

	//function about display player
	void player_to_buffer(COORD playerPos);
	void erase_player_from_buffer(COORD oldplayerPos);
	void update_ship_level(int shipLevel);
	char char_from_player(COORD playerPos, int num);

};

