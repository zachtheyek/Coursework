#include <iostream>
using namespace std;


//this program prints out the multiplication tables of the numbers 1 through 9 (1*1 up till 9*9)

int main() {
  int i, j;
  for(i = 1; i < 10; i++){
    for(j = 1; j < 10; j++){
      cout << i << " * " << j << " = " << i * j << "\n";
    }
    cout << "\n";
  }
}
