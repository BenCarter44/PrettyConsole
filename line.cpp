#include "line.h"



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
	int otherX = 0;
	int otherY = 0;
	int tempWidth, tempHeight;
	if (endX > startX)
	{
		tempWidth = endX - startX + 1;
		anchorX = startX;
		otherX = endX;
	}
	else
	{
		tempWidth = startX - endX + 1;
		anchorX = endX;
		otherX = startX;
	}
	if (endY > startY)
	{
		tempHeight = endY - startY + 1;
		anchorY = startY;
		otherY = endY;
	}
	else
	{
		tempHeight = startY - endY + 1;
		anchorY = endY;
		otherY = startY;
	}
	ScreenComponent::init(anchorX, anchorY, tempWidth, tempHeight);
	int slopeY = endY - startY;
	int slopeX = endX - startX;
	//cout << "\n\n\n\n\n";
	//cout << slopeY << endl;
	//cout << slopeX << endl;
	//cout << anchorX << endl;
	//cout << anchorY << endl;
	if (abs(slopeY) <= abs(slopeX))
	{
		int slope = int(slopeY * 100 / slopeX);
		if (slope >= 0)
		{
			affected[0][0] = 1;
			affected[height-1][width-1] = 1;
			rowContent[height-1][width-1] = ' ';
			rowContent[0][0] = ' ';
		}
		else
		{
			affected[height - 1][0] = 1;
			affected[0][width - 1] = 1;
			rowContent[height - 1][0] = ' ';
			rowContent[0][width - 1] = ' ';
		}
		bool flip = slope >= 0;
		slope = abs(slope);
		for (int x = 0; x < width-1; x++)
		{
			
			int y = 0;
			if ((slope * x) % 100 > 60)
			{
				y = (slope * x) / 100 + 1;
			}
			else if ((slope * x) % 100 == 0)
			{
				y = (slope * x) / 100;
			}
			else
			{
				y = (slope * x) / 100;
			}
				
			if (!flip)
			{
				y = height - 1 - y;
			}
			affected[y][x] = 1;
			rowContent[y][x] = ' ';
		}
	}
	else
	{
		int slope = int(slopeX * 100 / slopeY);
		if (slope >= 0)
		{
			affected[0][0] = 1;
			affected[height - 1][width - 1] = 1;
			rowContent[height - 1][width - 1] = ' ';
			rowContent[0][0] = ' ';
		}
		else
		{
			affected[height - 1][0] = 1;
			affected[0][width - 1] = 1;
			rowContent[height - 1][0] = ' ';
			rowContent[0][width - 1] = ' ';
		}
		bool flip = slope >= 0;
		slope = abs(slope);
		
		for (int y = 0; y < height - 1; y++)
		{
			//Console::mapValue(y, 0, height - 1, )
			int x = 0;
			if ((slope * y) % 100 > 60)
			{
				x = (slope * y) / 100 + 1;
			}
			else if ((slope * y) % 100 == 0)
			{
				x= (slope * y) / 100;
			}
			else
			{
				x = (slope * y) / 100;
			}

			if (!flip)
			{
				x = width- x - 1;
			}
			//cout << x << endl;
			affected[y][x] = 1;
			rowContent[y][x] = ' '; //to_string(x).at(0);
		}
	}
}

Line2D::Line2D(int startX, int startY, int endX, int endY) : ScreenComponent()
{
	init(startX, startY, endX, endY);
}
