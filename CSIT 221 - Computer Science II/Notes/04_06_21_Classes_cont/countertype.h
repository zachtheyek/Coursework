/*
  This is a header file, and is used to separate class definitions from the main .cpp file. It serves 2 purposes: 
    1. to streamline the main .cpp file and avoid clutter
    2. to make it easier to reuse class definitions (since we can import the same header file for different .cpp files)

  To use header files, simply write: #include "filename.h" at the start of a .cpp file

  Additionally, we can create a separate .cpp file with the same name as the header file, and include the function definitions in there to streamline the header file itself (i.e. we only include function headings in the header file). To do so, we must write: #include "filename.cpp" at the end of the class definitions. 
    Note that we can remove the separate .cpp file that contains our function definitions from the project directory (it's not deleted, just not visible from our working directory). This is useful when we have a large number of header files, such that we don't want to clutter our workbench.
*/
#ifndef _CLASS_   //meaning: if this header file has not been compiled (see next line)
#define _CLASS_   //meaning: then compile this header file

#include <iostream>
using namespace std;

class counterType {
  int counter;

public:
  //constructors
  counterType(): counter(0) {}
  counterType(int start_val) {
    if (start_val > 0) {
      counter = start_val;
    }
    else {
      counter = 0;
      cout << "Negative argument provided. Object initialized to 0." << endl;
    }
  }

  //function headings
  void set_counter(int val);
  unsigned int get_count() const;   //unsigned int means the integer must be positive
  void increment();
  void decrement();
};

#include "countertype.cpp"   //this is an implementation of the class, since "countertype.cpp" includes the class function definitions. However, since "countertype.cpp" starts with the line: #include "countertype.h", we're essentially implementing the class twice, since the main .cpp file also starts with the line: #include "countertype.h". To prevent this, we include the lines: #ifndef _CLASS_, and #define _CLASS_, at the beginning of our header file, which act like if statements. Basically, they require that this header file only compiles if it hasn't already. If it has been compiled, then skip the line: #include "countertype.h"

#endif   //since the first line of a header file is: #ifndef _CLASS_, (i.e. the start of an if statement), we must explicity call endif on the last line