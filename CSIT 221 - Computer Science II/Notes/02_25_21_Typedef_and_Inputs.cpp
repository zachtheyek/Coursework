#include <iostream>
#include <string>
using namespace std;

//this is a global constant (indicated by const), which means that no function can change its value
const int SIZE = 10;

//this is a macro definition, i.e. we define an identifier using the #define function, and we assign it a replacement. When compiling, the preprocessor replaces all instances of the identifier with its corresponding replacement
#define ROWS 5
#define COLS 5

//the typedef function does the same thing as the #define function, except instead of redifining a variable (the identifier), it redefines a datatype (i.e. int, char, str, etc.). When the preprocessor encounters the user-defined datatype during compilation, it will point back to its corresponding original datatype
//ex: (1) whenever we call myIntType, the compiler reads it as int a, where a is some variable. See below for example
//ex: (2) whenever we call myArrayType, the compiler reads it as int a[ROWS][COLS], where a is some variable. See below for example
typedef int myIntType;  
typedef int myArrayType[ROWS][COLS]; 

int main() {

  //declaring a variable of type myIntType
	myIntType a = 90;
	cout << a << endl << endl;

	//declaring a variable of type myArrayType
	myArrayType b;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			b[i][j] = 0;
		}
	}
  for (int k = 0; k < ROWS; k++) {
		for (int l = 0; l < COLS; l++) {
			cout << b[k][l] << "\t";
		}
    cout << endl;
	}
  cout << endl;


  //we know that the cout function works like the print() function in Python, in that it's an output statement used to print/display something on the screen. It's compatible with most data types, and uses the extraction operator <<
	//the cin function on the other hand works like the input() function in Python; it's an input statement used to take an input from files, consoles, etc, and uses the insertion operator >>


  //Q: replace the second entry in a list string of lists with a user-given input taken using the cin function

  //using the <string> package, we can define an array of strings
	string list[SIZE] = { "First", "Second", "Third", "Fourth" };

  //print the original array
  for (int x = 0; x < 4; x++) {
    cout << list[x] << ", ";
  }
  cout << endl << endl;

  //note that the cin function will take an input, as long as there are no spaces ' ' in between, i.e. if the user-input is "Hello world", the cin function will only store the string "Hello", and terminate when it sees the space after. To circumvent this, we can use the getline() function to save the whole user-input as a single line, such that cin doesn't terminate at a space
  cout << "Please enter a string: ";
	getline(cin, list[1]);

  //print the augmented array
	for (int y = 0; y < 4; y++) {
    cout << list[y] << ", ";
  }
  cout << endl;
  
	return 0;
}