#include <iostream>
#include <string>
using namespace std;

//we can pass a pointer by value through a function
void printByVal (int *x) {
  cout << "By value: " << endl; 
  cout << "Address of pointer: " << x << endl;
  cout << "Value of pointer: " << *x << endl << endl;

  x = new int(20);
}

//we can also pass a pointer by reference through a function
void printByRef (int *&x) {
  cout << "By reference: " << endl; 
  cout << "Address of pointer: " << x << endl;
  cout << "Value of pointer: " << *x << endl << endl;

  x = new int(20);
}


int main() {

  //Q: write a program that prompts the user to input a string, and outputs the string in all uppercase (use a dynamic character array to store the string).

  int stringSize;
  cout << "Input the size of your string: ";
  cin >> stringSize;
  cin.ignore (numeric_limits <streamsize>::max (), '\n');   //prompt the user for the size of the input string

  char *p;   //declare a pointer that points to a char memory location
  p = new char[stringSize];   //create a character array and point to it using the character pointer

  cout << "Input a lowercase string: ";
  cin.get (p, stringSize + 1);   //take a string input from the user, and store each character individually in the dynamic character array we declared above; note that the second input to the cin.get function is the number of characters that we're storing, i.e. the size of the string, where we +1 because at the end of every string is an implicit /n that we must account for

  cout << "Uppercase string: ";
  for (int i = 0; i < stringSize; i++) {
    cout << char(int(p[i]) - 32);
  }
  cout << endl << endl;


  //next, let's look at passing pointers through functions
  int *q;
  q = new int(5);   //we initialize our integer pointer q, using a constructor call int(), where we don't necessarily have to include an actual value in the call (in which case *q = 0)

  cout << "q points to: " << q << endl;
  cout << "q: " << *q << endl << endl;

  //notice that even though we changed the value of the pointer in the function (and thus the memory location that it's pointing to), because we pass the pointer by value, the actual memory location and value of the pointer isn't changed outside the function. This is the same as when passing normal variables by value
  printByVal(q);
  printByVal(q);

  //the same is not true when passing a pointer by reference through a function (notice that the memory address and value of q is different the second time). This is again the same as when passing normal variables by reference
  printByRef(q);
  printByRef(q);

  //note that similar to how "new" allocates memory, "delete" frees up that memory for use again. Both "new" and "delete" works on all data types
  //a memory leak occurs when we allocate memory for use but we don't free up that memory, meaning the excess memory can't be used for other things, and is still occupied even after the program has finished running


  return 0;
}