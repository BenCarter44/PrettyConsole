#ifndef CONSOLE_H
#define CONSOLE_H


#if defined(_WIN32) || defined(WIN32)
#include <windows.h>

//  Microsoft 
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)



#else
//  GCC
#include <sys/ioctl.h>
#define LINUX 1
#define EXPORT __attribute__((visibility("default")))
#define IMPORT

#endif
#ifdef DLLHEADER_COMPLIE
#define DLLHEADER EXPORT
#else
#define DLLHEADER IMPORT
#endif


#include "row.h"
#include "screenComponent.h"
#include "MyString.h"




class DLLHEADER Console
{
private:
	Row* rows;
	bool resize;
	int height;
	int width;
	bool support;

public:
	void render();
	Console();
	Console(MyString t);
	void init();
	void init(MyString t);
	void fillScreen();
	void clear();
	void putString(MyString data, int x, int y);
	void putString(MyString data, int x, int y, Style s);
	void screenTest();
	MyString stringRender();
	int getWidth() const;
	int getHeight() const;
	void smartRender();
	void addShape(ScreenComponent* sc);
	static int mapValue(int x, int in_min, int in_max, int out_min, int out_max)
	{
		return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
	}
	bool getSupport()
	{
		return support;
	}
	void setTitle(MyString title);
	Style getSpecificStyle(int x, int y);
	unsigned char getSpecificChar(int x, int y);
};



#endif