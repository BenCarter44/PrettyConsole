// PrettyConsole.cpp : Defines the entry point for the application.
//

#include "PrettyConsole.h"
#include "console.h"

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

	sleep_for(milliseconds(5000));
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
	//sleep_for(milliseconds(1000));
	unsigned long startF = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
	unsigned long stopF = startF;

	for (int r = 0; r < c.getHeight(); r++)
	{
		for (int x = 0; x < c.getWidth(); x++)
		{
			Style colorText = Style();
			//colorText.init();
			int a = Console::mapValue(r, 0, c.getHeight(), 0, 16);

			colorText.setTextColor(a);
			colorText.setBackgroundColor(a, 10, 255);
			c.putString(" Testing", x, r, colorText);
			c.putString(" END", 0, c.getHeight() - 1, colorText);
			//string a = c.stringRender();
			//cout << a;
			//cout << "\033[<0>;<0>H";
			
			c.smartRender();
			stopF = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
			double fps = 1000000 / (stopF - startF);
			c.putString("   " + to_string(fps) + "  ", 0, 5);
			c.putString("      " + to_string(stopF - startF) + "     ", 0, 7);
			//sleep_for(milliseconds(10));
			startF = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
		}
	}
	
	

	return 0;
	
	


}


