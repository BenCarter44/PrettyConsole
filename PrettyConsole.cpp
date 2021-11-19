// PrettyConsole.cpp : Defines the entry point for the application.
//

#include "PrettyConsole.h"
#include "console.h"
#include "rectangle.h"
#include "line.h"

#include <chrono>
#include <thread>// sleep!
using namespace std::chrono;


using namespace std;
// https://stackoverflow.com/questions/4842424/list-of-ansi-color-escape-sequences
// http://ndpsoftware.com/git-cheatsheet.html#loc=index;
int main()
{
	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; 
//	cout << "Hello CMake!!!." << endl;

	//
	Console c = Console();

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

	
	c.clear();
	c.screenTest();
	c.render();
	sleep_for(milliseconds(1000));
	Rectangle2D* rc = new Rectangle2D(0,0,20,4);
	Style newStyle = Style();
	newStyle.setBackgroundColor(0, 0, 0);
	rc->setFill(newStyle);
	c.addShape(rc);
	c.smartRender();
	sleep_for(milliseconds(1000));
	Rectangle2D* rc2 = new Rectangle2D(15, 3, 35, 4);
	newStyle.init();
	newStyle.setBackgroundColor(255, 255, 255);
	rc2->setFill(newStyle);
	c.addShape(rc2);
	c.smartRender();
	sleep_for(milliseconds(1000));
	Style borderStyle;
	borderStyle.setBackgroundColor(255, 0, 0);
	Rectangle2D* rc3 = new Rectangle2D(12, 7, 12, 4);
	rc3->setBorder(borderStyle);
	rc3->setFill(newStyle);
	c.addShape(rc3);

	c.smartRender();

	Line2D* ln1 = new Line2D(0, 0, 0,c.getHeight()-1);
	ln1->setFill(borderStyle);

	c.addShape(ln1);

	c.smartRender();

	c.putString("Test", 0, 0);
	c.smartRender();

	getchar();

	return 0;
	
	


}


