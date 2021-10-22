#pragma once
#include <iostream> 
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

#include "Control.h"
#include "Screen.h"

#define screen_x 236
#define screen_y 62

class Player
{
	

private:
	//Variable
	
	

	struct Secretpin
	{
		bool B = 0;
		bool U = 0;
		bool D = 0;
		bool Y = 0;

		bool I = 0;
		bool S = 0;

		bool T = 0;
		bool H = 0;
		bool R = 0;
		bool O = 0;
		bool W = 0;
		bool E = 0;
	};
	Secretpin secretpin;


public:
	//Construcotr/Deconstructor
	Player();

	//Class
	Control control;

	//Variable

	COORD characterPos;
	COORD oldCharacterPos;

	struct infinityStone
	{
		bool soul_stone = 0;
		bool power_stone = 0;
		bool time_stone = 0;
		bool mind_stone = 0;
		bool reality_stone = 0;
		bool space_stone = 0;
	};
	infinityStone gem;

	struct playerState
	{
		bool isPause = 0;
		bool isAlive = 1;
		bool isVisible = 1;
	};
	playerState state;

	struct playerStat
	{
		int level = 0;
		int exp = 0;
		int expLimit = 0;
		int baseAttack = 1;
		int baseHp = 3;
		int playerHp = 3;
		int playerMaxHp = 3;
	};
	playerStat stat;

	int not_added_point = 0;
	bool position_is_Update = 0;
	bool space_is_Pressed = 0;
	std::string command = "";

	//Function

	void decreseHp(int amount);

	void control_to_command();
	void doCommand();

	bool checkEasterEgg();

	int updatelevel(int score);
	int updateHp(); 
	void updateBaseStat();
	void updateCharacterPos(int x,int y);
};

