#include "styleAttribute.h"
#include <iostream>
using namespace std;

int StyleAttribute::testNumber = 0;

StyleAttribute::StyleAttribute()
{
	testID = testNumber;
	//cout << "Creating " << testID << endl;
	isGood = false;
	isArr = false;
	value = 0;
	valueArr = new int[5];
	testNumber++;
}
StyleAttribute::~StyleAttribute()
{
	//cout << "Problem" << testID << " " << isDestroyed << endl;
	if (!isDestroyed)
	{
		delete[] valueArr;
	}
	isDestroyed = true;
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
void StyleAttribute::setArr(int* dat, int length)
{
	isGood = true;
	isArr = false;
	int leng = length;
	delete[] valueArr;
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
