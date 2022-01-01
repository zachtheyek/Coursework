//This is a separate .cpp file that includes the function definitions for the class defined in its respective header file (which shares the same name)
#include <iostream>
#include "countertype.h"
using namespace std;

void counterType::set_counter(int val) {
  if(val > 0) {
    counter = val;
  }
  else {
    counter = 0;
    cout << "Negative argument provided. Object value set to 0." << endl;
  }
}

unsigned int counterType::get_count() const {
  return counter;
}
  
void counterType::increment() {
  counter += 1;
}

void counterType::decrement() {
  if(counter > 0) {
    counter -= 1;
  }
  else {
    cout << "Counter cannot be decremented further." << endl;
  }
}