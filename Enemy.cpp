#include "Enemy.h"

Enemy::Enemy()
{

}

void Enemy::createEnemy(int limitSize, std::string type)
{
	if (type == "wall mob")
	{
		int size = rand() % limitSize + 1;

		COORD tempEnemypos{ 235 ,rand() % (50 - size) + 4 };
		enemyHealth.push_back(size * size);
		enemyScore.push_back(size * size);
		enemyType.push_back(type);
		enemyDirection.push_back({ 1,0 });

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < 2 * size; j++)
			{
				if (j == size * 2 - 1)
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(' ');
					enemyfg.push_back(0);
					enemybg.push_back(0);
				}
				else if (j % 2 == 0)
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(4);
					enemyfg.push_back(0);
					enemybg.push_back(7);
				}
				else
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(255);
					enemyfg.push_back(0);
					enemybg.push_back(7);
				}
				tempEnemypos.X = tempEnemypos.X + 1;
			}
			tempEnemypos.Y = tempEnemypos.Y + 1;
			if (tempEnemypos.X == 235 + size * 2)
			{
				tempEnemypos.X = tempEnemypos.X - size * 2;
			}
		}
		enemyNum++;
	}
	if (type == "cross mob")
	{
		int size = rand() % limitSize + 1;
		if (size == 3)
		{
			size++;
		}
		COORD tempEnemypos{ 235 ,rand() % (50 - size) + 4 };
		enemyHealth.push_back(size);
		enemyScore.push_back(size * size);
		enemyType.push_back(type);
		if (rand()%2==0)
		{
			enemyDirection.push_back({ 1,1 });
		}
		else
		{
			enemyDirection.push_back({ 1,-1 });
		}
		

		///" 2 2"
		///"22222"
		///   2
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (j == size * 2 - 1)
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(' ');
					enemyfg.push_back(0);
					enemybg.push_back(0);
				}
				else if (j % 2 == 0)
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(3);
					enemyfg.push_back(4);
					enemybg.push_back(7);
				}
				else
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(255);
					enemyfg.push_back(0);
					enemybg.push_back(7);
				}
				tempEnemypos.X = tempEnemypos.X + 1;
			}
			tempEnemypos.Y = tempEnemypos.Y + 1;
			if (tempEnemypos.X == 235 + 2)
			{
				tempEnemypos.X = tempEnemypos.X - 2;
			}
		}
		
		enemyNum++;
	}
	if (type == "wall")
	{
		int size = rand() % limitSize + 1;

		COORD tempEnemypos{ 235 ,rand() % (50 - size) + 4 };
		enemyHealth.push_back(999);
		enemyScore.push_back(size * size);
		enemyType.push_back(type);
		enemyDirection.push_back({ 1,0 });

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < 2 * size; j++)
			{
				if (j == size * 2 - 1)
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(' ');
					enemyfg.push_back(0);
					enemybg.push_back(0);
				}
				else if (j % 2 == 0)
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(177);
					enemyfg.push_back(0);
					enemybg.push_back(7);
				}
				else
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(177);
					enemyfg.push_back(0);
					enemybg.push_back(7);
				}
				tempEnemypos.X = tempEnemypos.X + 1;
			}
			tempEnemypos.Y = tempEnemypos.Y + 1;
			if (tempEnemypos.X == 235 + size * 2)
			{
				tempEnemypos.X = tempEnemypos.X - size * 2;
			}
		}
		enemyNum++;
	}
	if (type == "wall_top")
	{
		int size = rand() % limitSize + 1;
		COORD tempEnemypos{ 235 ,12 };
		enemyHealth.push_back(999);
		enemyScore.push_back(size * size);
		enemyType.push_back(type);
		enemyDirection.push_back({ 1,0 });

		for (int i = 0; i < 47; i++)
		{
			for (int j = 0; j < 2 * size; j++)
			{
				if (j == size * 2 - 1)
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(' ');
					enemyfg.push_back(0);
					enemybg.push_back(0);
				}
				else if (j % 2 == 0)
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(177);
					enemyfg.push_back(0);
					enemybg.push_back(7);
				}
				else
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(177);
					enemyfg.push_back(0);
					enemybg.push_back(7);
				}
				tempEnemypos.X = tempEnemypos.X + 1;
			}
			tempEnemypos.Y = tempEnemypos.Y + 1;
			if (tempEnemypos.X == 235 + size * 2)
			{
				tempEnemypos.X = tempEnemypos.X - size * 2;
			}
		}
		enemyNum++;
	}
	if (type == "wall_bot")
	{
		int size = rand() % limitSize + 1;
		COORD tempEnemypos{ 235 ,3 };
		enemyHealth.push_back(999);
		enemyScore.push_back(size * size);
		enemyType.push_back(type);
		enemyDirection.push_back({ 1,0 });

		for (int i = 0; i < 47; i++)
		{
			for (int j = 0; j < 2 * size; j++)
			{
				if (j == size * 2 - 1)
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(' ');
					enemyfg.push_back(0);
					enemybg.push_back(0);
				}
				else if (j % 2 == 0)
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(177);
					enemyfg.push_back(0);
					enemybg.push_back(7);
				}
				else
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(177);
					enemyfg.push_back(0);
					enemybg.push_back(7);
				}
				tempEnemypos.X = tempEnemypos.X + 1;
			}
			tempEnemypos.Y = tempEnemypos.Y + 1;
			if (tempEnemypos.X == 235 + size * 2)
			{
				tempEnemypos.X = tempEnemypos.X - size * 2;
			}
		}
		enemyNum++;
	}
	if (type == "wall_mid")
	{
		int size = rand() % limitSize + 1;
		COORD tempEnemypos{ 235 ,3 };
		enemyHealth.push_back(999);
		enemyScore.push_back(size * size);
		enemyType.push_back(type);
		enemyDirection.push_back({ 1,0 });

		for (int i = 0; i < 23; i++)
		{
			for (int j = 0; j < 2 * size; j++)
			{
				if (j == size * 2 - 1)
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(' ');
					enemyfg.push_back(0);
					enemybg.push_back(0);
				}
				else if (j % 2 == 0)
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(177);
					enemyfg.push_back(0);
					enemybg.push_back(7);
				}
				else
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(177);
					enemyfg.push_back(0);
					enemybg.push_back(7);
				}
				tempEnemypos.X = tempEnemypos.X + 1;
			}
			tempEnemypos.Y = tempEnemypos.Y + 1;
			if (tempEnemypos.X == 235 + size * 2)
			{
				tempEnemypos.X = tempEnemypos.X - size * 2;
			}
		}
		tempEnemypos={ 235 , 36};
		for (int i = 0; i < 23; i++)
		{
			for (int j = 0; j < 2 * size; j++)
			{
				if (j == size * 2 - 1)
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(' ');
					enemyfg.push_back(0);
					enemybg.push_back(0);
				}
				else if (j % 2 == 0)
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(177);
					enemyfg.push_back(0);
					enemybg.push_back(7);
				}
				else
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(177);
					enemyfg.push_back(0);
					enemybg.push_back(7);
				}
				tempEnemypos.X = tempEnemypos.X + 1;
			}
			tempEnemypos.Y = tempEnemypos.Y + 1;
			if (tempEnemypos.X == 235 + size * 2)
			{
				tempEnemypos.X = tempEnemypos.X - size * 2;
			}
		}
		enemyNum++;
	}
	if (type == "wall of buddy")
	{
		int size = 49;
		COORD tempEnemypos{ 235 ,6 };
		enemyHealth.push_back(999);
		enemyScore.push_back(999);
		enemyType.push_back(type);
		enemyDirection.push_back({ 1,0 });

		int crossx1 = 0;
		int crossy1 = 0;
		int crossx2 = size * 2 - 2;
		int crossy2 = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < 2 * size; j++)
			{

				if (j == size * 2 - 1)
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(' ');
					enemyfg.push_back(0);
					enemybg.push_back(0);
				}
				else if (j % 2 == 0)
				{
					if (i == crossy1 && j == crossx1 && i == crossy2 && j == crossx2)
					{
						enemyPos.push_back(tempEnemypos);
						enemyTag.push_back(enemyNum);
						enemychar.push_back(4);
						enemyfg.push_back(2);
						enemybg.push_back(0);
						crossx1 += 2;
						crossy1 += 1;
						crossx2 -= 2;
						crossy2 += 1;
					}
					else if (i == crossy1 && j == crossx1)
					{
						enemyPos.push_back(tempEnemypos);
						enemyTag.push_back(enemyNum);
						enemychar.push_back(4);
						enemyfg.push_back(9);
						enemybg.push_back(9);
						crossx1 += 2;
						crossy1 += 1;
					}
					else if (i == crossy2 && j == crossx2)
					{
						enemyPos.push_back(tempEnemypos);
						enemyTag.push_back(enemyNum);
						enemychar.push_back(4);
						enemyfg.push_back(4);
						enemybg.push_back(4);
						crossx2 -= 2;
						crossy2 += 1;
					}
					else if (i == 24 || (j == 48 && i % 2 != 1))
					{
						enemyPos.push_back(tempEnemypos);
						enemyTag.push_back(enemyNum);
						enemychar.push_back(4);
						enemyfg.push_back(6);
						enemybg.push_back(6);
					}
					else
					{
						enemyPos.push_back(tempEnemypos);
						enemyTag.push_back(enemyNum);
						enemychar.push_back(7);
						enemyfg.push_back(0);
						enemybg.push_back(7);
					}

				}
				else
				{
					enemyPos.push_back(tempEnemypos);
					enemyTag.push_back(enemyNum);
					enemychar.push_back(255);
					enemyfg.push_back(0);
					enemybg.push_back(7);
				}
				tempEnemypos.X = tempEnemypos.X + 1;
			}
			tempEnemypos.Y = tempEnemypos.Y + 1;
			if (tempEnemypos.X == 235 + size * 2)
			{
				tempEnemypos.X = tempEnemypos.X - size * 2;
			}
		}
		enemyNum++;
	}


}

