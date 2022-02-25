#include "MyString.h"

/*
Project 1 - MyString.

This is the MyString class methods
Benjamin Carter - 1/15/2022


Small note. I decided to use unsigned int / unsigned char for everything because the position of a element in a string will never be negative, and will also allow for longer strings in theory
And I used unsigned char as I want to work with 0-255 on the ASCII chart.
*/

MyString::MyString() // create an array of length one. 0 length string Big-O: O(1)
{
	lenArray = 1;
	currLength = 0;
	theArray = new unsigned char[lenArray];
}
MyString::MyString(const char* s) // convert the string into a character array Big-O: O(n)
{
	int lenArray = 0;
	char inc = s[0];
	while (inc != '\0')
	{
		length++;
	}

	lenArray = s.length();
	currLength = lenArray;
	theArray = new unsigned char[lenArray];
	for (unsigned int i = 0; i < s.length(); i++)
	{
		theArray[i] = s[i];
	}
}
MyString::MyString(const MyString &s) // copy constructor Big-O: O(n)
{
	lenArray = s.lenArray;
	currLength = s.currLength;
	theArray = new unsigned char[lenArray];
	for (unsigned int i = 0; i < s.currLength; i++)
	{
		theArray[i] = s.theArray[i];
	}
}
MyString::~MyString() // destroy!
{
	delete[] theArray;
}
std::ostream& operator<<(std::ostream& os, const MyString& s) // shift out to cout Big-O: O(n)
{
	
	for (unsigned int i = 0; i < s.currLength; i++)
	{
		cout << s.theArray[i];
	}
	//os << out; // must use a string because os has no idea how to interrupet a MyString (that would be recursive here)
	return os;
}
void MyString::ensureCapacity(unsigned int n) // If I do theArray[n], will I get a number or an error? This makes sure I will not get an error Big-O: O(n)
{

	// 0,1,2,3,4,5,_,7

	if (n > lenArray - 1)
	{
		// n is bigger!
		unsigned int newLength = n + 1;
		unsigned char* newArray = new unsigned char[newLength]; // if n is larger than the size of the array, increase it to become n+1 long
		for (unsigned int i = 0; i < newLength; i++)
		{
			if (i < currLength)
			{
				newArray[i] = theArray[i];
			}
		}
		delete[] theArray;
		theArray = newArray;
		lenArray = newLength;
	}
}
void MyString::ensureCapacity(unsigned int n, unsigned int l) // same as above, but makes sure that a string of size l will fit at index n. Big-O: O(n)
{
	
	// 0,1,2,3

	if (n + l > lenArray - 1)
	{
		// n is bigger!
		unsigned int newLength = n + l + 1;
		unsigned char* newArray = new unsigned char[newLength]; // if it doesn't fit, do n + l + 1
		for (unsigned int i = 0; i < newLength; i++)
		{
			if (i < currLength)
			{
				newArray[i] = theArray[i];
			}
		}
		delete[] theArray;
		theArray = newArray;
		lenArray = newLength;
	}
}


