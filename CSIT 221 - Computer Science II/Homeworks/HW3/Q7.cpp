//Chp 12, Q7
#include <iostream>
using namespace std;


int main() {
  int num;
  int *numPtr;
  numPtr = &num;

  int stop;
  int inc;

  cout << "Input starting value: ";
  cin >> *numPtr;
  cout << "Input stopping value: ";
  cin >> stop;
  cout << "Input increment value: ";
  cin >> inc;
  cout << endl;

  while (*numPtr <= stop) {
    cout << num << " ";
    *numPtr += inc;
  }
  

  return 0;
}