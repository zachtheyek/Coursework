//Chp 8, Q19
#include <iostream>
#include <string>
using namespace std;

//Define the number of rows and seats as global constants
const int ROWS = 13;
const int SEATS = 6;

//Also define the rows that correspond to which ticket types as global constant arrays, as well as the lengths of each array as global constants themselves
const int FIRST[] = {1, 2};
const int BUSINESS[] = {3, 4, 5, 6, 7};
const int ECONOMY[] = {8, 9, 10, 11, 12, 13};

const int LEN_FIRST = sizeof(FIRST)/sizeof(FIRST[0]);
const int LEN_BUSINESS = sizeof(BUSINESS)/sizeof(BUSINESS[0]);
const int LEN_ECONOMY = sizeof(ECONOMY)/sizeof(ECONOMY[0]);

//Define a function to initialize a ROWS x SEATS matrix with all empty seats '*'
void initMenu (char menu[][SEATS]) {
  for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < SEATS; j++) {
      menu[i][j] = '*';
		}
	}
}

//Define a function to print the seating arrangement, i.e. the matrix, with row and seat numbers clearly labeled
void printMenu (char menu[][SEATS]) {
  int letter = 65;
  int rowNum = 1;
  
  cout << endl;

  for (int a = 0; a < ROWS + 1; a++) {
		for (int b = 0; b < SEATS + 1; b++) {
      if ((a == 0) && (b == 0)) {
        cout << "\t\t";
      } else if (a == 0) {
        cout << char(letter++) << '\t';
      } else if (b == 0) {
        string row = "Row " + to_string(rowNum++);
        cout << row << '\t';
      } else {
        cout << menu[a - 1][b - 1] << '\t';
      }
		}
		cout << endl;
	}
  cout << endl;
}

//Define a function to take the desired type and seat as inputs
void takeInput (char menu[][SEATS], string &type_input, string &seat_input) {
  printMenu (menu);

  cout << endl << "Input your desired ticket type (first class, business class, or economy class), or enter \"exit\" to quit the menu: ";
  getline (cin, type_input);

  cout << endl << "Desired seat (ex: 1A, 7F, 4B, etc.), or press \"enter\" if you entered \"exit\" to the previous prompt: ";
  getline (cin, seat_input);
}

//Define a function to check if the user-inputs are valid (if so, it reserves the seat; if not, it prints an error message)
bool checkInput (char menu[][SEATS], string &type_input, string &seat_input) {

  //First, we check if the user wishes to exit the menu
  if (type_input == "exit") {
    return false;
  } else if ((type_input == "first class") || (type_input == "business class") || (type_input == "economy class")) {
      
      //If not, we check if the users desired seat input is valid
      int row, seat;
      bool seat_valid, type_valid = false;

      if ((seat_input.back() >= 65) && (seat_input.back() <= (65 + SEATS - 1))) {
        seat = seat_input.back() - 64;
      } else {
          seat_valid = true;
      }

      if (seat_input.size() == 2) {
        row = stoi(seat_input.substr(0, 1));
      } else if (seat_input.size() == 3) {
        row = stoi(seat_input.substr(0, 2));
      } else {
        seat_valid = true;
      }

      if ((row < 1) || (row > ROWS)) {
        seat_valid = true;
      }

      if (seat_valid == true) {
        cout << endl << "Invalid seat input. Make sure your desired seat is in the format NumberLetter (ex: 1A, 7F, 4B, etc.), and is one of the seats listed in the menu." << endl;
        return true;
      }

      //Then, we check if the users ticket type input is valid
      if (type_input == "first class") {
        for (int x = 0; x < LEN_FIRST; x++) {
          if (row == FIRST[x]) {
            type_valid = true;
          }
        }
      } else if (type_input == "business class") {
          for (int y = 0; y < LEN_BUSINESS; y++) {
            if (row == BUSINESS[y]) {
              type_valid = true;
            }
          }
      } else if (type_input == "economy class") {
          for (int z = 0; z < LEN_ECONOMY; z++) {
            if (row == ECONOMY[z]) {
              type_valid = true;
            }
          }
      }

      //Finally, we check if the user's seat is taken
      if (type_valid == true) {
        if (menu[row - 1][seat - 1] == '*') {
          menu[row - 1][seat - 1] = 'X';
          cout << endl << "Your seat: " << seat_input << ", has been reserved." << endl;
          printMenu (menu);

          //We prompt the user to see if they want to reserve another seat, or if they wish to exit the menu
          string repeat = " ";

          while (true) {
            cout << endl << "Would you like to reserve another seat? If so, enter \"yes\", or enter \"exit\" to quit the menu: ";
            getline (cin, repeat);

            if ((repeat == "yes") || (repeat == "exit")) {
              break;
            } else {
                cout << endl << "Invalid entry, please enter \"yes\" if you'd like to reserve another seat, or enter \"exit\" to quit the menu." << endl;
            }
          }

          if (repeat == "yes") {
            return true;
          } else if (repeat == "exit") {
            return false;
          }

        } else if (menu[row - 1][seat - 1] == 'X') {
            cout << endl << "This seat is taken. Please choose another seat." << endl;
            return true;
        }

      } else if (type_valid == false){
        cout << endl << "Your desired seat does not match your desired ticket type. Remember that rows 1 and 2 are first class, rows 3 to 7 are business class, and rows 8 to 13 are economy class." << endl;
        return true;
      }
  } else {
      cout << endl << "Invalid ticket type, make sure your input is in all lowercase and is spaced appropriately." << endl;
      return true;
  }
}


int main() {
  //Declare and initialize the matrix for the initial empty seating arrangement
  char menu[ROWS][SEATS];
  initMenu (menu);  

  //Declare two variables to store the user-inputs (ticket type and desired seat)
  string type_input;
  string seat_input;

  //Take the ticket type and desired seat as user-inputs, execute the appropriate commands, and loop until the user explicitly tells the program to stop
  bool loop = true;

  while (loop == true) {
    takeInput (menu, type_input, seat_input);
    loop = checkInput (menu, type_input, seat_input);
  }

  //Once the user chooses to exit the menu, we print a final thank you message before exiting the program
  cout << endl << "Thank you for flying with us, we hope you have a wonderful trip!" << endl;
  
  return 0;
}