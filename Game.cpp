#include "Game.h"

Game::Game()
{
}

bool Game::isRunning()
{
	return runningStatus;
}

void Game::gameSetup()
{
	screen.drawSquare(0, 0, screen_x, 3, 7, 7);
	screen.drawSquare(0, screen_y - 3, screen_x, 3, 7, 7);
	//create 5 blank slot for gem
	screen.char_to_buffer(106, 60, 254, 0, 7);
	screen.char_to_buffer(108, 60, 254, 0, 7);
	screen.char_to_buffer(110, 60, 254, 0, 7);
	screen.char_to_buffer(112, 60, 254, 0, 7);
	screen.char_to_buffer(104, 60, 254, 0, 7);
	screen.char_to_buffer(102, 60, 254, 0, 7);
	//set old and new player position start point
	player.oldCharacterPos.X = 20;
	player.oldCharacterPos.Y = 29;
	player.characterPos.X = 20;
	player.characterPos.Y = 29;
	screen.set_cursor_visible(0);
}

void Game::playerControl()
{
	player.control_to_command();
	if (player.position_is_Update)
	{
		screen.erase_player_from_buffer(player.oldCharacterPos);
		screen.player_to_buffer(player.characterPos);
		screen.buffer_to_console();
		player.position_is_Update = 0;
	}
}

void Game::displayStatus()
{
	//display HP
	screen.string_to_buffer(0, 1, "            ", 7, 7);
	screen.string_to_buffer(0, 1, "HP : " + std::to_string(player.stat.playerHp) + " / " + std::to_string(player.stat.playerMaxHp), 4, 7);
	//display LV
	screen.string_to_buffer(0, 0, "        ", 7, 7);
	screen.string_to_buffer(0, 0, "LV : " + std::to_string(player.stat.level), 0, 7);
	screen.string_to_buffer(20, 0, "        ", 7, 7);
	screen.string_to_buffer(20, 0, "shipLV : " + std::to_string(screen.id), 0, 7);
	//display Score
	point += enemy.point_not_add_yet;
	enemy.point_not_add_yet = 0;
	screen.string_to_buffer(screen_x - 15, 0, "             ", 7, 7);
	screen.string_to_buffer(screen_x - 15, 0, "score : " + std::to_string(point), 4, 7);
	//display time
	screen.string_to_buffer(screen_x - 15, 1, "             ", 7, 7);
	screen.string_to_buffer(screen_x - 15, 1, "time : " + std::to_string(time), 2, 7);
	//display space stone
	if (space_stone == 1)
	{
		screen.char_to_buffer(106, 60, 254, 1, 7);
	}
	//display mind stone
	if (mind_stone == 1)
	{
		screen.char_to_buffer(108, 60, 254, 14, 7);
	}
	//display reality stone
	if (reality_stone == 1)
	{
		screen.char_to_buffer(110, 60, 254, 4, 7);
	}
	//display power stone
	if (power_stone == 1)
	{
		screen.char_to_buffer(112, 60, 254, 5, 7);
	}
	//display time stone
	if (time_stone == 1)
	{
		screen.char_to_buffer(104, 60, 254, 2, 7);
	}
	//display soul stone
	if (soul_stone == 1)
	{
		screen.char_to_buffer(102, 60, 254, 6, 7);
	}


	screen.buffer_to_console();
}


void Game::playerDisplay()
{

	if (player.state.isVisible)
	{
		screen.player_to_buffer(player.characterPos);
		screen.buffer_to_console();
	}

	else
	{
		if (time - disappearTime > 10)
		{
			screen.player_to_buffer(player.characterPos);
			screen.buffer_to_console();
			player.state.isVisible = 1;
		}
	}

}

