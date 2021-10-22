#pragma once
#include "Player.h"
#include "Screen.h"
#include "Enemy.h"
#include "Bullet.h"
class Game
{
private:
	bool runningStatus=1;

	// - status of stone
	int space_stone = 0;
	int mind_stone = 0;
	int reality_stone = 0;
	int power_stone = 0;
	int time_stone = 0;
	int soul_stone = 0;
public:
	//Constructor/Deconstructor
	Game();

	//Accessor
	bool isRunning();
	
	//Class
	Player player;
	Screen screen;
	Bullet bullet;
	Enemy enemy;

	
	//Variable
	int main_stage = 1;
	int sub_stage = 1;
	int point = 0;
	long int time = 0;
	long int disappearTime = 0;
	int level = 0;
	int shipLevel = 0;

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
	void gameSetup();
	void playerControl();
	void displayStatus();
	void playerDisplay();
	void updateEnemy();
	void updateBullet();
	void createBullet();
	void createEnemy();
	void updatePlayer();
	void updateGameStatus();
	void updateTime();
};

