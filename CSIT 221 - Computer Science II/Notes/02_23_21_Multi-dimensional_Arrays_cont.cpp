#include <iostream>
using namespace std;

const int row = 6;
const int col = 6;
const int len = 10;

//initialize a 6x6 two-dimensional integer array with all zeros
void initMatrix (int twoArr[][col]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			twoArr[i][j] = 0; 
		}
	}
}
//initialize a 10 element one-dimensional integer array from 1 to 10
void initArray (int oneArr[]) {
  for (int k = 0; k < len; k++) {
    oneArr[k] = k + 1;
  }
} 

//print a 6x6 two-dimensional integer array
void printMatrix (int twoArr[][6]) {
	for (int a = 0; a < row; a++) {
		for (int b = 0; b < col; b++) {
			cout << twoArr[a][b] << " ";
		}
		cout << endl; 
	}
	cout << endl;
}
//print a 10 element one-dimensional integer array
void printArray (int oneArr[]) {
	for (int c = 0; c < len; c++) {
		cout << oneArr[c] << " ";
	}
	cout << endl;
}


int main () {
  //Q1: Initialize a 6x6 two-dimensional integer array with all zeros, and change it to its gradient, column-wise
  int doubleArray[row][col];
  initMatrix (doubleArray);

  cout << "Before gradient:" << endl;
  printMatrix (doubleArray);

  int gradient = 0;

  for (int column = 0; column < col; column++) {
    for (int rows = 0; rows < row; rows++) {
      doubleArray[rows][column] = gradient;
    }
    gradient++;
  }

  cout << "After gradient:" << endl;
  printMatrix (doubleArray);


  //Q2: Take a one-dimensional integer array, and mirror it (i.e. from left to right, the first half of the array is the exact same as the second half of the array, from right to left)
  int oneArray[len];
  initArray (oneArray);

  cout << endl << "Before mirror:" << endl;
  printArray (oneArray);

  int count = 1;

  for (int index = 0; index < len; index ++) {
    if (index > 4) {
      oneArray[index] = oneArray[index - count];
      count += 2;
    }
  }

  cout << endl << "After mirror:" << endl;
  printArray (oneArray);


  return 0;
}