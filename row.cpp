
#include "row.h"
#include "styles.h"
#include <iostream>



Row::Row()
{
	isRender = false;
	//rowContent = new unsigned char[10];
	//styles = new Style[10];
	width = 0;
	isProper = false;
}
void Row::init()
{
	isRender = false;
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
	isRender = false;
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
void Row::init(int len)
{
	isRender = false;
	if (isProper)
	{
		delete[] rowContent;
		delete[] styles;
	}
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
	isRender = false;
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
MyString Row::getStyle(int i)
{

	return styles[i].getASCII();
}
Style Row::getStyleObj(int i)
{
	return styles[i];
}
void Row::setStyle(int i,Style s)
{
	setStyle(s, i);
}
void Row::setRowStyle(Style s)
{
	isRender = false;
	for (int x = 0; x < width; x++)
	{
		styles[x].init(s);
	}
}
void Row::spaceFill()
{
	isRender = false;
	//cout << width;
	for (int x = 0; x < width; x++)
	{
		rowContent[x] = ' ';
	}
}
void Row::putString(MyString s, int start)
{
	isRender = false;
	if (start + s.length() > width)
	{
		s = s.substring(0, width - start);
	}
	for (int x = 0; x < s.length(); x++)
	{
		rowContent[x + start] = s.at(x);
	}
}
void Row::putString(MyString s, int start, Style sty)
{
	isRender = false;
	if (start + s.length() > width)
	{
		s = s.substring(0, width - start);
	}
	for (int x = 0; x < s.length(); x++)
	{
		rowContent[x + start] = s.at(x);
		styles[x + start].init(sty);
	}
}
void Row::renderLine()
{
	isRender = true;
	MyString out = "";
	MyString previous = "";

	for (int x = 0; x < width; x++)
	{

		if (previous != styles[x].getASCII())
		{
			previous = styles[x].getASCII();
			out += previous;
		}
		out += rowContent[x];
	}
	renderString = out;

}
void Row::setRender(bool r)
{
	isRender = r;
}
bool Row::getRenderState()
{
	return isRender;
}
MyString Row::getRenderResult()
{
	
	return renderString;
}
void Row::setChar(unsigned char c, int i)
{
	if (i < width && i >= 0)
	{
		isRender = false;
		rowContent[i] = c;
	}
}
void Row::setStyle(Style& s, int i)
{
	if (i < width && i >= 0)
	{
		isRender = false;
		styles[i].init(s);
	}
}