void Enemy::updateEnemyPos()
{
	for (int i = 0; i < enemyPos.size(); i++)
	{
		enemyPos[i].X = enemyPos[i].X - enemyDirection[enemyTag[i]].X;
		enemyPos[i].Y = enemyPos[i].Y - enemyDirection[enemyTag[i]].Y;
	}

	std::vector<COORD> tempenemyPos = enemyPos;
	std::vector<int> tempenemyTag = enemyTag;
	std::vector<int> tempenemychar = enemychar;
	std::vector<int> tempenemyfg = enemyfg;
	std::vector<int> tempenemybg = enemybg;

	std::vector<int> tempenemyHealth = enemyHealth;
	std::vector<int> tempenemyScore = enemyScore;
	std::vector<std::string> tempenenmytype = enemyType;
	std::vector<COORD> tempenemyDirection = enemyDirection;

	
	int j = 0;
	int havechange = 0;
	for (int i = 0; i < enemyPos.size(); i++)
	{
		if (i != 0)
		{
			if (havechange == 1 && tempenemyTag[i - 1] != tempenemyTag[i])
			{
				havechange = 0;
			}
		}

		if ((tempenemyPos[i].Y == 3 || tempenemyPos[i].Y == 58))
		{
			if (havechange == 0)
			{
				tempenemyDirection[tempenemyTag[i]].Y = tempenemyDirection[tempenemyTag[i]].Y * (-1);
				havechange = 1;
			}
		}
	}
	for (int i = 0; i < enemyPos.size(); i++)
	{
		
		if (enemyPos[i].X == -1)
		{	
			// if last block of that mob gone delete that mob
			if (tempenemyTag[j] != tempenemyTag[j + 1])
			{
				tempenemyHealth.erase(tempenemyHealth.begin() + tempenemyTag[j]);
				tempenemyScore.erase(tempenemyScore.begin() + tempenemyTag[j]);
				tempenenmytype.erase(tempenenmytype.begin() + tempenemyTag[j]);
				tempenemyDirection.erase(tempenemyDirection.begin() + tempenemyTag[j]);
				enemyNum--;
			}

			// delete that block

			tempenemyPos.erase(tempenemyPos.begin() + j);
			tempenemyTag.erase(tempenemyTag.begin() + j);
			tempenemychar.erase(tempenemychar.begin() + j);
			tempenemyfg.erase(tempenemyfg.begin() + j);
			tempenemybg.erase(tempenemybg.begin() + j);
			
			j--;
		}
		j++;
	}
	enemyPos = tempenemyPos;
	enemyTag = tempenemyTag;
	enemyHealth = tempenemyHealth;
	enemyScore = tempenemyScore;
	enemychar = tempenemychar;
	enemyfg = tempenemyfg;
	enemybg = tempenemybg;
	enemyDirection = tempenemyDirection;
	updateEnemyTag();
}

