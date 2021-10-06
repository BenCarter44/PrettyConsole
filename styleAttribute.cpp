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
	isGood = false;
	isArr = false;
	int leng = length;
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

bool StyleAttribute::isSet()
{
	return isSet;
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
