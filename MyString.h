
/*
Project 1 - MyString.

This is the MyString class header
Benjamin Carter - 1/15/2022
*/

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>


class MyString
{
private:
	unsigned char* theArray;  // the array that holds characters
	unsigned int lenArray;  // the length of the array
	unsigned int currLength;  // the length of the string. The length of the string can be less than the length of the array.
	void ensureCapacity(unsigned int n); // make sure that there would not be an error for accessing the index n
	void ensureCapacity(unsigned int n, unsigned int l); // make sure that there would not be an error for access the index n through n+(l-1)

public:
	MyString(); // create an empty container for characters
	MyString(const char* s); // a constructor that converts a string to a MyString
	MyString(const MyString &s); // a copy constructor
	~MyString(); // destroy
	friend std::ostream& operator<<(std::ostream& os, const MyString& dt); // runs if you do cout << foo. foo.operator(foo) 
	
	MyString operator+(const MyString &s) const; // concat two strings
//	void show() const; // disp to console
	unsigned int length() const; // find the length of the string
	MyString concat(const MyString &s) const; // also concat
	bool operator==(const MyString &s) const; // isEqual
	bool operator<(const MyString &s) const; // is less than, is greater than. Order of word in dictionary
	bool operator>(const MyString &s) const;
	unsigned int* lexIndex() const; // a helper method that the operator< and > use. Calculates the letter index for each letter in a MyString
	unsigned char get(int x) const; // get character x
	unsigned char at(int x) const; 
	unsigned char operator[](unsigned int i) const; // get character i
	MyString toLower() const; // convert toUpper           // use the ASCII table!
	MyString toUpper() const;  // convert toLower
	MyString substring(unsigned int start) const; //return a MyString starting at "start" and going to the end of the MyString
	MyString substring(unsigned int start, unsigned int end) const; // return a MyString starting at "start" and ending one element before "end"
	unsigned int indexOf(const MyString& s) const; // find the first index of the MyString s in the MyString
	unsigned int lastIndexOf(const MyString& s) const; // find the last index of the MyString s in the MyString
	


};
#endif