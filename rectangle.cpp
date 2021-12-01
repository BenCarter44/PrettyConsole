#include "rectangle.h"

Rectangle2D::Rectangle2D() : ScreenComponent()
{
	// automatically calls screencomponent
}

void Rectangle2D::init()
{
	ScreenComponent::init();
}
Rectangle2D::Rectangle2D(int startX, int startY, int w, int h) : ScreenComponent(startX, startY, w, h)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			affected[y][x] = 1;
			rowContent[y][x] = ' ';

		}
	}
}
void Rectangle2D::init(int startX, int startY, int w, int h)
{
	ScreenComponent::init(startX, startY, w,h);
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			affected[y][x] = 1;
			rowContent[y][x] = ' ';

		}
	}

}

Rectangle2D::~Rectangle2D()
{

}
void Rectangle2D::setFill(Style& s)
{
	fill.init(s);
	// store the style in every part
	if (!isBorder)
	{
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				styles[y][x].init(s);			
			}
		}
	}
	if (isBorder)
	{
		for (int y = 2; y < height-2; y++)
		{
			for (int x = 2; x < width-2; x++)
			{
				styles[y][x].init(s);				
			}
		}
	}
	
}
void Rectangle2D::setBorder(Style& s)
{
	border.init(s);
	isBorder = true;
	// store the style in every part
	for (int y = 1; y < height - 1; y++)
	{	
		styles[y][0].init(s);
		styles[y][width - 1].init(s);
		styles[y][1].init(s);
		styles[y][width - 2].init(s);
	}
	for (int x = 0; x < width; x++)
	{
		styles[0][x].init(s);
		styles[height - 1][x].init(s);
	}
	
}
void Rectangle2D::removeBorder()
{
	isBorder = false;
}
