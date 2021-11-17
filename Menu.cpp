#include "Menu.h"
#include <windows.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
Menu::Menu()
{
	Screen screen;
}

bool Menu::isRunning()
{
	return runningStatus;
}

void Menu::setup()
{
	screen.drawSquare(0, 0, screen_x, screen_y, 0, 0);
	screen.string_to_buffer(screen_x - 50, 1, "Nataphan Rakvidhyasatra 64010223", 0, 7);
	screen.drawLogo(20, 5, 10, 0);
	//screen.string_to_buffer(25, 20, "play game", 10, 0);
	//screen.string_to_buffer(25, 25, "show leaderboard", 10, 0);
	//screen.string_to_buffer(25, 30, "exit game", 10, 0);
	screen.buffer_to_console();
	screen.set_cursor_color(10, 0);
	clearcommand();
	runningStatus = 1;

}

void Menu::clearcommand()
{
	command = "";
}



void Menu::inputcommand()
{
	screen.erase_string_from_buffer(20, 20, 100, 0, 0);

	screen.string_to_buffer(20, 20, "command:~# ",10,0);
	screen.buffer_to_console();
	while (command == "")
	{
		screen.openTextbox(32, 20);
		screen.writeTextbox(10,0);
		screen.closeTextbox();
		command = screen.collectedText;
	}

	if (command == "play")
	{
		runningStatus = 0;
	}
	else if (command == "lead")
	{
		runningStatus = 0;
	}
	else if (command == "exit")
	{
		runningStatus = 0;
	}
	else if (command == "help")
	{
		runningStatus = 0;
	}
	else
	{
		screen.string_to_buffer(20, 19, "                                                         ", 4, 0);
		screen.string_to_buffer(20, 19, "error: command \"" + command + "\" not found type \"help\" for help", 4, 0);
	}
	screen.buffer_to_console();
}
