#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {

	char studentID[9];   //student ID is 8 characters long

	int numStudents;
	cout << "Enter number of students: ";
	cin >> numStudents;

	int numQuestions;
	cout << "Enter number of questions: ";
	cin >> numQuestions;
	cout << endl;

	char *ansKey;
	ansKey = new char[numQuestions + 1];

	char *studentAns;
	studentAns = new char[numQuestions + 1];

	ifstream inFile;
	inFile.open ("2-ex2-data.txt");

	if (inFile.is_open ()) {

		cout << "Reading answer key..." << endl;
		inFile.get(ansKey, numQuestions + 1);
		cout << "Answer key: " << ansKey << endl << endl;

    cout << "Calculating grades..." << endl;
		for (int i = 0; i < numStudents; i++) {
			float studentScore = 0;

			inFile >> studentID;
			cout << studentID << '\t';

			inFile.get (studentAns, numQuestions + 2);
      cout << studentAns << '\t';

			for (int j = 0; j < numQuestions; j++) {
				if (studentAns[j + 1] == ansKey[j]) {
					studentScore += 2.0;
				}
				else if (studentAns[j + 1] == ' ') {
          studentScore += 0.0;
				}
        else {
          studentScore -= 1.0;
        }
			}

      studentScore = studentScore / (2 * numQuestions) * 100;
      cout << studentScore << '%' << '\t';

      if (studentScore >= 90.0) {
        cout << 'A' << endl;
      }
      else if ((studentScore >= 80.0) && (studentScore < 90.0)) {
        cout << 'B' << endl;
      }
      else if ((studentScore >= 70.0) && (studentScore < 80.0)) {
        cout << 'C' << endl;
      }
      else if ((studentScore >= 60.0) && (studentScore < 70.0)) {
        cout << 'D' << endl;
      }
      else if ((studentScore >= 0.0) && (studentScore < 60.0)) {
        cout << 'F' << endl;
      }
		}
		inFile.close();
	}
	else {
		cout << "Unable to open file." << endl;
	}


	return 0;
}