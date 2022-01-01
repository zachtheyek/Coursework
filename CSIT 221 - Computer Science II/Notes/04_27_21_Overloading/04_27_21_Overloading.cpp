/*
Notes (04/27/21)

We can overload pre-existing functions in C++ to accomodate user-defined structures/classes, e.g. the '*', '-', '%', '+=', '==', 'cout' operators etc. This means that instead of defining a printClass() function in a class, we can simply overload the cout operator, and so forth.
*/

#include <iostream>
#include "countertype.h"
using namespace std;

int main() {

  counterType myCount1(5);
  counterType myCount2(10);
  counterType myCount3;
  counterType myCount4;

  //after overloading the '+' and '-' operators, we can perform actions like these without having to define entirely new functions in the class
  myCount3 = myCount1 + myCount2;
  myCount4 = myCount2 - myCount1;

  //similarly, after overloading the '++', '--', and '<<' operators, we can perform actions like these as well
  cout << "Before: " << myCount3 << endl;
  cout << "After: " << myCount3++ << endl << endl;
  cout << "Before: " << myCount4 << endl;
  cout << "After: " << myCount4-- << endl << endl;

  
  return 0;
}