#ifndef CONSOLE_H
#define CONSOLE_H


#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#else
#include <sys/ioctl.h>
#define LINUX 1
#endif
#include "row.h"



using namespace std;

class Console
{
private:
	Row* rows;
	bool resize;
	int height;
	int width;
	

public:
	void render();
	Console();
	void fillScreen();
	void clear();
	


};
#endif