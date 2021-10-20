// PrettyConsole.cpp : Defines the entry point for the application.
//

#include "PrettyConsole.h"
#include "Console.h"
using namespace std;
// https://stackoverflow.com/questions/4842424/list-of-ansi-color-escape-sequences
int main()
{
//	cout << "Hello CMake!!!." << endl;
	
	Console c = Console();
	c.clear();
	c.screenTest();
	c.putString("Testing", 5, 5);
	
	c.render();
	
	getchar();

	return 0;
	
	


}


