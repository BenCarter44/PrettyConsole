#include "line.h"

Line2D::Line2D() : ScreenComponent()
{

}
void Line2D::init()
{
	ScreenComponent::init();
}
void Line2D::init()
{
	ScreenComponent::init();
}
Line2D::Line2D(int startX, int startY, int endX, int endY) : ScreenComponent()
{
	if (endX > startX)
	{
		width = endX - startX + 1;
		anchorX = startX;
	}
	else
	{
		width = startX - endX + 1;
		anchorX = endX;
	}
	if (endY > startY)
	{
		height = endY - startY + 1;
		anchorY = startY;
	}
	else
	{
		height = startY - endY + 1;
		anchorY = endY;
	}
	ScreenComponent::init(anchorX, anchorY, width, height);
	int slopeY = endY - startY;
	int slopeX = endX - startX;
	/*
	
	Y
	 Y	
	  Y
	
	
	*/
	for (int x = 0; x < width; x++)
	{
		int change = ((slopeY * 1000) / (slopeX * 1000)) / width);
		int y = Console::mapValue(width * x, 0, 1000, 0, height);
		affected[y][x] = 1;
		rowContent[y][x] = ' ';

	}

}