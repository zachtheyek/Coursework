//Chp 8, Q23
#include <iostream>
using namespace std;

//Define the dimensions of the matrix (i.e. rows and columns), the total number of elements in the matrix (i.e. rows * columns), and the number of iterations we want to run, as global constants
const int ROWS = 3;
const int COLS = 3;
const int PROD = ROWS * COLS;
const int ITER = 1000000;

//Define a function to randomly place each integer from 1 to 9 (or whatever the max is for larger matrices) into the matrix
void initMatrix (int matrix[][COLS]) {
  //We declare and define an array with integers 1 to 9 (or whatever the max is for larger matrices) sorted in ascending order
  int numbers[PROD];
  for (int a = 0; a < PROD; a++) {
    numbers[a] = a + 1;
  }

  //We then go through the matrix and randomly assign an integer from the previous array, making sure to delete the integer from the array once we assign it such that we don't assign two of the same integers
  for (int b = 0; b < ROWS; b++) {
    for (int c = 0; c < COLS; c++) {
      while (true) {
        int randomNum = rand() % PROD + 1;
        if (numbers[randomNum - 1] != 0) {
          matrix[b][c] = randomNum;
          numbers[randomNum - 1] = 0;
          break;
        } 
      }
    }
  }
}

//Define a function to print matrices
void printMatrix (int matrix[][COLS]) {
  for (int x = 0; x < ROWS; x++) {
    for (int y = 0; y < COLS; y++) {
      cout << matrix[x][y] << '\t';
    }
    cout << endl;
  }
  cout << endl;
}

//Define a function to calculate the magic number of a matrix (sum of all the numbers in the matrix, divided by 3), and returns true or false depending on whether the matrix is a magic square (i.e. the sums of each row, column, and diagonal are all equal to the magic number)
bool magicNumber (int matrix[][COLS]) {
  int magicNum, row, col, diag_left, diag_right, index = 0;
  int sum[ROWS * COLS + 2];

  //Using a double-nested for-loop, we loop through the matrix, calculating the sum of each individual row and column, and the sum of the two diagonals. We then append each of these sums to an array, for reference later. We also find the sum of every element in the matrix such that we can divide it by 3 to calculate the magic number
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      magicNum += matrix[i][j];
      row += matrix[i][j];  
      col += matrix[j][i];  

      if (i == j) {  
        diag_left += matrix[i][j];
      } if (i + j == COLS - 1) {  
        diag_right += matrix[i][j];
      }
    }
    sum[index++] = row;  
    sum[index++] = col;  
    row = 0;  
    col = 0;  
  }
  sum[index++] = diag_left;  
  sum[index++] = diag_right;  
  magicNum /= 3; 
    
  //Then, we loop through the array of sums, and compare each element to the magic number. We return true if and only if every sum in the array is equal to the magic number, otherwise we break and return false.
  for (int k = 0; k < index; k++) {
    if (sum[k] != magicNum) {
      return false;
    }
  } 
  return true;
}


int main () {
  //Declare a matrix with the appropriate dimensions, as well as an integer variable to keep track of how many of our matrices are magic squares
  int matrix[ROWS][COLS];
  int count;
    
  //For n iterations, we initialize the matrix, and find whether it's a magic square
  for (int x = 0; x < ITER; x++) {
    initMatrix (matrix);

    if (magicNumber (matrix) == true) {
      //Optional: if the matrix is a magic square, we print out the matrix
      //printMatrix (matrix);
      count += 1;
    }
  }

  //Finally, we print out a prompt telling us how many of our n matrices were perfect squares
  cout << "Number of magic squares in " << ITER << " trials: " << count << endl;

  return 0;
}