MyString MyString::operator+(const MyString& s) const // concat two strings Big-O: O(n)
{
	MyString theNewString;
	theNewString.ensureCapacity(s.lenArray + lenArray); // check to see if the newString can handle it.
	theNewString.currLength = s.currLength + currLength;
	for (unsigned int i = 0; i < currLength; i++)
	{
		theNewString.theArray[i] = theArray[i];   // add the first string letter by letter
	}
	for (unsigned int i = 0; i < s.currLength; i++)
	{
		theNewString.theArray[i + currLength] = s.theArray[i]; // add the second string letter by letter
	}
	return theNewString;
}
unsigned int MyString::length() const // Big-O: O(1)
{
	return currLength;
}
MyString MyString::concat(const MyString& s) const  // Big-O: O(1)
{
	return operator+(s);
}
bool MyString::operator==(const MyString& s) const // checks to see if string is equal. Big-O: O(n)
{
	if (s.currLength != currLength)
	{
		return false;
	}
	for (unsigned int i = 0; i < currLength; i++)
	{
		if (s.theArray[i] != theArray[i])
		{
			return false;
		}
	}
	return true;
}
bool MyString::operator<(const MyString& s) const // checks to see if a string is greater than a certain word. Big-O: O(n)
{
	// calculate the LEX-index and compare.
	unsigned int* lexOther = s.lexIndex();
	unsigned int* my = lexIndex();
	for (unsigned int i = 0; i < currLength; i++)
	{
		
		if (i < s.currLength)
		{
			if (lexOther[i] == my[i])
			{
				// continue
			}
			else
			{
				unsigned int t = my[i];
				unsigned int q = lexOther[i];
				delete[] my;
				delete[] lexOther;
				return t < q;
			}

		}
		else
		{
			delete[] my;
			delete[] lexOther;
			return true;
		}
	}
	delete[] my;
	delete[] lexOther;
	return true;

}
bool MyString::operator>(const MyString& s) const // same. Take advantage of the DeMorgan rule/logic rules. X is greater than Y if X<Y is not true and X==Y is not true.
{
	// Big - O: O(n)   because both are O(n)
	// calculate the LEX-index and compare.
	return (!operator<(s) && !operator==(s));
}
unsigned int* MyString::lexIndex() const // get the index of every letter on the ASCII table and put it onto an array. // Big-O: O(n)
{
	// find the value of the word. 
	// you need a max length??
	// 32 - 126. So 94 chars.

	//(i - 32) * 94
	unsigned int* out = new unsigned int[currLength];

	for (unsigned int i = 0; i < currLength; i++)
	{
		out[i] = (theArray[i] - 32) * 94 + 1;
	}

	return out;

}
unsigned char MyString::get(int x) const  //Big-O: O(1)
{
	return theArray[x];
}
unsigned char MyString::at(int x) const //Big-O: O(1)
{
	return get(x);
}
unsigned char MyString::operator[](unsigned int i) const //Big - O: O(1)
{
	return get(i);
}
MyString MyString::toLower() const // convert to lower. Add 32    Big-O: O(n)
{
	MyString theNewString;
	theNewString.ensureCapacity(lenArray);
	theNewString.currLength = currLength;
	for (unsigned int i = 0; i < currLength; i++)
	{
		if (theArray[i] < 91 && theArray[i] > 64)
		{
			theNewString.theArray[i] = theArray[i] + 32;
		}
		else
		{
			theNewString.theArray[i] = theArray[i];
		}
		
	}
	
	return theNewString;
}
MyString MyString::toUpper() const // covert to upper. Subtract 32  Big-O: O(n)
{
	MyString theNewString;
	theNewString.ensureCapacity(lenArray);
	theNewString.currLength = currLength;
	for (unsigned int i = 0; i < currLength; i++)
	{
		if (theArray[i] > 96 && theArray[i] < 123)
		{
			theNewString.theArray[i] = theArray[i] - 32;
		}
		else
		{
			theNewString.theArray[i] = theArray[i];
		}

	}
	return theNewString;
}
MyString MyString::substring(unsigned int start) const //create new string. Do a substring with a forLoop   Big-O: O(n)
{
	MyString theNewString;
	theNewString.ensureCapacity(lenArray);
	theNewString.currLength = currLength - start;
	int j = 0;
	for (unsigned int i = start; i < currLength; i++)
	{
		theNewString.theArray[j] = theArray[i];
		j++;

	}
	return theNewString;
}
MyString MyString::substring(unsigned int start,unsigned int end) const // same, but stop at end. Assumes that end is within bounds    Big-O: O(n)
{
	MyString theNewString;
	theNewString.ensureCapacity(lenArray);
	theNewString.currLength = end - start;

	// 0,1,2,3,4,5  currLen: 6, start: 2  end 4


	int j = 0;
	for (unsigned int i = start; i < end; i++)
	{
		theNewString.theArray[j] = theArray[i];
		j++;

	}
	return theNewString;
}
unsigned int MyString::indexOf(const MyString& s) const // will return INT_MAX if not found (it is unsigned!) - returns the first index of a word   Big-O: O(nm)  or O(n^2)  where n is the current MyString and m is the MyString to find
{
	unsigned int out = -1; // return INT_MAX if not found. (unsigned)
	if (s.currLength > currLength)
	{
		return -1;
	}
	
	for (unsigned int i = 0; i < currLength - s.currLength + 1; i++)
	{
		out = i;
		for (unsigned int j = 0; j < s.currLength; j++)
		{
			if (s.at(j) != at(i+j))
			{
				out = -1;
				break;
			}
		}
		if (out != -1)
		{
			return out;
		}
	}
	return out;
}
unsigned int MyString::lastIndexOf(const MyString& s) const // will return INT_MAX if not found (it is unsigned!) returns the last index of a word. Counts backwards
{
	// Big-O: O(nm)  or O(n^2)  where n is the current MyString and m is the MyString to find
	unsigned int out = -1;
	if (s.currLength > currLength)
	{
		return -1;
	}

	for (unsigned int i = currLength-s.currLength; i > s.currLength - 1; i--)
	{
		out = i;
		for (unsigned int j = 0; j < s.currLength; j++)
		{
			if (s.at(j) != at(i+j))
			{
				out = -1;
				break;
			}
		}
		if (out != -1)
		{
			return out;
		}
	}
	return out;
}

