#ifndef STYLEATTRIB_H
#define STYLEATTRIB_H 1
#define INVALID_STYLE -1404;


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
	void setArr(int* dat, int length);
	void setValue(int dat);
	bool isSet();
	int getValue();
	int* getValueArr();


};

#endif;