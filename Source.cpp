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