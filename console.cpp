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
	

#else

// this code only works on linux:
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);

	height = w.ws_row;
	width = w.ws_col;
#endif
	//cout << height << '\n';
	//cout << width << '\n';
	//height -= 1;
	//width -= 1;

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
		//cout << out.length() << '\n';
		if (y < height - 1)
		{
			out += '\n';
			//cout << "\033[<" << (y + 1) << ">;<0>H";
			//cout << out;
			//cout << '\n';
			//out = "";
		}
		
	}
	return out;
}
void Console::render()
{
	//cout << rows[0].getCharacter(0);
	
	//cout << "\033[2J"; // clears the whole screen and sets cursor to (0,0) \\033[<L>;<C>H
	cout << "\033[<0>;<0>H";
	cout << stringRender(); // << '\f' << endl; //flush;
	//cout << 



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
void Console::putString(string data, int x, int y,Style s)
{
	rows[y].putString(data, x, s);
}
void Console::screenTest()
{
	int t = 0;
	for (int r = 0; r < height; r++)
	{
		
		rows[r].spaceFill();

		int a = mapValue(r, 0, height, 0, 255);

		Style newStyle = Style();
	
		newStyle.setBackgroundColor(a, 10, 255);
		newStyle.setTextColor(255, 255, 255);
		//newStyle.setBackgroundColor(mapValue(r, 0, height, 0, 16));
		//cout << a << '\n';
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
