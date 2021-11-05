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

}
void Rectangle2D::init(int startX, int startY, int w, int h)
{
	ScreenComponent::init(startX, startY, w,h);
}

Rectangle2D::~Rectangle2D()
{

}
void Rectangle2D::setFill(Style& s, bool invisible=false)
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
				affected[y][x] = 1;
				if (!invisible)
				{
					rowContent[y][x] = ' ';
				}
			}
		}
	}
	if (isBorder)
	{
		for (int y = 1; y < height-1; y++)
		{
			for (int x = 1; x < width-1; x++)
			{
				styles[y][x].init(s);
				affected[y][x] = 1;
				if (!invisible)
				{
					rowContent[y][x] = ' ';
				}
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
		affected[y][width - 1] = 1;
		affected[y][0] = 1;
		rowContent[y][0] = ' ';
		rowContent[y][width - 1] = ' ';
	}
	
}
void Rectangle2D::removeBorder()
{
	isBorder = false;
}
