
#include "point.h"

Point2D::Point2D(int x, int y) : ScreenComponent(x,y,1,1)
{
	rowContent[0][0] = ' ';
	affected[0][0] = 1;
}
void Point2D::init(int x, int y)
{
	ScreenComponent::init(x,y,1,1);
	rowContent[0][0] = ' ';
	affected[0][0] = 1;
}
Point2D::Point2D() : ScreenComponent(0, 0, 1, 1)
{
	rowContent[0][0] = ' ';
	affected[0][0] = 1;
}
void Point2D::init()
{
	ScreenComponent::init(0, 0, 1, 1);
	rowContent[0][0] = ' ';
	affected[0][0] = 1;
}
void Point2D::putChar(char c)
{
	rowContent[0][0] = c;
}
