//Chp 12, Q10
#include <iostream>
#include <iomanip>
using namespace std;


int main() {
  double *baseRadius;
  double *height;

  cout << fixed << showpoint << setprecision(2);

  baseRadius = new double;
  *baseRadius = 1.5;

  height = new double;
  *height = 2 * (*baseRadius);

  baseRadius = new double;
  *baseRadius = 4.0;

  //after making the necessary corrections, the outputs of the following statements are 4.00, 3.00, 50.24, and 75.36, respectively
  cout << "Radius of the base: " << *baseRadius << endl;
  cout << "Height: " << *height << endl;
  cout << "Volume: " << 3.14 * (*baseRadius) * (*baseRadius)
  << endl;
  cout << "Surface area: "
  << 2 * 3.14 * (*baseRadius) * (*height) << endl;


  return 0;
}