void Enemy::updateEnemyTag()
{
	int different = 0;
	int old = -1;//kept old
	int order = 0;
	for (int i = 0; i < enemyTag.size(); i++)
	{
		if (old == -1)
		{
			old = enemyTag[i];
		}
		if (old == enemyTag[i])
		{
			enemyTag[i] = order;
		}
		if (old < enemyTag[i])
		{
			old = enemyTag[i];
			order++;
			enemyTag[i] = order;
		}
	}
}

bool Enemy::decreseEnemyHealth(int tag, int damage)
{
	bool death = 0;
	//std::vector<COORD> deletedpos;
	if (tag < enemyHealth.size())
	{
		enemyHealth[tag] = enemyHealth[tag] - damage;
		if (enemyHealth[tag] < 1)
		{
			if (enemyType[tag]== "wall of buddy")
			{
 				boss = 0;
			}
			point_not_add_yet += enemyScore[tag];
			deleteEnemybyTag(tag);
			if (rand() % 10 == 0)
			{
				obtain_mind = 1;
			}
			if (rand() % 10 == 0)
			{
				obtain_soul = 1;
			}
			if (rand() % 10 == 0)
			{
				obtain_time = 1;
			}
			if (rand() % 10 == 0)
			{
				obtain_space = 1;
			}
			death = 1;
		}
	}
	return death;
}

