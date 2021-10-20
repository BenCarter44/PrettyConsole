#include "styleAttribute.h"
#include <iostream>
using namespace std;

//int StyleAttribute::testNumber = 0;


void StyleAttribute::init()
{
	if (isGood && isArr)
	{
		delete[] valueArr;
	}
	isGood = false;
	isArr = false;
	value = 0;
	valueArr = NULL;
}


StyleAttribute::StyleAttribute()
{
	isGood = false;
	isArr = false;
	value = 0;
	valueArr = NULL;
	
}
StyleAttribute::~StyleAttribute()
{
	if (isGood && isArr)
	{
		delete[] valueArr;
		isGood = false;
	}
}
StyleAttribute::StyleAttribute(int* dat,int length)
{
	isGood = true;
	value = 0;
	isArr = true;
	int leng = length;
	valueArr = new int[length];
	for (int x = 0; x < leng; x++)
	{
		valueArr[x] = dat[x];
	}
}
void StyleAttribute::init(int* dat, int length)
{

	setArr(dat, length);
}

void StyleAttribute::setArr(int* dat, int length)
{
	if (isGood && isArr)
	{
		delete[] valueArr;
	}
	isGood = true;
	isArr = true;
	int leng = length;

	valueArr = new int[length];
	for (int x = 0; x < leng; x++)
	{
		valueArr[x] = dat[x];
	}
}
StyleAttribute::StyleAttribute(int dat)
{
	isGood = true;
	isArr = false;
	value = dat;
	valueArr = new int[5];
}
void StyleAttribute::init(int dat)
{
	if (isGood && isArr)
	{
		delete[] valueArr;
	}
	isGood = true;
	isArr = false;
	value = dat;
	valueArr = new int[5];
}
void StyleAttribute::setValue(int dat)
{
	isGood = true;
	isArr = false;
	value = dat;
}

bool StyleAttribute::isSet() const
{
	return isGood;
}
int StyleAttribute::getValue() const
{
	if (isGood)
	{
		return value;
	}
	else
	{
		return INVALID_STYLE;
	}
}
int* StyleAttribute::getValueArr() const
{
	if (isGood)
	{
		return valueArr;
	}
	else
	{
		return nullptr; // return NULL
	}
}
