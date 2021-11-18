#define _CRT_SECURE_NO_WARNINGS
//#include "Screen.h"
#include <iostream>
#include <String.h>
#include <windows.h>
#include <time.h>

#include "Screen.h"
#include "Game.h"
#include "Menu.h"
#include "Scoreboard.h"

const int black = 0;
const int blue = 1;
const int green = 2;
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

Menu menu;

int main()
{
	while (true)
	{
		menu.command = "";
		menu.clearcommand();
		menu.setup();
		while (menu.isRunning())
		{
			menu.clearcommand();
			menu.inputcommand();
		}
		if (menu.command == "play")
		{
			Game game;
			game.gameSetup();
			while (game.isRunning())
			{
				game.displayStatus();
				game.playerControl();
				game.playerDisplay();
				game.updateEnemy();
				game.updateBullet();
				game.createBullet();
				game.createEnemy();
				game.updatePlayer();
				game.updateGameStatus();
				game.updateTime();
			}
			Scoreboard lead;
			if (lead.can_be_added(game.point))
			{
				lead.getName();
				lead.addScore(lead.name, game.point);
				lead.pushList();
				lead.showLeaderboard();
				while (lead.isRunning())
				{
					lead.waitInput();
				}
			}
			menu.command = "";
		}
		if (menu.command == "help")
		{
			menu.screen.drawSquare(0, 0, screen_x, screen_y, 0, 0);
			menu.screen.string_to_buffer(screen_x - 50, 1, "Nataphan Rakvidhyasatra 64010223", 0, 7);
			menu.screen.drawLogo(20, 5, 10, 0);
			menu.screen.string_to_buffer(20, 20, "play :: to play game", 10, 0);
			menu.screen.string_to_buffer(20, 22, "lead :: to check leaderboard", 10, 0);
			menu.screen.string_to_buffer(20, 24, "exit :: to exit program", 10, 0);
			menu.screen.string_to_buffer(20, 26, "help :: to check manual command", 10, 0);
			menu.screen.string_to_buffer(20, 26, "help :: to check manual command", 10, 0);
			menu.screen.string_to_buffer(20, 30, "player controls", 10, 0);
												// 12345  12345 12345 123451234512345
			menu.screen.string_to_buffer(20, 31, "        _____                   _____                     ", 10, 0);
			menu.screen.string_to_buffer(20, 32, "       |  W  |                 | esc |             ", 10, 0);
			menu.screen.string_to_buffer(20, 33, "        _____                   _____            ", 10, 0);
			menu.screen.string_to_buffer(20, 35, "          up                  pause/exit        ", 10, 0);
			menu.screen.string_to_buffer(20, 36, " _____  _____  _____     ___________________              ", 10, 0);
			menu.screen.string_to_buffer(20, 37, "|  A  ||  S  ||  D  |   |       space       | ", 10, 0);
			menu.screen.string_to_buffer(20, 38, " _____  _____  _____     ___________________           ", 10, 0);
			menu.screen.string_to_buffer(20, 40, "  left   down  right            shoot            ", 10, 0);
			
			menu.screen.string_to_buffer(70, 32, "SOUL    STONE : REVIVING", 10, 0);
			menu.screen.string_to_buffer(70, 33, "TIME    STONE : DELAY TIME", 10, 0);
			menu.screen.string_to_buffer(70, 34, "SPACE   STONE : INCREASE HP", 10, 0);
			menu.screen.string_to_buffer(70, 35, "MIND    STONE : AMPIFY", 10, 0);
			menu.screen.string_to_buffer(70, 36, "REALITY STONE : ohqqlvfguebjre 13", 10, 0);
			menu.screen.string_to_buffer(70, 37, "POWER   STONE : INCREASE ATK", 10, 0);
			        
			menu.screen.char_to_buffer(68, 32, 254, yellow, 0);
			menu.screen.char_to_buffer(68, 33, 254, green, 0);
			menu.screen.char_to_buffer(68, 34, 254, blue, 0);
			menu.screen.char_to_buffer(68, 35, 254, light_yellow, 0);
			menu.screen.char_to_buffer(68, 36, 254, red, 0);
			menu.screen.char_to_buffer(68, 37, 254, purple, 0);

			menu.screen.buffer_to_console();
			menu.screen.buffer_to_console();
			menu.screen.control.collectedData = "";
			while (true)
			{
				menu.screen.control.input();
				if (menu.screen.control.collectedData != "")
				{
					break;
				}
			}
			menu.command = "";
		}
		if (menu.command == "exit")
		{
			break;
		}
		if (menu.command == "lead")
		{
			Scoreboard lead;
			lead.getList();
			lead.showLeaderboard();
			while (lead.isRunning())
			{
				lead.waitInput();
			}
			lead.pushList();
			menu.command = "";
		}
	}
	

}