std::vector<COORD> Enemy::get_xy_pos_from_tag(int tag)
{
	std::vector<COORD>  xyPos;
	for (int i = 0; i < enemyTag.size(); i++)
	{
		if (enemyTag[i] == tag)
		{
			xyPos.push_back(enemyPos[i]);
		}
	}
	return xyPos;
}

int Enemy::get_Tag_from_xy(int x, int y)
{
	int tag = 0;
	for (int i = 0; i < enemyPos.size(); i++)
	{
		if (enemyPos[i].X == x && enemyPos[i].Y == y)
		{
			tag = enemyTag[i];
		}
	}
	return tag;
}

void Enemy::deleteEnemybyTag(int tag)
{
	std::vector<COORD> tempenemyPos = enemyPos;
	std::vector<int> tempenemyTag = enemyTag;
	std::vector<int> tempenemyHealth = enemyHealth;
	std::vector<int> tempenemyScore = enemyScore;
	std::vector<int> tempenemychar = enemychar;
	std::vector<int> tempenemyfg = enemyfg;
	std::vector<int> tempenemybg = enemybg;
	std::vector<std::string> tempenemytype = enemyType;
	std::vector<COORD> tempenemyDirection = enemyDirection;

	int j = 0;

	for (int i = 0; i < enemyTag.size(); i++)
	{
		if (tempenemyTag[j] == tag)
		{
			tempenemyPos.erase(tempenemyPos.begin() + j);
			tempenemyTag.erase(tempenemyTag.begin() + j);
			tempenemychar.erase(tempenemychar.begin() + j);
			tempenemyfg.erase(tempenemyfg.begin() + j);
			tempenemybg.erase(tempenemybg.begin() + j);
			j--;
		}
		j++;
	}
	tempenemyDirection.erase(tempenemyDirection.begin() + tag);
	tempenemyHealth.erase(tempenemyHealth.begin() + tag);
	tempenemyScore.erase(tempenemyScore.begin() + tag);
	tempenemytype.erase(tempenemytype.begin() + tag);
	enemyNum--;

	enemyPos = tempenemyPos;
	enemyTag = tempenemyTag;
	enemyHealth = tempenemyHealth;
	enemyScore = tempenemyScore;
	enemychar = tempenemychar;
	enemyfg = tempenemyfg;
	enemybg = tempenemybg;
	enemyType = tempenemytype;
	enemyDirection = tempenemyDirection;
	updateEnemyTag();
}

