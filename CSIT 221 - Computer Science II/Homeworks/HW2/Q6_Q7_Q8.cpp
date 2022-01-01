//Chp 9, Q(6, 7, 8)
#include <iostream>
#include <string>
using namespace std;

struct fruitType {
  string fruitName;
  string color;
  int fat;
  int sugar;
  int carb;
};

void getFruitInput (fruitType &fruit) {
  cout << "Name of fruit: ";
  getline (cin, fruit.fruitName);

  cout << "Color of fruit: ";
  getline (cin, fruit.color);

  cout << "Amount of fat (in grams) in fruit: ";
  cin >> fruit.fat;
  cin.ignore (numeric_limits <streamsize>::max(), '\n');

  cout << "Amount of sugar (in grams) in fruit: ";
  cin >> fruit.sugar;
  cin.ignore (numeric_limits <streamsize>::max(), '\n');

  cout << "Amount of carbs (in grams) in fruit: ";
  cin >> fruit.carb;
  cin.ignore (numeric_limits <streamsize>::max(), '\n');

  cout << endl;
}

void printFruitInfo (fruitType fruit) {
  cout << "The name of the fruit is " << fruit.fruitName << endl;
  cout << "It is " << fruit.color << " in color" << endl;
  cout << "It has " << fruit.fat << " grams of fat" << endl;
  cout << "It has " << fruit.sugar << " grams of sugar" << endl;
  cout << "It has " << fruit.carb << " grams of carbs" << endl;
}


int main () {

  fruitType fruit;
  getFruitInput (fruit);
  printFruitInfo (fruit);

  return 0;
}