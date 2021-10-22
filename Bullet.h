#pragma once

#include <windows.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>

class Bullet
{
private:

public:
	//Constructor/Deconstructor
	Bullet();


	//Variable
	std::vector<COORD> bulletPos;
	std::vector<COORD> old_bulletPos;
	std::vector<char> bulletchar;
	std::vector<int> colour;

	int maxBullet = 5;
	int bulletNum = 0;
	int shipLevel = 0;

	//Function
	void updateLevel(int score);
	void update_ship_level(int gemNum);
	void createBullet(int x, int y);
	void update_bullet_position(int x, int y);
	void deletebullet(int x, int y);


};