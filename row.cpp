
#include "Row.h"
#include "styles.h"
#include <iostream>

using namespace std;

Row::Row()
{
	rowContent = new unsigned char[10];
	styles = new Style[10];
	width = 0;
	isProper = false;
}
Row::Row(int len)
{
	isProper = true;
	rowContent = new unsigned char[len];
	styles = new Style[len];
	for (int x = 0; x < len; x++)
	{
		rowContent[x] = ' ';
		styles[x] = Style();
	}
	width = len;
}
void Row::setLen(int len)
{
	isProper = true;
	rowContent = new unsigned char[len];
	styles = new Style[len];
	for (int x = 0; x < len; x++)
	{
		rowContent[x] = ' ';
		styles[x] = Style();
	}
	width = len;
}
string Row::getStyle(int i)
{
	return styles[i].getASCII();
}
void Row::spaceFill()
{
	//cout << width;
	for (int x = 0; x < width; x++)
	{
		rowContent[x] = ' ';
	}
}
void Row::putString(string s, int start)
{
	if (start + s.length() > width)
	{
		s = s.substr(0, width - start);
	}
	for (int x = 0; x < s.length(); x++)
	{
		rowContent[x + start] = s.at(x);
	}
}
