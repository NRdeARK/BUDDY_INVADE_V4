#pragma once
#include <iostream>
#include <fstream>

#include "Screen.h"
#include "Control.h"
class Scoreboard
{
private:
	int isrunning = 1;
public:
	//Constructor/Deconstructor
	Scoreboard();
	
	//Accessor
	bool isRunning();

	//Class
	Screen screen;
	Control control;
	//Variable
	struct player
	{
		std::string name[5] = 
		{
			"NULL","NULL","NULL","NULL","NULL"
		};
		int score[5] =
		{
			0,0,0,0,0
		};
	};
	player playerlist;
	std::string boardtext;
	std::string name = "";
	//Function
	void getList();
	void pushList();
	void showLeaderboard();
	void waitInput();
	bool can_be_added(int score);
	void getName();
	void addScore(std::string name,int score); 
};

