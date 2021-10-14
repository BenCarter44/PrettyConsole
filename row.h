#ifndef ROW_H
#define ROW_H
#include "styles.h"

using namespace std;

class Row
{
private:
	unsigned char* rowContent; // same as byte
	Style* styles;
	int width = 0;
	bool isProper = false;


public:
	Row();
	void setLen(int len);

	Row(int len);
	~Row()
	{
			delete[] rowContent;
			delete[] styles;
		
	}
	string getStyle(int i);
	char getCharacter(int i)
	{
		return rowContent[i];
	}
	void spaceFill();
	void putString(string s, int start);
};

#endif
