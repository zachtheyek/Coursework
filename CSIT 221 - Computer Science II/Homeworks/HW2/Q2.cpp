//Chp 9, Q2
#include <iostream>
#include <string>
using namespace std;

const int NUM_STUDENTS = 3;

struct studentType {
  string studentFName;
  string studentLName;
  int testScore;
  char grade;
};

void initStudentType (studentType studentList[]) {
  for (int i = 0; i < NUM_STUDENTS; i++) {
    cout << "First name of student " << to_string(i + 1) << ": ";
    getline (cin, studentList[i].studentFName);

    cout << "Last name of student " << to_string(i + 1) << ": ";
    getline (cin, studentList[i].studentLName);

    bool TF = false;
    while (TF == false) {
      int test_score;

      cout << "Student " << to_string(i + 1) << "\'s test score: ";
      cin >> test_score;
      cin.ignore (numeric_limits <streamsize>::max(), '\n');

      if ((test_score >= 0) && (test_score <= 100)) {
        studentList[i].testScore = test_score;
        TF = true;
      }
      else {
        cout << "Test score must be between 0 and 100." << endl;
      }
    }
    cout << endl;    
  }
}

//Assume 90-100 is an A, 80-89 is a B, 70-79 is a C, 60-69 is a D, and 0-59 is an E
void assignStudentGrade (studentType studentList[]) {
  for (int j = 0; j < NUM_STUDENTS; j++) {
    if ((studentList[j].testScore >= 90) && (studentList[j].testScore <= 100)) {
      studentList[j].grade = 'A';
    }
    else if ((studentList[j].testScore >= 80) && (studentList[j].testScore < 90)) {
      studentList[j].grade = 'B';
    }
    else if ((studentList[j].testScore >= 70) && (studentList[j].testScore < 80)) {
      studentList[j].grade = 'C';
    }
    else if ((studentList[j].testScore >= 60) && (studentList[j].testScore < 70)) {
      studentList[j].grade = 'D';
    }
    else if ((studentList[j].testScore >= 0) && (studentList[j].testScore < 60)) {
      studentList[j].grade = 'E';
    }
  }
}

void printStudentType (studentType studentList[]) {
  for (int k = 0; k < NUM_STUDENTS; k++) {
    cout << studentList[k].studentLName << ", " << studentList[k].studentFName << ": " << studentList[k].testScore << "\% (" << studentList[k].grade << ")" << endl;
  }
  cout << endl;
}

int findHighest (studentType studentList[], int highest_index[]) {
  int c = 0;
  int highest_score = studentList[0].testScore;

  for (int a = 1; a < NUM_STUDENTS; a++) {
    if (highest_score < studentList[a].testScore) {
      highest_score = studentList[a].testScore;
    }
  } 

  for (int b = 0; b < NUM_STUDENTS; b++) {
    if (studentList[b].testScore == highest_score) {
      highest_index[c++] = b;
    }
  }

  return c;
}

void printHighest (studentType studentList[]) {
  int highest_index[NUM_STUDENTS];
  int c = findHighest (studentList, highest_index);

  for (int d = 0; d < c; d++) {
    cout << studentList[highest_index[d]].studentLName << ", " << studentList[highest_index[d]].studentFName << " has the highest test score." << endl;
  }
}


int main () {

  studentType students[NUM_STUDENTS];
  initStudentType (students);
  assignStudentGrade (students);
  printStudentType (students);
  printHighest (students);

  return 0;
}
