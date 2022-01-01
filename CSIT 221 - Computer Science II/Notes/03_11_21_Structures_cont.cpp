/*
Q: Declare an array: soccer, of 3 components of sportsType. 
		Then, initialize each component of soccer as follows: 
			sportName to null string
			teamName to null string
			numberOfPlayers to 0
			teamPayroll to 0.0
			coachSalary to 0.0
		Next, use a loop to take user-input data into the array soccer
		Finally, output the names of soccer teams whose payroll is greater than or equal to 10,000,000
*/

#include <iostream>
#include <string>
using namespace std;

const int LENGTH = 3;

struct sportsType {
	string sportName;
	string teamName;
	int numberOfPlayers;
	double teamPayroll;
	double coachSalary;
};

void initSportsType(sportsType sport) {
	sport.sportName = "";
	sport.teamName = "";
	sport.numberOfPlayers = 0;
	sport.teamPayroll = 0.0;
	sport.coachSalary = 0.0;
}


int main () {

	sportsType soccer[LENGTH];
	for (int i = 0; i < LENGTH; i++) {
		initSportsType(soccer[i]);
	}

	for (int j = 0; j < LENGTH; j++) {
		cout << "What is the sport name: ";
		getline(cin, soccer[j].sportName);

		cout << "What is the team name: ";
		getline(cin, soccer[j].teamName);

		cout << "What is the number of players: ";
		cin >> soccer[j].numberOfPlayers;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');

		cout << "What is the team's payroll: ";
		cin >> soccer[j].teamPayroll;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');

		cout << "What is the coach's salary: ";
		cin >> soccer[j].coachSalary;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');

		cout << endl;
	}

	bool check = false;
	for (int k = 0; k < LENGTH; k++) {
		if (soccer[k].teamPayroll >= 10000000) {
			cout << soccer[k].teamName << " has a payroll greater than 10,000,000." << endl;
			check = true;
		}
	}
	if (check == false) {
		cout << "No teams have a payroll greater than 10,000,000." << endl;
	}


	return 0;
}
