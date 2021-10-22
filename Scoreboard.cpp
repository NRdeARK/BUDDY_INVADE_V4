#include "Scoreboard.h"

Scoreboard::Scoreboard()
{
	Screen screen;
}

bool Scoreboard::isRunning()
{
	return isrunning;
}

void Scoreboard::showLeaderboard()
{
	screen.drawSquare(0,0,236,62,7,0);
	screen.buffer_to_console();
	
}
