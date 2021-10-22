#include "Control.h"
#include <iostream> 
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string>

Control::Control()
{
	setConsole(screen_x, screen_y);
	setMode();
}

int Control::setMode()
{
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	SetConsoleMode(rHnd, fdwMode);
	return 0;
}

int Control::setConsole(int x, int y)
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}

bool Control::input()
{
	GetNumberOfConsoleInputEvents(rHnd, &numEvents);
	if (numEvents != 0)
	{
		INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
		ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
		for (DWORD i = 0; i < numEventsRead; ++i) {
			if ((eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown == true))
			{
				collectedData = "";
				char chr;
				if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar >= '0' && eventBuffer[i].Event.KeyEvent.uChar.AsciiChar <= '9')
				{
					char chr = eventBuffer[i].Event.KeyEvent.uChar.AsciiChar;
					collectedData.push_back(chr);
				}

				if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar >='A' && eventBuffer[i].Event.KeyEvent.uChar.AsciiChar <= 'Z')
				{
					char chr = eventBuffer[i].Event.KeyEvent.uChar.AsciiChar;
					collectedData.push_back(chr);
				}
				
				if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar >= 'a' && eventBuffer[i].Event.KeyEvent.uChar.AsciiChar <= 'z')
				{
					char chr = eventBuffer[i].Event.KeyEvent.uChar.AsciiChar;
					collectedData.push_back(chr);
				}
				
				if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
				{
					collectedData = "esc";
				}
				if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_BACK)
				{
					collectedData = "back";
				}
				if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == ' ')
				{
					collectedData = "space";
				}
				if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == VK_RETURN)
				{
					collectedData = "enter";
				}
				if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == VK_LEFT)
				{
					collectedData = "arrowLeft";
				}
				if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == VK_RIGHT)
				{
					collectedData = "arrowRight";
				}
				if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == VK_UP)
				{
					collectedData = "arrowUp";
				}
				if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == VK_DOWN)
				{
					collectedData = "arrowDown";
				}
				return true;
				
			}

			else if (eventBuffer[i].EventType == MOUSE_EVENT) 
			{
				int posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
				int posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
				if (eventBuffer[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
				{

					mouse_x = posx;
					mouse_y = posy;
					return true;
				}
				else if (eventBuffer[i].Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED)
				{
					mouse_x = posx;
					mouse_y = posy;
					return true;
				}
				else if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED)
				{
					mouse_x = posx;
					mouse_y = posy;
					return false;
				}
			}
			
			else
			{
				delete[] eventBuffer;
				return false;
			}
			
		}
	}
}

std::string Control::stringFromInput()
{
	if (input())
	{
		return collectedData;
	}
}
