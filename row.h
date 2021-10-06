#ifndef ROW_H
#define ROW_H

using namespace std;

class Row
{
private:
	unsigned char* rowContent; // same as byte
	int* styles;
	int width = 0;
	bool isProper = false;


public:
	Row();
	void setLen(int len);

	Row(int len);
	~Row()
	{
		if (isProper)
		{
			delete[] rowContent;
			delete[] styles;
		}

	}
	int getStyle(int i);
	char getCharacter(int i)
	{
		return rowContent[i];
	}
	void spaceFill();
};

#endif
