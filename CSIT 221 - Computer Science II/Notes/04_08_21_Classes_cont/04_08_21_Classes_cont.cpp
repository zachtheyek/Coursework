//Q: Take an input string containing a roman numeral, and convert it to arabic numerals using the class definition in the header file (roman.h)

#include <iostream>
#include <string>
#include "roman.h"
using namespace std;

int main() {

	romanType myNum1("IV");
	myNum1.romanToPositiveInteger();
	myNum1.printRoman();
	myNum1.printPositiveInteger();

  romanType myNum2("VIII");
	myNum2.romanToPositiveInteger();
	myNum2.printRoman();
	myNum2.printPositiveInteger();

	cout << endl << "Number of objects: " << romanType::objCounter << endl;


	return 0;
}