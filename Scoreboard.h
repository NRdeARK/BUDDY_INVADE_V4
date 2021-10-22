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
	//Variable
	
	std::string boardtext;
	//Function
	void showLeaderboard();
	void addScore();



	//
};

