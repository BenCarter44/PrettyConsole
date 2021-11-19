#ifndef LINE_H
#define RECTH_H

#include "screenComponent.h"
#include "styles.h"
#include "console.h"
class Line2D : public ScreenComponent
{
private:
	Style fill;
public:

	Line2D();

	void init();
	Line2D(int startX, int startY, int endX, int endY);
	void init(int startX, int startY, int endX, int endY);
	~Line2D();
	void setFill(Style& s, bool invisible);

};



#endif
