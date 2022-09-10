#include <iostream>
using namespace std;

// Recursive function that prints the digits of a decimal integer n in reverse order
void print_reverse_int(int n);

int main() {
    print_reverse_int(12345);
}

void print_reverse_int(int n) {
    if(n == 0) // base case
        return;
    
    cout << n % 10; // use the modulo operator to retrive the last digit
    print_reverse_int(n / 10); // remove the last digit via integer division
}