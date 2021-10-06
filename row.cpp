
#include "Row.h"
#include <iostream>
using namespace std;

Row::Row()
{
	
}
Row::Row(int len)
{
	isProper = true;
	rowContent = new unsigned char[len];
	styles = new int[len];
	for (int x = 0; x < len; x++)
	{
		rowContent[x] = ' ';
		styles[x] = 0;
	}
	width = len;
}
void Row::setLen(int len)
{
	rowContent = new unsigned char[len];
	styles = new int[len];
	for (int x = 0; x < len; x++)
	{
		rowContent[x] = ' ';
		styles[x] = 0;
	}
	width = len;
}
int Row::getStyle(int i)
{
	return styles[i];
}
void Row::spaceFill()
{
	//cout << width;
	for (int x = 0; x < width; x++)
	{
		rowContent[x] = '-';
	}
}
