#include "console.h"
#include <iostream>
using namespace std;

Console::Console()
{
	init();
}
void Console::init()
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
	width = w.ws_col;
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
string Console::stringRender()
{
	string out;
	for (int y = 0; y < height;y++)
	{
		string previous = "";

		for (int x = 0; x < width; x++)
		{

			if (previous != rows[y].getStyle(x))
			{
				previous = rows[y].getStyle(x);
				out += previous;
			}
			out += rows[y].getCharacter(x);
		}
		if (y < height - 1)
		{
			out += '\n';
		}
		//cout << '\n';
	}
	return out;
}
void Console::render()
{
	//cout << rows[0].getCharacter(0);
	
	//cout << "\033[2J"; // clears the whole screen and sets cursor to (0,0) \\033[<L>;<C>H
	cout << "\033[<0>;<0>H";

	cout << stringRender();



}
void Console::smartRender()
{

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

		int a = mapValue(r, 0, height, 0, 255);

		Style newStyle = Style();
		
		t = (r * 3) % 255;
		newStyle.setBackgroundColor(a, 10, 255);
		
		rows[r].setRowStyle(newStyle);
	}
}
int Console::getHeight() const
{
	return height;
}
int Console::getWidth() const
{
	return width;
}

int mapValue(int x, int in_min, int in_max, int out_min, int out_max) 
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
