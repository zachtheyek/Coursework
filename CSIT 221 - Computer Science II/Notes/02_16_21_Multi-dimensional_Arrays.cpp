#include <iostream>
using namespace std;

//arrays, including 2D arrays, are passed through functions by reference; we need not specify the number of rows being passed through, but we have to specify the number of columns
void printMatrix (int twoArr[][3]) {
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      cout << twoArr[row][column] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

int main () {
  //we can combine the declaration and definition statement of an array; note that we have to specify the data type, and the number of elements
  int myArray[5] = {1, 2, 3, 4, 5};

  //notice that all three statements point to the same memory location
  cout << myArray << endl;
  cout << &myArray << endl;
  cout << &myArray[0] << endl;
  cout << "\n";

  //we can also redefine elements of an array, so long as they're of the same data type that we initially declared the array to be
  myArray[3] = 10;

  //we can print the elements of an array one-by-one using a loop (for or while)
  for (int i = 0; i < 5; i++) {
    cout << myArray[i] << " ";
  }
  cout << "\n";

  int j = 0;
  while (j < 5) {
    cout << myArray[j] << " ";
    j++;
  }
  cout << "\n\n";


  //moving onto 2D arrays, i.e. lists of lists 
  //note that the two []'s refer to the rows and columns, respectively
  int twoArray[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  //though it's not required, it's most intuitive to print the elements of a 2D array using nested loops
  //to make things easier, we define a function printMatrix that prints a 2D array, using a for-loop (see above)
  printMatrix (twoArray);

  //Q: make the diagonal elements of our 2D array zeros
  //notice that since the diagonals occur when the index of the row is the same as the column, we only need to use a single loop
  for (int k = 0; k < 3; k++) {
    twoArray[k][k] = 0;
  }
  printMatrix (twoArray);

  //we can also print a specific row, e.g. first row
  int row = 0;
  for (int x = 0; x < 3; x++) {
    cout << twoArray[row][x] << " ";
  }
  cout << "\n\n";

  //and the same thing can be done for columns
  int column = 0;
  for (int y = 0; y < 3; y++) {
    cout << twoArray[y][column] << "\n";
  }
  cout << "\n";

  //Q: given a 3x3 array, convert it into a 1D array where the rows are joined tail-to-head
  int oneArray[9];
  int index = 0;
  for (int a = 0; a < 3; a++) {
    for (int b = 0; b < 3; b++) {
      oneArray[index] = twoArray[a][b];
      index ++;
    }
  }
  
  for (int c = 0; c < 9; c++) {
    cout << oneArray[c] << " ";
  }

  return 0;
}