void Game::createBullet()
{
	//if spacebar was pressed
	if (player.space_is_Pressed)
	{
		//if player level 0-2 
		if (bullet.shipLevel == 0 || bullet.shipLevel == 1 || bullet.shipLevel == 2)
		{
			//create 1 bullet
			bullet.createBullet(player.characterPos.X + 3, player.characterPos.Y + 2);
		}
		//if player level 3-4
		else if (bullet.shipLevel == 3 || bullet.shipLevel == 4)
		{
			//create 2 bullet
			bullet.createBullet(player.characterPos.X + 3, player.characterPos.Y + 1);
			bullet.createBullet(player.characterPos.X + 3, player.characterPos.Y + 3);
		}
		//if player level 5-6
		else if (bullet.shipLevel == 5 || bullet.shipLevel == 6)
		{
			//create 3 bullet
			bullet.createBullet(player.characterPos.X + 3, player.characterPos.Y + 1);
			bullet.createBullet(player.characterPos.X + 3, player.characterPos.Y + 2);
			bullet.createBullet(player.characterPos.X + 3, player.characterPos.Y + 3);
		}
		//reset variable
		player.space_is_Pressed = 0;
	}

}


void Game::createEnemy()
{
	int sizelim;
	int spawnTime;
	if (time < 500)
	{
		spawnTime = 500;
		sizelim = 3;
	}
	else if (time < 2500)
	{
		spawnTime = 350;
		sizelim = 5;
	}
	else if (time < 5000)
	{
		spawnTime = 200;
		sizelim = 7;
	}
	else if (time < 10000)
	{
		spawnTime = 100;
		sizelim = 9;
	}
	else 
	{
		spawnTime = 70;
		sizelim = 20;
	}
	//if time pass 500 +10*timestone ms
	
	if (time % (spawnTime + 10 * time_stone) == 0)
	{
		if (point >= 500 && point < 1000 && enemy.boss == 0)
		{
			enemy.createEnemy(sizelim, "wall of buddy");
			enemy.boss = 1;
			screen.erase_string_from_buffer(122, 1, 30, 0, 7);
			screen.string_to_buffer(122,1,"boss is spawned",0,7);
		}
		if (enemy.boss == 0)
		{
			int random = rand() % 10;
			if (random == 0)
			{
				int typeWall = rand() % 5;

				if (typeWall == 0)
				{
					enemy.createEnemy(sizelim, "wall_top");
				}
				else if (typeWall == 1)
				{
					enemy.createEnemy(sizelim, "wall_mid");
				}
				else if (typeWall == 2)
				{
					enemy.createEnemy(sizelim, "wall_bot");
				}
				else if (typeWall >= 3)
				{
					enemy.createEnemy(sizelim, "wall");
				}
			}
			else if(random<=3) 
			{
				enemy.createEnemy(sizelim, "cross mob");
			}
			else
			{
				enemy.createEnemy(sizelim, "wall mob");
			}
			
		}
		else
		{
			enemy.boss = 0;
			for (int i = 0; i < enemy.enemyType.size(); i++)
			{
				if (enemy.enemyType[i] == "wall of buddy")
				{
					enemy.boss =1;
					break;
				}
			}
		}
	}
}

void Game::updateEnemy()
{
	int updateTime;
	
	if (enemy.boss==0)
	{
		if (time < 500)
		{
			updateTime = 15;
		}
		else if (time < 1500)
		{
			updateTime = 13;
		}
		else if (time < 3000)
		{
			updateTime = 10;
		}
		else if (time < 4500)
		{
			updateTime = 7;
		}
		else if (time < 5000)
		{
			updateTime = 5;
		}
		else if (time < 6000)
		{
			updateTime = 4;
		}
		else
		{
			updateTime = 2;
		}
	}
	else
	{
		updateTime = 15;
	}
	///every 10 + 2*timestone enemy will update
	if (time % (updateTime + 2 * time_stone) == 0)
	{
		//erase all enemy pos in buffer
		for (int i = 0; i < enemy.enemyPos.size(); i++)
		{
			if (enemy.enemyPos[i].X < screen_x)
			{
				screen.erase_char_from_buffer(enemy.enemyPos[i].X, enemy.enemyPos[i].Y, 7, 0);
			}

		}
		//update the position of enemy
		enemy.updateEnemyPos();
		//draw enemy to the buffer
		for (int i = 0; i < enemy.enemyPos.size(); i++)
		{
			if (enemy.enemyPos[i].X < screen_x)
			{
				screen.char_to_buffer(enemy.enemyPos[i].X, enemy.enemyPos[i].Y, enemy.enemychar[i], enemy.enemyfg[i], enemy.enemybg[i]);
			}
		}
	}
	screen.buffer_to_console();
}

