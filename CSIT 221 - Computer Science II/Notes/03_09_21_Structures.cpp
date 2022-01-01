#include <iostream>
#include <string>
using namespace std;

const int SEMESTER = 8;

//define a structure that stores the grades for the past 8 semesters of a given student in an array
struct grades {
  double grade[SEMESTER];
};

//define another structure that stores information about a given student, including a data member using our previously defined grades structure
struct studentInfo {
  string name;
  string studentId;
  int yearOfEnrollment;
  string major;
  float cgpa;
  int yearOfGraduation;
  grades semGrades;
};

//define a function that prints the info stored in each data member for our previously defined studentInfo structure
void printStudentInfo (studentInfo student) {
  cout << "Name: " << student.name << endl;
  cout << "Student ID: " << student.studentId << endl;
  cout << "Year of enrollment: " << student.yearOfEnrollment << endl;
  cout << "Major: " << student.major << endl;
  cout << "CGPA: " << student.cgpa << endl;
  cout << "Year of graduation: " << student.yearOfGraduation << endl;
  for (int p = 0; p < SEMESTER; p++) {
    cout << "Semester " << to_string (p + 1) << " grades: " << student.semGrades.grade[p] << endl;
  }
}

int main() {
  //create an array of students, where each element is of structure studentInfo, and the length of the array (i.e. the number of students) is given by the user
  int numStudents;

  cout << "How many students would you like to enter: ";
  cin >> numStudents;
  cin.ignore (numeric_limits <streamsize>::max (), '\n');   //note that we have to include this line after every cin as we use a mix of cin and getline() in this program
  cout << endl;
  studentInfo studentList[numStudents];

  //Then, for each student in the array, we take their info as user-inputs
  for (int i = 0; i < numStudents; i++) {
    cout << "Name of student " + to_string(i + 1) + ": ";
    getline (cin, studentList[i].name);

    cout << "Student ID number of student " + to_string(i + 1) + ": ";
    getline (cin, studentList[i].studentId);

    cout << "Year of enrollment of student " + to_string(i + 1) + ": ";
    cin >> studentList[i].yearOfEnrollment;
    cin.ignore (numeric_limits <streamsize>::max (), '\n');

    cout << "Major of student " + to_string(i + 1) + ": ";
    getline (cin, studentList[i].major);

    cout << "CGPA of student " + to_string(i + 1) + ": ";
    cin >> studentList[i].cgpa;
    cin.ignore (numeric_limits <streamsize>::max (), '\n');

    cout << "Year of graduation of student " + to_string(i + 1) + ": ";
    cin >> studentList[i].yearOfGraduation;
    cin.ignore (numeric_limits <streamsize>::max (), '\n');

    for (int j = 0; j < SEMESTER; j++) {
      cout << "Semester " << to_string (j + 1) << " grades: ";
      cin >> studentList[i].semGrades.grade[j];
      cin.ignore (numeric_limits <streamsize>::max (), '\n');
    }
    cout << endl;
  }
  
  //print the info of each student in the array
  for (int k = 0; k < numStudents; k++) {
    printStudentInfo(studentList[k]);
    cout << endl;
  }


  //notice that the assignment operator still works for user-defined structures
  studentInfo newStudent; 
  newStudent = studentList[0];
  printStudentInfo (newStudent);


  return 0;
}
