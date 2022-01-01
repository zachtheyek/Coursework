#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int LEN = 3;
const int ROWS = 3;
const int COLS = 3;

void init_1d_array (int *arr) {
  srand((unsigned int)time(NULL));
  for (int a = 0; a < LEN; a++) {
    arr[a] = rand() % 10;
  }
}

void print_1d_array (int *arr) {
  for (int b = 0; b < LEN; b++) {
    cout << arr[b] << '\t';
  }
  cout << endl;
}

void delete_1d_array (int *arr) {
  delete [] arr;
}

void init_2d_array (float *matrix[]) {
  for (int i = 0; i < ROWS; i++) {
    matrix[i] = new float[COLS];
  }

  for (int j = 0; j < ROWS; j++) {
    for (int k = 0; k < COLS; k++) {
      matrix[j][k] = rand() % 10;
    }
  }
}

void print_2d_array (float *matrix[]) {
  for (int m = 0; m < ROWS; m++) {
    for (int n = 0; n < COLS; n++) {
      cout << matrix[m][n] << '\t';
    }
    cout << endl;
  }
  cout << endl;
}

void delete_2d_array (float *matrix[]) {
  for (int p = 0; p < ROWS; p++) {
    delete [] matrix[p];
  }
}


int main() {

  int *arr = new int[LEN];
  init_1d_array (arr);
  print_1d_array (arr);
  delete_1d_array (arr);

  cout << endl;

  float *matrix[ROWS];
  init_2d_array (matrix);
  print_2d_array (matrix);
  delete_2d_array (matrix);
  

  return 0;
}