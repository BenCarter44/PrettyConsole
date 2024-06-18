// PrettyConsole.cpp : Defines the entry point for the application.
//

#include "PrettyConsole.h"
#include "console.h"
#include "rectangle.h"
#include "line.h"
#include "point.h"

#include <chrono>
#include <thread>// sleep!

#include <fstream>

using namespace std::chrono;


using namespace std;
// https://stackoverflow.com/questions/4842424/list-of-ansi-color-escape-sequences
// http://ndpsoftware.com/git-cheatsheet.html#loc=index;
#ifndef STOP_TEST
int main()
{
	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; 
//	cout << "Hello CMake!!!." << endl;

	//
	Console c = Console();
	if (!c.getSupport())
	{
		cout << "Display not supported! Press enter to quit... ";
		getchar();
		return 0;
	}
	cout << c.getHeight() << '\n';
	cout << c.getWidth() << '\n';
	




	ifstream input("colorSimple.dat");
	string charMap = "";
	while (!input.eof())
	{
		char inc;
		input.get(inc);
		if (!input.eof())
		{
			charMap.push_back(inc);
		}
	}
	//cout << "'" << charMap << "'";
	input.close();

#ifndef COLORR
	ifstream pyInput("transfer.toc");
	int inWidth;
	int inHeight;
	int styleAmount;     // NOTE. THIS IS NOT SECURE.... BUT, I'M IGNORING IT FOR NOW.... THIS WILL NEED TO GET FIXED BY INCLUDING ERROR CHECKING
	pyInput >> inWidth;
	pyInput >> inHeight;
	pyInput >> styleAmount;
	if (inWidth != c.getWidth() || inHeight != c.getHeight())
	{
		cout << "Please run from BAT. The console sizes are different!";
	}
	c.clear();

	// style def
	
	Style* styleDefinitions = new Style[styleAmount+2];
	int divisor = 255 / (styleAmount);  // style = 5, so 5.  51 each.
	for (int x = 0; x < (styleAmount); x++)
	{
		// 255 / (styleAmount-1) for each. if style = 6 
		styleDefinitions[x].setBackgroundColor(x * divisor, x * divisor, x * divisor);
		styleDefinitions[x].setTextColor((x+1) * divisor, (x+1) * divisor, (x+1) * divisor);
	}
	styleDefinitions[styleAmount].setBackgroundColor(255,255,255);
	styleDefinitions[styleAmount].setTextColor(255, 0, 0);
	styleDefinitions[styleAmount+1].setBackgroundColor(255, 255, 255);
	styleDefinitions[styleAmount+1].setTextColor(0, 0, 0);

	for (int y = 0; y < inHeight; y++)
	{
		for (int x = 0; x < inWidth; x++)
		{
			int textNumber;
			int backColor;
			pyInput >> textNumber;
			pyInput >> backColor;
			Point2D p = Point2D(x, y);
			p.setFill(styleDefinitions[backColor]);
			p.putChar(charMap[textNumber]);
			c.addShape(&p); // & is the refrence to.
			//pyInput
		}
		c.smartRender(); // render each line!
	}
	pyInput.close();

#else
	ifstream pyInput("transferCOLOR.toc");
	int inWidth;
	int inHeight;
	pyInput >> inWidth;
	pyInput >> inHeight;
	if (inWidth != c.getWidth() || inHeight != c.getHeight())
	{
		cout << "Please run from BAT. The console sizes are different!";
	}
	c.clear();

	// style def


	for (int y = 0; y < inHeight; y++)
	{
		for (int x = 0; x < inWidth; x++)
		{
			int textNumber;
			int textR;
			int textG;
			int textB;
			int backR;
			int backG; // NOTE. THIS IS NOT SECURE.... BUT, I'M IGNORING IT FOR NOW.... THIS WILL NEED TO GET FIXED BY INCLUDING ERROR CHECKING
			int backB;
			pyInput >> textNumber;
			pyInput >> textR;
			pyInput >> textG;
			pyInput >> textB;
			pyInput >> backR;
			pyInput >> backG;
			pyInput >> backB;
			Point2D p = Point2D(x, y);

			Style newStyle = Style();
			newStyle.setTextColor(textR, textG, textB);
			newStyle.setBackgroundColor(backR, backG, backB);

			p.setFill(newStyle);
			p.putChar(charMap[textNumber]);
			c.addShape(&p); // & is the refrence to.
			//pyInput
		}
		c.smartRender(); // render each line!
	}
	pyInput.close();


#endif
	/*int height = c.getHeight();
	int width = c.getWidth();
	cout << "Testing!\n";
	sleep_for(milliseconds(1000));
	cout << "Testing1!\n";
	sleep_for(milliseconds(1000));
	cout << "Testing2!";
	sleep_for(milliseconds(1000));
	int y = 1;
	string s = "\033[" + to_string(y) + ";1f";
	cout << s;
	cout << "a";
	cout << "\n\n\n";*/

	
	//c.clear();
	// go through each line in the file. Take c.getHeight

	return 0;


	/*
	Coupling:

	Loose Coupling is when if you change 1 class, you don't need to change the implementation of other classes

	Tight Coupling is when you change 1 class, you need to change other classes to make it work.

	Loose coupling is recommended.
	
	
	*/
	
	


}
#endif

