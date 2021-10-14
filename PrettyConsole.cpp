// PrettyConsole.cpp : Defines the entry point for the application.
//

#include "PrettyConsole.h"
#include "Console.h"
using namespace std;

int main()
{
	cout << "Hello CMake!!!." << endl;
	Console c = Console();
	c.fillScreen();
	c.render();
	return 0;
}

