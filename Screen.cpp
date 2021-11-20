#include "Screen.h"
#include <string.h>

Screen::Screen()
{
	setConsole(screen_x, screen_y);
	setMode();
}

int Screen::setMode()
{
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	SetConsoleMode(rHnd, fdwMode);
	return 0;
}

int Screen::setConsole(int x, int y)
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}

void Screen::char_to_buffer(int x, int y, char chr, int fg, int bg)
{
	if (x<screen_x && x>-1 && y<screen_y && y>-1)
	{
		consoleBuffer[x + screen_x * y].Char.AsciiChar = chr;
		consoleBuffer[x + screen_x * y].Attributes = fg + 16 * bg;
	}
}

void Screen::string_to_buffer(int x, int y, std::string word, int fg, int bg)
{
	for (int i = 0; i < word.length(); i++)
	{
		consoleBuffer[x + i + screen_x * (y)].Char.AsciiChar = word[i];
		consoleBuffer[x + i + screen_x * (y)].Attributes = fg + 16 * bg;
	}
}

void Screen::buffer_to_console()
{
	WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos, &windowSize);
}

void Screen::erase_char_from_buffer(int x, int y, int fg, int bg)
{
	char_to_buffer(x, y, ' ', fg, bg);
}

void Screen::erase_string_from_buffer(int x, int y,int lenght, int fg, int bg)
{
	for (int i = 0; i < lenght; i++)
	{
		consoleBuffer[x + i + screen_x * (y)].Char.AsciiChar = ' ';
		consoleBuffer[x + i + screen_x * (y)].Attributes = fg + 16 * bg;
	}
}

char Screen::char_from_console(int x, int y)
{
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2];
	COORD c = { x,y };
	DWORD num_read;
	if (!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))
		return '\0';
	else
		return buf[0];
}

void Screen::drawSquare(int x, int y, int lenght, int breath, int fg, int bg)
{
	for (int j = 0; j < lenght; j++)
	{
		for (int i = 0; i < breath; i++)
		{
			char_to_buffer(x + j, y + i, ' ', fg, bg);
		}
	}
	buffer_to_console();
}

void Screen::clearbuffer()
{
	for (int j = 0; j < screen_x; j++)
	{
		for (int i = 0; i < screen_y; i++)
		{
			char_to_buffer(j, i, '\0', black, black);
		}
	}
	buffer_to_console();
}

void Screen::set_cursor_pos(int x, int y)
{
	cursor.pos.X = x;
	cursor.pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor.pos);
}

void Screen::set_cursor_color(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

void Screen::set_cursor_visible(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}

void Screen::drawLogo(int x, int y, int fg, int bg)
{
	string_to_buffer(x, y,     " BBBBB                D      D          IIIIII                              D                   ", fg, bg);
	string_to_buffer(x, y + 1, " B    B               D      D            ii                                D                   ", fg, bg);
	string_to_buffer(x, y + 2, " B   B                D      D            ii                                D                   ", fg, bg);
	string_to_buffer(x, y + 3, " BBBB    U    U   DDDDd  DDDDd Y    Y     ii    N  nnn v     V  aaaA    DDDDd   eeee    R  rr   ", fg, bg);
	string_to_buffer(x, y + 4, " B   B   U    U  d    d d    d Y    Y     ii    N nn n  v   V  a   A   d    d  E    e   R r  r  ", fg, bg);
	string_to_buffer(x, y + 5, " B    B  U    U  d    d d    d Y    y     ii    Nn   n   v V   a   A   d    d  E eeee   Rr      ", fg, bg);
	string_to_buffer(x, y + 6, " BBBBB   UuuuuU   DDDD   DDDD   YYYYy   IIIIII  N    n    V     aa  aa  DDDD   Ee       R       ", fg, bg);
	string_to_buffer(x, y + 7, "                                    y                                            eeee           ", fg, bg);
	string_to_buffer(x, y + 8, "                                   y                                                            ", fg, bg);
	string_to_buffer(x, y + 9, "                                yyy                                                             ", fg, bg);
}

void Screen::openTextbox(int x,int y)
{
	set_cursor_pos(x, y);
	set_cursor_visible(1);
}

void Screen::writeTextbox(int fg,int bg)
{
	set_cursor_color(fg, bg);
	int startx = cursor.pos.X;
	int starty = cursor.pos.Y;
	int x = cursor.pos.X;
	int y = cursor.pos.Y;
	std::string text="";
	int limit = 21;
	int charNum = 0;
	do
	{

		control.collectedData.clear();
		erase_string_from_buffer(startx, starty, text.size(), white, black);
		//erase_string_from_buffer(startx, starty + 1, 5, white, black);
		if (limit > charNum)
		{
			control.input();
		}
		//control.input();
		if (control.collectedData == "back" && text.size()>0)
		{
			text.erase(text.begin() + charNum-1);
			//text.pop_back();
			x -= 1;
			set_cursor_pos(x, y);
			charNum--;
			string_to_buffer(startx, starty + 1, "         ", white, black);

		}
		if (std::isalnum(control.collectedData[0])&&control.collectedData.size()<2 && charNum < 20)
		{
			text.push_back(control.collectedData[0]);
			x += 1;
			set_cursor_pos(x,y);
			charNum++;
			string_to_buffer(startx, starty + 1, "         ", white, black);
		}
		
		string_to_buffer(startx, starty, text, fg, bg);
		string_to_buffer(startx, starty+1, control.collectedData, white, black);
		buffer_to_console();


	} while (control.collectedData != "enter" && control.collectedData != "esc");
	if (control.collectedData == "enter")
	{
		Beep(2000, 200);
		collectedText = text;
		closeTextbox();
	}

}

void Screen::closeTextbox()
{
	set_cursor_visible(0);
}

void Screen::player_to_buffer(COORD playerPos)
{
	int x[8] = { 0,0,1,0,1,0,1,0 };
	int y[8] = { 0,1,1,2,2,3,3,4 };
	for (size_t i = 0; i < 8; i++)
	{
		char_to_buffer(playerPos.X + x[i], playerPos.Y + y[i], chrship[id][i], fgship[id][i], bgship[id][i]);
	}
}

void Screen::erase_player_from_buffer(COORD oldplayerPos)
{
	int x[8] = { 0,0,1,0,1,0,1,0 };
	int y[8] = { 0,1,1,2,2,3,3,4 };
	for (size_t i = 0; i < 8; i++)
	{
		char_to_buffer(oldplayerPos.X + x[i], oldplayerPos.Y + y[i], ' ', 0, 0);
	}
}

void Screen::update_ship_level(int shipLevel)
{

	if (shipLevel == 0 || shipLevel == 1 || shipLevel == 2)
	{
		id = 0;
	}
	if (shipLevel == 3 || shipLevel == 4)
	{
		id = 1;
	}
	if (shipLevel == 5 || shipLevel == 6)
	{
		id = 2;
	}
}

char Screen::char_from_player(COORD playerPos, int num)
{
	int pos_x = playerPos.X;
	int pos_y = playerPos.Y;
	int x[8] = { 0,0,1,0,1,0,1,0 };
	int y[8] = { 0,1,1,2,2,3,3,4 };
	return char_from_console(pos_x + x[num], pos_y + y[num]);
}



