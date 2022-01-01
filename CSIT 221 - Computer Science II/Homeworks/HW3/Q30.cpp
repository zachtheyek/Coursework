//Chp 12, Q30
#include <iostream>
using namespace std;

const int ROWS = 50;
const int COLS = 10;

void init_dMatrix (int *arr[]) {
  for (int i = 0; i < ROWS; i++) {
    arr[i] = new int[COLS];
  }

  for (int j = 0; j < ROWS; j++) {
    for (int k = 0; k < COLS; k++) {
      arr[j][k] = 0;
    }
  }
}

void print_dMatrix (int *arr[]) {
  for (int m = 0; m < ROWS; m++) {
    for (int n = 0; n < COLS; n++) {
      cout << arr[m][n] << '\t';
    }
    cout << endl;
  }
}

void delete_dMatrix (int *arr[]) {
  for (int a = 0; a < COLS; a++) {
    delete arr[a];
  }
}


int main() {
  int *votes[ROWS];

  init_dMatrix (votes);
  print_dMatrix (votes);
  delete_dMatrix (votes);


  return 0;
}