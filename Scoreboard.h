#pragma once
#include <iostream>
#include <fstream>
#include<vector>

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
	struct playerlisting
	{
		std::vector<std::string> name =
		{
			"NULL","NULL","NULL","NULL","NULL"
		};
		std::vector <int> score =
		{
			0,0,0,0,0
		};
	};
	playerlisting playerlist;
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

