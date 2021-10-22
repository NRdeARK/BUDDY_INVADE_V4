#pragma once
#include <windows.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>

#define screen_x 236
#define screen_y 62

class Enemy
{
private:
public:
	//Constructor/Deconstructor
	Enemy();
	
	//Variable
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
	int enemyNum = 0;
	int boss = 0;
	int point_not_add_yet = 0;
	bool obtain_space = 0;
	bool obtain_mind = 0;
	bool obtain_time = 0;
	bool obtain_soul = 0;
	//multi intiallise
	std::vector<COORD> enemyPos;
	std::vector<int> enemyTag;
	std::vector<int> enemychar;
	std::vector<int> enemyfg;
	std::vector<int> enemybg;
	//single initiallise
	std::vector<int> enemyHealth;
	std::vector<int> enemyScore;
	std::vector<std::string>enemyType;

	//Function
	void createEnemy(int limitSize, std::string type);
	void updateEnemyPos();
	void updateEnemyTag();
	bool decreseEnemyHealth(int tag, int damage);
	std::vector<COORD> get_xy_pos_from_tag(int tag);
	int get_Tag_from_xy(int x, int y);
	void deleteEnemybyTag(int tag);




};
