
#include "Row.h"
#include "styles.h"
#include <iostream>

using namespace std;

Row::Row()
{
	//rowContent = new unsigned char[10];
	//styles = new Style[10];
	width = 0;
	isProper = false;
}
Row::~Row()
{
	if (isProper)
	{
		delete[] rowContent;
		delete[] styles;
	}
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
	if (isProper)
	{
		delete[] rowContent;
		//cout << "PROBLEM!";
		delete[] styles;
		//cout << "ANSWER!"<<len;

	}
	isProper = true;
	rowContent = new unsigned char[len];
	styles = new Style[len];
	for (int x = 0; x < len; x++)
	{
		rowContent[x] = ' ';
	}
	width = len;

}
string Row::getStyle(int i)
{
	return styles[i].getASCII();
}
void Row::setStyle(int i,Style s)
{
	styles[i] = s;
}
void Row::setRowStyle(Style s)
{
	for (int x = 0; x < width; x++)
	{
		styles[x] = s;
	}
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