void Game::updateBullet()
{
	
	//loop equal to bullet
	for (int i = 0; i < bullet.old_bulletPos.size(); i++)
	{
		//erase bullet from old bullet pos
		screen.erase_char_from_buffer(bullet.old_bulletPos[i].X, bullet.old_bulletPos[i].Y, 7, 0);
	}
	//loop equal to bullet
	for (int i = 0; i < bullet.bulletPos.size(); i++)
	{
		//get char from bullet position
		char charFromBuffer = screen.char_from_console(bullet.bulletPos[i].X, bullet.bulletPos[i].Y);
		//if char that get from bullet position not equal to null and space
		if (charFromBuffer != 0 && charFromBuffer != ' ')
		{
			//get tag from that bullet position
			int tag = enemy.get_Tag_from_xy(bullet.bulletPos[i].X, bullet.bulletPos[i].Y);
			//get all position of that enemy from tag
			std::vector<COORD> xyPos = enemy.get_xy_pos_from_tag(tag);
			//calculate player damage 
			int damage = (player.stat.baseAttack + power_stone) * (1 + 0.5 * enemy.obtain_mind);
			//decrese enemy HP is HP of that enemy blow 1 return True
			bool enemydeleted = enemy.decreseEnemyHealth(tag, damage);
			//if enemy HP below 1
			if (enemydeleted)
			{
				//loop equal to size of all position of that enemy
				for (int i = 0; i < xyPos.size(); i++)
				{
					//erase enemy from buffer
					screen.erase_char_from_buffer(xyPos[i].X, xyPos[i].Y, 0, 0);
				}
				//fill buffer to console for case that hit the object but object deleted
				screen.buffer_to_console();
			}
			//delete bullet 
			bullet.deletebullet(bullet.bulletPos[i].X, bullet.bulletPos[i].Y);
		}
		//if char get from that position not equal to null and space
		else
		{
			//fill bullet to buffer
			screen.char_to_buffer(bullet.bulletPos[i].X, bullet.bulletPos[i].Y, '>', 7, 0);
		}
	}
	bullet.update_bullet_position(1, 0);
}

