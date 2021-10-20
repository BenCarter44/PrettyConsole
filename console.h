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
	void init();
	void fillScreen();
	void clear();
	void putString(string data, int x, int y);
	void screenTest();
	string stringRender();
	int getWidth() const;
	int getHeight() const;
	void smartRender();
};

int mapValue(int x, int in_min, int in_max, int out_min, int out_max);

#endif