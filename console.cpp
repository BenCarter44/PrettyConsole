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
	height += 0;
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
		rows[y].setRender(true);
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
void Console::render() // redo the entire screen
{
	//cout << rows[0].getCharacter(0);
	
	//cout << "\033[2J"; // clears the whole screen and sets cursor to (0,0) \\033[<L>;<C>H
	cout << "\033[0;0f";
	cout << stringRender(); 
	//cout << 
	/*
	for (int y = 0; y < height; y++)
	{
		cout << rows[y].getRenderState();
	}
	cout <<  '\n'; */
}
void Console::smartRender()
{
	/*for (int y = 0; y < height; y++)
	{
		cout << rows[y].getRenderState();
	}
	cout << '\n';*/
	// only render the specific line that needs revision.
	//int count = 0;
	for (int y = 0; y < height; y++)
	{
		if (!rows[y].getRenderState())
		{
			/*cout << y << '\n';
			if (count < height - 1)
			{
				putString(to_string(y), 0, count + 1);
			}
			count++;*/
			rows[y].renderLine();
			string s = "\033[" + to_string(y+1) + ";0f";

			cout << s << rows[y].getRenderResult();
		}
		
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
	/*if (y < height - 1)
	{
		cout << "H: " << rows[y + 1].getRenderState();
	} */
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
void Console::addShape(ScreenComponent* sc)
{
	int sx = sc->getAnchorX();
	int sy = sc->getAnchorY();
	int lenX = sc->getWidth();
	int lenY = sc->getHeight();

	for (int countY = 0; countY < lenY; countY++)
	{
		for (int countX = 0; countX < lenX; countX++)
		{
			if (sc->getAffected(countX, countY))
			{
				rows[countY + sy].setChar(sc->getChar(countX, countY),countX+sx);
				rows[countY + sy].setStyle(*(sc->getStyleSpecific(countX, countY)), countX + sx);
			}
		}
	}
}