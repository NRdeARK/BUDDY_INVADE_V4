#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <fstream>
#include "Scoreboard.h"
#include<string>
#include <vector>

Scoreboard::Scoreboard()
{
	Screen screen;
	Control control;
	getList();
}

bool Scoreboard::isRunning()
{
	return isrunning;
}

void Scoreboard::getList()
{

	using std::cout; using std::cerr;
	using std::endl; using std::string;
	using std::ifstream; using std::vector;

	string filename("lead.txt");
	vector<string> lines;
	string line;

	ifstream input_file(filename);
	if (!input_file.is_open()) {
		cerr << "Could not open the file - '"
			<< filename << "'" << endl;
	}

	while (getline(input_file, line)) {
		lines.push_back(line);
	}
	bool mode = 1;
	int j = 0;
	for (int i = 0; i < lines.size(); i++)
	{
		if (lines.size() >= j+2)
		{
			if (mode)
			{
				playerlist.name[j] = lines[j * 2];
			}
			else
			{
				playerlist.score[j] = std::stoi(lines[j *2  + 1]);
				j++;
			}
			mode = !mode;
		}
	}
	input_file.close();
}

void Scoreboard::pushList()
{
	using namespace std;
	using std::cout; using std::cerr;
	using std::endl; using std::string;
	using std::ofstream; using std::vector;

	string filename("lead.txt");
	vector<string> lines;
	string line;

	ofstream input_file(filename);
	if (!input_file.is_open()) 
	{
		cerr << "Could not open the file - '"<< filename << "'" << endl;
	}

	bool mode = 1;
	int j = 0;

	for (int i = 0; i < 5; i++)
	{
		input_file << playerlist.name[i] << endl;
		input_file << playerlist.score[i] << endl;
	}

	input_file.close();
}

void Scoreboard::showLeaderboard()
{
	screen.drawSquare(0,0,236,62,0,7);

	screen.string_to_buffer(50, 2, "RANK", 0, 7);
	screen.string_to_buffer(50, 6, "1", 0, 7);
	screen.string_to_buffer(50, 10, "2", 0, 7);
	screen.string_to_buffer(50, 14, "3", 0, 7);
	screen.string_to_buffer(50, 18, "4", 0, 7);
	screen.string_to_buffer(50, 22, "5", 0, 7);
	screen.string_to_buffer(100, 2, "NAME", 0, 7);
	screen.string_to_buffer(150, 2, "SCORE", 0, 7);
	for (int i = 0; i < 5; i++)
	{
		screen.string_to_buffer(100, 6 + i * 4, playerlist.name[i], 0, 7);
		screen.string_to_buffer(150, 6 + i * 4, std::to_string(playerlist.score[i]), 0, 7);
	}
	screen.buffer_to_console();
}

void Scoreboard::waitInput()
{
	control.input();
	if (control.collectedData != "")
	{
		isrunning = 0;
	}
}

bool Scoreboard::can_be_added(int score)
{
	for (int i = 0; i < 5; i++)
	{
		if (playerlist.score[i] < score)
		{
			return true;
		}
	}
	return false;
}

void Scoreboard::getName()
{
	screen.string_to_buffer(100,31,"NAME",7,0);
	screen.erase_string_from_buffer(100,31, 100, 0, 0);
	screen.buffer_to_console();
	name = "";
	while (name == "")
	{
		screen.openTextbox(118, 31);
		screen.writeTextbox(7,0);
		screen.closeTextbox();
		name = screen.collectedText;
	}
	screen.buffer_to_console();
}

void Scoreboard::addScore(std::string name, int score)
{
	int order;
	for (int i = 0; i < 5; i++)
	{
		if (playerlist.score[i] < score)
		{
			order = i;
			break;
		}
	}
	playerlist.name[order] = name;
	playerlist.score[order] = score;
}
