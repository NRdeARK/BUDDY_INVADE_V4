#include "Bullet.h"

void Bullet::updateLevel(int score)
{
	int expRemain = score;
	int expPassPoint = 9;
	int level = 0;
	while (expRemain > expPassPoint)
	{
		level++;
		expRemain -= expPassPoint;
		expPassPoint *= 2;
	}
	level = level;
}

Bullet::Bullet()
{
}

void Bullet::update_ship_level(int gemNum)
{
	int num = gemNum;
	shipLevel = num;
	if (num == 0||num == 1 || num == 2)
	{
		maxBullet = 5;
	}
	if (num == 3 || num == 4)
	{
		maxBullet = 12;
	}
	if (num == 5 || num == 6)
	{
		maxBullet = 30;
	}
}

void Bullet::createBullet(int x, int y)
{
	if (bulletNum < maxBullet)
	{
		COORD temp_bullet_position = { x,y };
		bulletPos.push_back(temp_bullet_position);
		bulletNum++;
	}
}

void Bullet::update_bullet_position(int x, int y)
{
	std::vector<COORD>temp_bullet_pos;
	for (int i = 0; i < bulletPos.size(); i++)
	{
		if (bulletPos[i].X < 235)
		{
			COORD temp_XY = { bulletPos[i].X + x,bulletPos[i].Y + y };
			temp_bullet_pos.push_back(temp_XY);
		}
		else
		{
			bulletNum--;
		}
	}
	old_bulletPos = bulletPos;
	bulletPos = temp_bullet_pos;
}

void Bullet::deletebullet(int x, int y)
{
	for (int i = 0; i < bulletPos.size(); i++)
	{
		if (bulletPos[i].X == x && bulletPos[i].Y == y)
		{
			bulletPos.erase(bulletPos.begin() + i);
			//old_bulletPos.erase(old_bulletPos.begin() + i);
			bulletNum--;
		}
	}
}
