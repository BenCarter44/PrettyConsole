#include "line.h"

using namespace std;

Line2D::Line2D() : ScreenComponent()
{

}
void Line2D::init()
{
	ScreenComponent::init();
}
Line2D::~Line2D()
{

}

void Line2D::init(int startX, int startY, int endX, int endY)
{
	int tempWidth, tempHeight;
	if (endX > startX)
	{
		tempWidth = endX - startX + 1;
		anchorX = startX;
	}
	else
	{
		tempWidth = startX - endX + 1;
		anchorX = endX;
	}
	if (endY > startY)
	{
		tempHeight = endY - startY + 1;
		anchorY = startY;
	}
	else
	{
		tempHeight = startY - endY + 1;
		anchorY = endY;
	}
	ScreenComponent::init(anchorX, anchorY, tempWidth, tempHeight);
	int slopeY = endY - startY;
	int slopeX = endX - startX;
	cout << "\n\n\n\n\n";
	cout << slopeY << endl;
	cout << slopeX << endl;
	cout << anchorX << endl;
	cout << anchorY << endl;
	if (abs(slopeY) <= abs(slopeX))
	{
		int slope = int(slopeY * 100 / slopeX);
		affected[0][0] = 1;
		affected[height-1][width-1] = 1;
		rowContent[height-1][width-1] = ' ';
		rowContent[0][0] = ' ';
		for (int x = 0; x < width; x++)
		{
			int y = 0;
			if ((slope * x) % 100 > 70)
			{
				y = (slope * x) / 100 + 1;
			}
			else
			{
				y = (slope * x) / 100;
			}
			affected[y][x] = 1;
			rowContent[y][x] = ' ';
		}
	}
	else
	{
		int slope = int(slopeX * 100 / slopeY);
		affected[anchorY][anchorX] = 1;
		affected[endY][endX] = 1;
		rowContent[anchorY][anchorX] = ' ';
		rowContent[endY][endX] = ' ';
		for (int y = 0; y < height; y++)
		{
			int x = 0;
			if ((slope * y) % 100 > 70)
			{
				x = (slope * y) / 100 + 1;
			}
			else
			{
				x = (slope * y) / 100;
			}
			affected[y + anchorY][x + anchorX] = 1;
			rowContent[y + anchorY][x + anchorX] = ' ';
		}
	}
}

Line2D::Line2D(int startX, int startY, int endX, int endY) : ScreenComponent()
{
	init(startX, startY, endX, endY);
}
