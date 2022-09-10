#include <iostream>
using namespace std;

// Recursive function that returns the sum of squares from 1 up to some integer n (where n > 0)
int sum_of_squares(int n);

int main() {
    cout << sum_of_squares(5);
}

int sum_of_squares(int n) {
    if(n == 1) // base case
        return 1;
    
    return n * sum_of_squares(n - 1);
}