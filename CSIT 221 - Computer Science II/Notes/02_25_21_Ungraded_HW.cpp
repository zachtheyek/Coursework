//Q: Write a program that parses through a 2D array, and determines whether a given entry is a local max (peak) or a local min (trough), relative to its immediate neighbors.
#include <iostream>
using namespace std;

//Define the dimensions of the array, and the range to which we wish to compare a given entry, as global constants
const int ROWS = 10;
const int COLS = 10;
const int RANGE = 1;

//Define a function to initialize a 2D array with random values between 1 - 100 assigned to each entry
void initMatrix (int matrix[][COLS]) {
  for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			matrix[i][j] = rand() % 100 + 1;
		}
	}
}

//Define a function to print a 2D array
void printMatrix (int matrix[][COLS]) {
  for (int a = 0; a < ROWS; a++) {
		for (int b = 0; b < COLS; b++) {
			cout << matrix[a][b] << '\t';
		}
		cout << endl;
	}
  cout << endl;
}

//Define a function that generates two parallel arrays of row and column indeces that are within our range of consideration
void defineRange (int row_range[], int col_range[], int &row_index, int &col_index) {
  int range = -1 * RANGE;

  for (int p = 0; p < (2 * RANGE + 1); p++) {
    row_range[p] = row_index + range;
    col_range[p] = col_index + range++;
  }
}


int main() {
  //Declare and initialize our 2D array
	int matrix[ROWS][COLS];
  initMatrix (matrix);
  printMatrix (matrix);

  //Declare two parallel matrices to store the row and column indeces that are within our range of consideration, using the defineRange() function
  int row_range[2 * RANGE + 1] = {};
  int col_range[2 * RANGE + 1] = {};

  //Loop through every entry in our 2D array
  for (int x = 0; x < ROWS; x++) {
    for (int y = 0; y < COLS; y++) {
      //Declare two variables to store the largest and smallest values as we move through the 2D array. By default, we assume the current entry to be the largest/smallest
      int largest = matrix[x][y];
      int smallest = matrix[x][y];

      defineRange(row_range, col_range, x, y);

      //Compare the current entry to its immediate neighbors. If we find its neighbor to be larger/smaller than itself, we replace the corresponding variables with the appropriate values
      for (int q = 0; q < (2 * RANGE + 1); q++) {
        for (int r = 0; r < (2 * RANGE + 1); r++) {
          int compare_largest = matrix[row_range[q]][col_range[r]];
          int compare_smallest = matrix[row_range[q]][col_range[r]];

          if (largest < compare_largest) {
            largest = compare_largest;
          }
          if (smallest > compare_smallest) {
            smallest = compare_smallest;
          }
        }
      }

      //If the current entry is larger/smaller than all of its immediate neighbors, then we print the appropriate prompt
      if (largest == matrix[x][y]) {
        cout << "Peak at: (" << x << ", " << y << ")" << endl;
      }
      if (smallest == matrix[x][y]) {
        cout << "Trough at: (" << x << ", " << y << ")" << endl;
      }
    }
  }
  return 0;
}
