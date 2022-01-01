#include <iostream>
using namespace std;
/*
Note that functions can be defined above the main() function (like we do in Python), or below the main() function, in which case, we have to include the function heading above the main() function. 

Also note that we don't have to include names for our parameter list (we could, but if we change it in the function definition, we have to also change it in the function heading).

The following is an example of overloading functions, i.e. defining two functions with the same name, but different parameter lists 
*/
int add (int, int);  
int add (int, int, int);


//next, let's write a simple function that does division
int divide (int, int);
/*
A natural question arises: what if we wanted to divide double values? or float values? 

One solution is to define an entirely new function that returns double/float instead of int, but an even better solution is to write a general function that handles data types automatically (this is called templating).

The heading for a templated function is written as follows. 

Note that T could also represent user-defined data types. Also note that T is local to this function, i.e. it can't be "seen" outside the scope of the divide function. This means that we can reuse T as a class for other functions, similar to how we can reuse loop variables i, j, k, etc. for multiple functions.

Once again, note that templates only relate to data types and nothing else, i.e. they're not variables!
*/
template <class T>
T divide (T, T);


/*
Next, we shall look at passing parameters by value or by reference through functions

Below are two examples of the same subtract function, where the first one is an int function that returns an integer value after we pass both parameters by value, while the second one is a void function that returns nothing after we pass two parameters by value and one by reference. 
*/
int subtract (int, int);
void subtract (int, int, int&);


int main () {

    cout << add (3, 4) << endl;
    cout << add (3, 4, 10) << endl << endl;


    cout << divide(5, 2) << endl;
    //When calling a templated function, it's convention to mention the data type that we're assuming in our function call, to make our code more readable. Below we assume integers, floating points, and doubles, respectively.
    cout << divide <int> (5, 2) << endl;
    cout << divide <float> (5.0, 2.0) << endl;
    cout << divide <double> (5.0, 2.0) << endl << endl;


    //Notice that because the second subtract function is a void function, we can't put it in a cout statement
    int result;
    cout << subtract (10, 3) << endl;
    subtract (10, 3, result);
    cout << result << endl;


    return 0;
}


int add (int a, int b) {
    return a + b;
}

int add (int a, int b, int c) {
    return a + b + c;
}

int divide (int a, int b) {
    if (b == 0) {
        cout << "Undefined" << endl;
        return 0;
    }
    return a/b;
}

template <class T> 
T divide (T a, T b) {
    if (b == 0) {
        cout << "Undefined" << endl;
        return 0;
    }
    return a/b;
}

int subtract (int a, int b) {
  return a - b;
}

void subtract (int a, int b, int &result) {
  result = a - b;
}