#include "styleAttribute.h"
StyleAttribute::StyleAttribute()
{
	isGood = false;
	isArr = false;
}
StyleAttribute::StyleAttribute(int* dat)
{
	isGood = false;
	isArr = false;
	int leng = sizeof(dat) / sizeof(int);
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
