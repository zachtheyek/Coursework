#include <iostream>
using namespace std;

//Q1 
//arrays have to be initialized with constant values, so either we pass through a literal constant, e.g. 5, or we declare the variable to be a constant using the "const" data type
const int rows1 = 5;
const int cols1 = 5;

//we first define two functions to initialize the arrays, i.e. fill the double-array with random characters, and fill the single-array with something (e.g. a space, ' ')
void initDoubleArray(char twoArr[][cols1]) {
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < cols1; j++) {
			twoArr[i][j] = char(rand() % 26 + 97);  //assign random value
		}
	}
}
void initSingleArray(char oneArr[]) {
	for (int k = 0; k < rows1 * cols1; k++) {
		oneArr[k] = ' ';
	}
}

//now we define two functions to print the arrays
void printMatrix(char twoArr[][cols1]) {
	for (int a = 0; a < rows1; a++) {
		for (int b = 0; b < cols1; b++) {
			cout << twoArr[a][b] << " ";
		}
		cout << endl;  //note: endl = "\n"
	}
	cout << endl;
}
void printArray(char oneArr[]) {
	for (int c = 0; c < rows1 * cols1; c++) {
		cout << oneArr[c] << " ";
	}
	cout << endl;
}

//and finally, we define a function that converts a double-array to a single-array, tail-to-head
void doubleToSingle(char twoArr[][cols1], char oneArr[]) {
	int index = 0;
	for (int p = 0; p < rows1; p++) {
		for (int q = 0; q < cols1; q++) {
			oneArr[index++] = twoArr[p][q];
		}
	}
}


//Q2
const int rows2 = 3;
const int cols2 = 3;

int findLargest(int doubleArray[][cols2]) {
	int largest = doubleArray[0][0];  //we shouldn't initialize largest to 0, in case all the values in the double-array are negative (<0)
	for (int i = 0; i < rows2; i++) {
		for (int j = 0; j < cols2; j++) {
			if (largest < doubleArray[i][j]) {  //in C++, it's "if", "else", and "elseif" (instead of "elif" in Python)
				largest = doubleArray[i][j];
			}
		}
	}
	return largest;
}


int main() {
	//Q1: (cont. from last class) write a program that takes a double-array, and converts it into a single-array

	char doubleArray[rows1][cols1];
	char singleArray[rows1 * cols1];

	initDoubleArray(doubleArray);
	initSingleArray(singleArray);

	printMatrix(doubleArray);

	doubleToSingle(doubleArray, singleArray);
	printArray(singleArray);


	cout << endl;


	//Q2: write a program that prints the largest value in a double-array

	int myArray[rows2][cols2] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	cout << "The largest value in the double array is: " << findLargest(myArray);

	return 0;
}
