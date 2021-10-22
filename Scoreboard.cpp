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
	screen.drawSquare(0,0,236,62,0,7);
	
	screen.string_to_buffer(10, 1, "RANK", 7, 0);
	screen.string_to_buffer(100, 1, "NAME", 7, 0);
	screen.string_to_buffer(150, 1, "SCORE", 7, 0);

	screen.buffer_to_console();
	
}
