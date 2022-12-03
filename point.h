#ifndef POINTH_H
#define POINTH_H

#include "screenComponent.h"
#include "console.h"

class DLLHEADER Point2D : public ScreenComponent
{
public:
	Point2D(int x, int y);
	void init(int x, int y);
	Point2D();
	void init();
	void putChar(char c);
	unsigned char getChar();

};

#endif