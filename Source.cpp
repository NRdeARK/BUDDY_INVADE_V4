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
Menu menu;

int main()
{
	while (true)
	{
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
		}
	}
	

}