#ifndef ROW_H
#define ROW_H
#include "styles.h"
#include "console.h"
#include "MyString.h"


class DLLHEADER Row
{
private:
	unsigned char* rowContent; // same as byte
	Style* styles;
	int width = 0;
	bool isProper = false;
	bool isRender = false;
	
	MyString renderString = "";

public:
	void renderLine();
	Row();
	void init();
	void setLen(int len);
	
	Row(int len);
	void init(int len);
	~Row();
	MyString getStyle(int i);
	unsigned char getCharacter(int i)
	{
		return rowContent[i];
	}
	void spaceFill();
	void putString(MyString s, int start);
	void putString(MyString s, int start, Style sty);
	void setStyle(int i, Style s);
	void setRowStyle(Style s);
	void setRender(bool r);
	bool getRenderState();
	void setChar(unsigned char c, int i);
	void setStyle(Style& s, int i);
	MyString getRenderResult();
	Style getStyleObj(int i);
};

#endif
