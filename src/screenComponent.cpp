#include "screenComponent.h"

ScreenComponent::ScreenComponent()
{
	width = 0;
	height = 0;
	anchorX = 0;
	anchorY = 0;
}

void ScreenComponent::init()
{
	for (int y = 0; y < height; y++)
	{
		delete[] affected[y];
		delete[] rowContent[y];
		delete[] styles[y];
	}
	width = 0;
	height = 0;
	anchorX = 0;
	anchorY = 0;
}
ScreenComponent::ScreenComponent(int startX, int startY, int width, int height)
{
	anchorX = startX;
	anchorY = startY;
	this->width = width;
	this->height = height;
	affected = new bool*[height];
	rowContent = new unsigned char* [height];
	styles = new Style* [height];

	for (int x = 0; x < height; x++)
	{
		affected[x] = new bool[width];
		rowContent[x] = new unsigned char[width];
		styles[x] = new Style[width];
		for (int y = 0; y < width; y++)
		{
			affected[x][y] = 0;
			rowContent[x][y] = ' ';
		}
	}

}
void ScreenComponent::init(int startX, int startY, int width, int height)
{
	anchorX = startX;
	anchorY = startY;
	for (int y = 0; y < this->height; y++)
	{
		delete[] affected[y];
		delete[] rowContent[y];
		delete[] styles[y];
	}

	this->width = width;
	this->height = height;
	affected = new bool* [height];
	rowContent = new unsigned char* [height];
	styles = new Style* [height];

	for (int x = 0; x < height; x++)
	{
		affected[x] = new bool[width];
		rowContent[x] = new unsigned char[width];
		styles[x] = new Style[width];
		for (int y = 0; y < width; y++)
		{
			affected[x][y] = 0;
			rowContent[x][y] = ' ';
		}
	}
}
ScreenComponent::~ScreenComponent()
{
	for (int y = 0; y < height; y++)
	{
		delete[] affected[y];
		delete[] rowContent[y];
		delete[] styles[y];
	}
}
int ScreenComponent::getWidth()
{
	return width;
}
int ScreenComponent::getHeight()
{
	return height;
}
int ScreenComponent::getAnchorX()
{
	return anchorX;
}
int ScreenComponent::getAnchorY()
{
	return anchorY;
}
bool ScreenComponent::getAffected(int x, int y)
{
	if (x < width && y < height && x >= 0 && y >= 0)
	{
		return affected[y][x];
	}
	return 0;
}
Style* ScreenComponent::getStyleSpecific(int x, int y)
{
	if (x < width && y < height && x >= 0 && y >= 0)
	{
		return &(styles[y][x]);
	}
	Style* s = new Style;
	return s;
}
unsigned char ScreenComponent::getChar(int x, int y)
{
	if (x < width && y < height && x >= 0 && y >= 0)
	{
		return rowContent[y][x];
	}
	return '#';
}
void ScreenComponent::setFill(Style& s)
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (affected[y][x])
			{
				styles[y][x].init(s);
			}
		}
	}
}