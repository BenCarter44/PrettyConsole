// PrettyConsole.cpp : Defines the entry point for the application.
//

#include "PrettyConsole.h"
#include "Console.h"

#include <chrono>
#include <thread>// sleep!


using namespace std;
// https://stackoverflow.com/questions/4842424/list-of-ansi-color-escape-sequences
int main()
{
	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; 
//	cout << "Hello CMake!!!." << endl;
	sleep_for(microseconds(100));

	Console c = Console();
	c.clear();
	c.screenTest();
	for (int r = 0; r < c.getHeight(); r++)
	{
		for (int x = 0; x < c.getWidth(); x++)
		{
			c.putString(" Testing", x, r);
			//string a = c.stringRender();
			//cout << a;
			//cout << "\033[<0>;<0>H";
			c.render();
			sleep_for(milliseconds(1000));
		}
	}
	
	getchar();

	return 0;
	
	


}