void Game::updatePlayer()
{
	bool getdamaged = 0;
	for (int i = 0; i < 8; i++)
	{
		if (screen.chrship[screen.id][i] != screen.char_from_player(player.characterPos, i))
		{
			getdamaged = 1;
		}
	}
	if (getdamaged)
	{
		player.decreseHp(1);
		screen.erase_player_from_buffer(player.characterPos);
		player.state.isVisible = 0;
		disappearTime = time;
	}

	//reality
	if (reality_stone == 0)
	{
		
		if (player.checkEasterEgg())
		{
			screen.erase_string_from_buffer(122, 1, 30, 0, 7);
			screen.string_to_buffer(122, 1, "reality stone aquired", 7, 0);
			player.gem.reality_stone = 1;
			reality_stone = 1;
		}
		screen.char_to_buffer(110, 60, 254, 0, 7);
	}
	else
	{
		
		if (rand() % 1000 == 0)
		{
			if (enemy.enemyNum > 0)
			{
				int tag = rand() % enemy.enemyNum;
				std::vector<COORD> xyPos = enemy.get_xy_pos_from_tag(tag);
				if (enemy.enemyType[tag] != "wall of buddy")
				{
					for (int i = 0; i < xyPos.size(); i++)
					{
						screen.erase_char_from_buffer(xyPos[i].X, xyPos[i].Y, 7, 4);
						screen.buffer_to_console();
					}
				}
				else
				{
					for (int i = 0; i < xyPos.size(); i++)
					{
						screen.erase_char_from_buffer(xyPos[i].X, xyPos[i].Y, 7, 4);
					}
					screen.buffer_to_console();
				}

				Sleep(1);

				if (enemy.enemyType[tag] != "wall of buddy")
				{

					for (int i = 0; i < xyPos.size(); i++)
					{
						screen.erase_char_from_buffer(xyPos[i].X, xyPos[i].Y, 7, 0);
						screen.buffer_to_console();
					}

				}
				else
				{
					for (int i = 0; i < xyPos.size(); i++)
					{
						screen.erase_char_from_buffer(xyPos[i].X, xyPos[i].Y, 7, 0);

					}
				}
				screen.buffer_to_console();
				enemy.decreseEnemyHealth(tag, 9999);
			}
			
		}
		
		screen.char_to_buffer(110, 60, 254, 4, 7);

	}
	
	//power
	if (power_stone == 0)
	{
		screen.char_to_buffer(112, 60, 254, 0, 7);
		if (point > 100)
		{
			screen.erase_string_from_buffer(122, 1, 30, 0, 7);
			screen.string_to_buffer(122, 1, "power stone aquired", 7, 0);
			power_stone = 1;
			screen.char_to_buffer(112, 60, 254, 5, 7);
		}

	}
	//mind
	if (mind_stone == 0)
	{
		screen.char_to_buffer(108, 60, 254, 0, 7);
		if (enemy.obtain_mind)
		{
			screen.erase_string_from_buffer(122, 1, 30, 0, 7);
			screen.string_to_buffer(122, 1, "mind stone aquired", black, white);
			mind_stone = 1;
			player.gem.mind_stone = 1;
			player.updateHp();
			screen.char_to_buffer(108, 60, 254, 14, 7);
		}

	}
	//space
	if (space_stone == 0)
	{
		screen.char_to_buffer(106, 60, 254, 0, 7);
		if (enemy.obtain_space)
		{
			screen.erase_string_from_buffer(122, 1, 30, 0, 7);
			screen.string_to_buffer(122, 1, "space stone aquired", 0, 7 );
			space_stone = 1;
			player.gem.space_stone = 1;
			player.updateHp();
			screen.char_to_buffer(106, 60, 254, 1, 7);
		}
	}
	//time
	if (time_stone == 0)
	{
		screen.char_to_buffer(104, 60, 254, 0, 7);
		if (enemy.obtain_time)
		{
			screen.erase_string_from_buffer(122, 1, 30, 0, 7);
			screen.string_to_buffer(122, 1, "time stone aquired", 0, 7);
			time_stone = 1;
			screen.char_to_buffer(104, 60, 254, 2, 7);
		}
	}
	//soul stone
	if (soul_stone == 0)
	{
		screen.char_to_buffer(102, 60, 254, 0, 7);
		if (enemy.obtain_soul)
		{
			screen.erase_string_from_buffer(122, 1, 30, 0, 7);
			screen.string_to_buffer(122, 1, "soul stone aquired", 0, 7);
			soul_stone = 1;
			screen.char_to_buffer(102, 60, 254, 6, 7);
		}

	}


	if (level != player.updatelevel(point))
	{
		level = player.updatelevel(point);
		//update player class
		player.updateBaseStat();
		player.updateHp();
		screen.player_to_buffer(player.characterPos);
		screen.buffer_to_console();
	}
	
	shipLevel = reality_stone + power_stone + mind_stone + space_stone + time_stone + soul_stone;

	if (bullet.shipLevel != shipLevel)
	{
		//update
		bullet.shipLevel = shipLevel;
		bullet.update_ship_level(shipLevel);
		screen.update_ship_level(shipLevel);
		//display
		screen.erase_player_from_buffer(player.characterPos);
		screen.player_to_buffer(player.characterPos);
		screen.buffer_to_console();
	}
	
}

void Game::updateGameStatus()
{
	if (player.state.isAlive==0)
	{
		if (soul_stone == 1)
		{
			player.state.isAlive = 1;
			soul_stone = 0;
			player.updateHp();
			enemy.obtain_soul = 0;
		}
		else
		{
			runningStatus = 0;
		}
	}
}

void Game::updateTime()
{
	Sleep(1);
	time++;
}

void Game::calculateScore()
{

}

void Game::saveScore()
{

}

