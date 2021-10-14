#include "styleAttribute.h"
StyleAttribute::StyleAttribute()
{
	isGood = false;
	isArr = false;
}
StyleAttribute::~StyleAttribute()
{
	if (isGood)
	{
		delete[] valueArr;
	}
}
StyleAttribute::StyleAttribute(int* dat,int length)
{
	isGood = true;
	isArr = true;
	int leng = length;
	valueArr = new int(length);
	for (int x = 0; x < leng; x++)
	{
		valueArr[x] = dat[x];
	}
}
void StyleAttribute::setArr(int* dat, int length)
{
	isGood = false;
	isArr = false;
	int leng = length;
	valueArr = new int(length);
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
}
void StyleAttribute::setValue(int dat)
{
	isGood = true;
	isArr = false;
	value = dat;
}

bool StyleAttribute::isSet()
{
	return isGood;
}
int StyleAttribute::getValue()
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
int* StyleAttribute::getValueArr()
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
