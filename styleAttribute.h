#ifndef STYLEATTRIB_H
#define STYLEATTRIB_H 1
#define INVALID_STYLE = -1404;
#include "styleAttribute.cpp"

class StyleAttribute
{
private: 
	bool isGood;
	int value;
	int* valueArr;
	bool isArr;
public:
	StyleAttribute();
	~StyleAttribute();
	StyleAttribute(int dat);
	StyleAttribute(int* dat,int length);
	bool isSet();
	int getValue();
	int* getValueArr();


};

#endif;