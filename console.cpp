#include "console.h"
#include <iostream>
using namespace std;

Console::Console()
{
	// get size of window
	
#ifndef LINUX

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, r;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	r = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	height = r;
	width = columns;

#else

// this code only works on linux:
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);

	height = w.ws_row;
	width =  w.ws_col;
#endif


	rows = new Row[height];

	resize = false;
	for (int x = 0; x < height; x++)
	{
		rows[x].setLen(width);

	}

}
void Console::render()
{
	cout << rows[0].getCharacter(0);

	
	for (int y = 0; y < height;y++)
	{
		int previous = 0;
		for (int x = 0; x < width; x++)
		{
			if (previous != rows[y].getStyle(x))
			{
				previous = rows[y].getStyle(x);
				cout << "<" << rows[y].getStyle(x) << ">";
			}
			cout << rows[y].getStyle(x);
		}
		cout << '\n';
	}
	

}
void Console::fillScreen()
{
	cout << height;
	
	for (int y = 0; y < height;y++)
	{
		rows[y].spaceFill();
	} 
	

}
void Console::clear()
{
	
	for (int y = 0; y < height;y++)
	{
		rows[y].spaceFill();
	}
	

}