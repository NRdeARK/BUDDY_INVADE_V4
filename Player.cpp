#include "Player.h"


Player::Player()
{
	
}

void Player::decreseHp(int amount)
{
	stat.playerHp -= amount;
	if (stat.playerHp < 1)
	{
		state.isAlive = 0;
	}
}

void Player::control_to_command()
{
	if (control.input())
	{
		command = control.collectedData;
		control.collectedData = "";
		doCommand();
	}
}

void Player::doCommand()
{
	if (command == "w" || command == "W")
	{
		if (characterPos.Y > 3)
		{
			updateCharacterPos(0, -1);
			position_is_Update = 1;
		}
	}
	if (command == "a" || command == "A")
	{
		if (characterPos.X > 0)
		{
			updateCharacterPos(-1, 0);
			position_is_Update = 1;
		}
	}
	if (command == "s" || command == "S")
	{
		if (characterPos.Y < screen_y - 3 - 5)
		{
			updateCharacterPos(0, 1);
			position_is_Update = 1;
		}
	}
	if (command == "d" || command == "D")
	{
		if (characterPos.X < screen_x - 2)
		{
			updateCharacterPos(1, 0);
			position_is_Update = 1;
		}
	}
	if (command == "space")
	{
		space_is_Pressed = 1;
	}
	if (command == "esc")
	{
		state.isPause = 1;
	}
	checkEasterEgg();
	command = "";
}

bool Player::checkEasterEgg()
{
	if (command == "b" || secretpin.B)
	{
		secretpin.B = 1;
		if (command == "u" || secretpin.U)
		{
			secretpin.U = 1;
			if (command == "d" || secretpin.D)
			{
				secretpin.D = 1;
				if (command == "y" || secretpin.Y)
				{
					secretpin.Y = 1;
					if (command == "i" || secretpin.I)
					{
						secretpin.I = 1;
						if (command == "s" || secretpin.S)
						{
							secretpin.S = 1;
							if (command == "t" || secretpin.T)
							{
								secretpin.T = 1;
								if (command == "h" || secretpin.H)
								{
									secretpin.H = 1;
									if (command == "r" || secretpin.R)
									{
										secretpin.R = 1;
										if (command == "o" || secretpin.O)
										{
											secretpin.O = 1;
											if (command == "w" || secretpin.W)
											{
												secretpin.W = 1;
												if (command == "e" || secretpin.E)
												{
													secretpin.E = 1;
													return true;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}

int Player::updatelevel(int score)
{
	int expRemain = score;
	int expPassPoint = 9;
	int level = 0;
	while (expRemain>expPassPoint)
	{
		level++;
		expRemain -= expPassPoint;
		expPassPoint *= 2;
	}
	stat.level = level;
	stat.exp = expRemain;
	stat.expLimit = expPassPoint;
	return level;
}

int Player::updateHp()
{
	int newHp = (stat.baseHp + gem.power_stone) * (1 + 0.5 * gem.mind_stone);
	stat.playerHp = newHp;
	stat.playerMaxHp = newHp;
	return newHp;
}

void Player::updateBaseStat()
{
	stat.baseHp = 3 + stat.level * 2;
	stat.baseAttack = 1 + stat.level / 3;
}

void Player::updateCharacterPos(int x,int y)
{
	oldCharacterPos = characterPos;
	characterPos.X = characterPos.X + x;
	characterPos.Y = characterPos.Y + y;
	position_is_Update = 1;
}
