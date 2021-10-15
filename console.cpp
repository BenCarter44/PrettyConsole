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
	//height -= 2;
	//width -= 2;

#else

// this code only works on linux:
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);

	height = w.ws_row;
	width =  w.ws_col;
#endif
	//cout << height << '\n';
	//cout << width << '\n';
	

	rows = new Row[height];

	resize = false;
	for (int x = 0; x < height; x++)
	{
	//	cout << "X: " << x << '\n';
		rows[x].setLen(width);
		
	}

	

}
void Console::render()
{
	//cout << rows[0].getCharacter(0);

	
	for (int y = 0; y < height;y++)
	{
		string previous = "";
		for (int x = 0; x < width; x++)
		{
			/*if (previous == rows[y].getStyle(x))
			{
				previous = rows[y].getStyle(x);
				cout << rows[y].getStyle(x);
			}*/
			cout << rows[y].getCharacter(x);
		}
		if (y < height - 1)
		{
			cout << '\n';
		}
		//cout << '\n';
	}
	

}
void Console::fillScreen()
{
//	cout << height;
	
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
void Console::putString(string data, int x, int y)
{
	rows[y].putString(data, x);
}
void Console::screenTest()
{
	int t = 0;
	for (int r = 0; r < height; r++)
	{
		rows[r].spaceFill();

		Style newStyle = Style();
		
		t = (r * 3) % 255;
		newStyle.setBackgroundColor(t, 10, 255);
		rows[r].setRowStyle(newStyle);
	}
}