#ifndef RECTH_H
#define RECTH_H

#include "screenComponent.h"
#include "styles.h"

class Rectangle2D : public ScreenComponent
{
private:
	Style border;
	Style fill;
	bool isBorder = false;
public:

	Rectangle2D();
	
	void init();
	Rectangle2D(int startX, int startY,int w, int h);
	void init(int startX, int startY, int w, int h);
	~Rectangle2D();
	void setFill(Style& s,bool invisible);
	void setBorder(Style& s);
	void removeBorder();
	
};



#endif
