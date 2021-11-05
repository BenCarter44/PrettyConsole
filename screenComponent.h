/*

This will be the superclass for any graphic on the screen.

Rectangles,
Lines,
Points,
Circles,
Parallelogram....

all shapes will need to boil down to a character array.
The console class will write the shape to the rows.



*/
#ifndef SCREENCOMP
#define SCREENCOMP
#include "styles.h"

class ScreenComponent
{

protected:
	bool** affected;
	unsigned char** rowContent;
	Style** styles;
	int width;
	int height;
	int anchorX;
	int anchorY;
public:
	ScreenComponent();
	
	void init();
	ScreenComponent(int startX, int startY, int width, int height);
	void init(int startX, int startY,int width, int height);
	~ScreenComponent();
	int getWidth();
	int getHeight();
	int getAnchorX();
	int getAnchorY();
	virtual void setFill(Style& s, bool invisible) = 0;
	bool getAffected(int x, int y);
	Style* getStyleSpecific(int x, int y);
	unsigned char getChar(int x, int y);
};



#endif
