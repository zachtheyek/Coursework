/*
Notes:
  Static arrays are arrays which have a fixed size. Using pointers, we can create dynamic arrays, where its sized is determined at runtime. This means that our overall code takes up less memory than if we were to use static arrays.
*/

#include <iostream>
#include <string>
using namespace std;

struct studentType {
  string FName;
  string LName;
  int ID;
  float gpa;
};

int main() {
  
  //a normal variable stores a value, where we can access its memory location using the '&' operator
  int iVar = 0;
  cout << "Value of iVar: " << iVar << endl;
  cout << "Memory location of iVar: " << &iVar << endl;

  //a pointer variable (denoted with the '*' operator at declaration) stores a memory location
  int *pVar = &iVar;   //here we assign the memory location of iVar to a pointer pVar
  //after declaration, the memory location of a pointer is accessed simply by calling the pointer normally (without the '*' operator), and the value stored at the memory location is accessed by attaching the '*' operator to the pointer
  cout << "Value of pVar: " << *pVar << endl;   
  cout << "Memory location of pVar: " << pVar << endl;

  int *pVar2 = pVar;   //here we assign the memory location that pVar points to to another pointer pVar2
  cout << "Value of pVar2: " << *pVar2 << endl;
  cout << "Memory location of pVar2: " << pVar2 << endl << endl;

  //notice that all 3 variables point to the same memory location, meaning if we assign a value to the memory location (using any of the 3 variables/pointers), the change will be reflected by all 3 variables/pointers
  *pVar2 = 10;
  cout << "Value of iVar: " << iVar << endl;
  cout << "Value of pVar: " << *pVar << endl; 
  cout << "Value of pVar2: " << *pVar2 << endl << endl;

  //to declare a pointer that points to nothing, we use the 'nullptr' or 'NULL' command
  int *a = nullptr;
  int *b = NULL;

  /*

  //pointers can be created for any data type, even user-defined data types (structs)
  studentType student;
  studentType *studentPtr;

  //to assign values to a struct pointer, we can do so using the usual '.' operator, or the '->' operator, like so
  student.gpa = 3.9;
  (*studentPtr).gpa = 3.9;
  studentPtr -> gpa = 3.9;

  */


  //now, we move on to dynamic arrays 
  //first, we declare an integer pointer p
  //then, we let p point to a new array of size 10 using the "new" command (note that "new" forces the system to allocate memory even if nothing is pointing to the memory address, that is, if we simply use "new" without explicitly having a pointer point to the allocated memory, the memory will be lost)
  //we have created a dynamic array
  int *p;   
  p = new int[10];

  //dynamic arrays work similarly to static arrays
  for (int i = 0; i < 10; i++) {   //here, we initialize the array like we would normally
    p[i] = i;
  }
  
  int iter = 0;
  while (iter < 10) {   //here, we print the array like we would normally
    cout << *p << '\t';
    p++;   //the main difference for dynamic vs static arrays is instead of incrementing the index, we increment the memory location
    iter ++;
  }
  cout << endl;

  //however, notice that after the last iteration of the while loop, we increment p to where it points to a memory address outside the memory of the dynamic array, hence we get a weird output when trying to print (p[0] points to the first memory location of the array since p is a pointer)
  cout << p[0] << endl;

  //to correct for this, simply increment p backwards once to go back to the memory of the dynamic array (now p points to the last element of the dynamic array as the first memory location)
  p--;
  cout << p[0] << endl << endl;


  //to declare a 2D dynamic array, we first declare an array of pointers, and have each pointer point to a new array
  int *address[5];
  for (int j = 0; j < 5; j++) {
    address[j] = new int[5];
  }

  //note that while 2D dynamic arrays are declared differently to 2D static arrays, they work mostly in the same manner
  for (int k = 0; k < 5; k++) {   //initialize the array
    for (int l = 0; l < 5; l++) {
      address[k][l]= 0;
    }
  } 

  for (int m = 0; m < 5; m++) {   //print the array
    for (int n = 0; n < 5; n++) {
      cout << address[m][n] << '\t';
    }
    cout << endl;
  }


  return 0;
}