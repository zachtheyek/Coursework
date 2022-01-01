/*
  Constructors (and destructors) by definition are overloaded functions (i.e. same name, different number of inputs). Which constructor that runs depends on how many inputs are given when declaring an object of that class. Note that similar to other functions of a class, constructors can also be defined outside the class definition using the scope resolution '::'. Here is another way of writing constructors: 
    Rectangle(int w, int h): width(w), height(h) {}

  At declaration, an array of a given class with n objects will always be initialized by the same constructor, that is, the default constructor.
    We can change the values of each individual object in the array after declaration

  Destructors are called automatically whenever an object goes out of scope
  Destructors (like constructors) have the same name as the class, but destructors have a '~' symbol at the start of their name

  Classes are a foundation of object oriented programming. The main benefit of object oriented programming is that we can reuse header files (i.e. class definitions). It's for this reason that in object oriented programming, we typically define classes in separate header files. This main file is our driver, where we simply "test" our other header files.
*/

//Q: Define a class counterType to implement a counter. Your class must have a private data member counter of type int, and functions to set counter to the value specified by the user. Initialize the counter to 0, retrieve the value of counter, and increment and decrement counter by one. Note that the value of counter must be non-negative.

#include <iostream>
#include "countertype.h"
using namespace std;


int main() {

  counterType firstCount;
  cout << "First counter: " << firstCount.get_count() << endl << endl;

  counterType secondCount(10);
  cout << "Second counter (before increment): " << secondCount.get_count() << endl;
  secondCount.increment();
  cout << "Second counter (after increment): " << secondCount.get_count() << endl << endl;

  counterType thirdCount(-30);
  cout << "Third counter: " << thirdCount.get_count() << endl;

  
  return 0;
}