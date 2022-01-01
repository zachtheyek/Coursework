#ifndef _ROMAN_CLASS_
#define _ROMAN_CLASS_

#include <iostream>
#include <string> 
using namespace std;

class romanType {
public:
	static int objCounter;

  romanType();
	romanType(string str);

	void setRoman(string str);
	void romanToPositiveInteger();
	void printPositiveInteger();
	void printRoman();

private:
	string romanNum;
	int num;
};

#include "roman.cpp"
#endif