#include <iostream>
#include <string>
#include <fstream>  //for reading or writing, from or into files
using namespace std;


int main () {

	//writing to files
	ofstream outFile;  //create an output file (path is created in the same place as source code, unless specified otherwise)
	outFile.open ("test.txt");  //name the file "test.txt" and open it (in our program we'll refer to it as outFile)
	outFile << "This is line one.\n";  //print to the file
	outFile << "This is line two.";
	outFile.close ();  //note that if we don't close the file, the system maintains a lock on the file, meaning we (or another person) can't open the file


	//reading from files
	string line;

	ifstream inFile;  //create (find) an input file (path is assumed to be current directory of source code, unless specified otherwise)
	inFile.open ("test.txt");
	getline(inFile, line);  //store inFile (that is, one line from "test.txt") in string (recall from before we stored user-input (cin) into a variable); this only reads one line from file, to read every line, we put it in a while loop, and loop until not empty
	cout << line << endl << endl;
	inFile.close();


	//Q: read the file named "fileio-db.dat", and print the whole file
	string lines;

	ifstream infile;
	infile.open("fileio-db.dat");

	//check if the file is open, i.e. if the file exists 
	if (infile.is_open()) {
		while (getline (infile, lines)) {  //since the getline function reads one line (until it encounters an implicit "\n"), we can loop until the getline function doesn't return anything, i.e. when we've read through the whole file
			cout << lines << endl; 
		}
		cout << endl;
		infile.close();
	} else {
		cout << "Unable to open file." << endl;
	}


	//Q: read the file named "fileio-db.dat", and print (in tabular format, separated based on ',') the data in csv file
	string field;

	ifstream csvfile;
	csvfile.open ("fileio-db.dat");

	if (csvfile.is_open ()) {
		while (getline (csvfile, field, ',')) {  //the third parameter in the getline function is the delimiter: ',' which is optional
			cout << field << "\t";  //note, getline stores the data (separated by delimiter ',') into field, and we print field out followed by a tab; getline loops to the next line after each iteration, since each line is ended by an implicit "\n"; this keeps happening as long as getline is running.
		}
		cout << endl;
		csvfile.close();
	} else {
		cout << "Unable to open file." << endl;
	}

	return 0;
}

/*
Notes: 

File I/O
	Simplest way to store data is in a textfile (non-secured; plain text)
		textfiles could be separated by commas (csv), by a single or multiple bytes, or any other delimiter
	We could also store data in a database (secured; structured)
	or in an object database (secured; easy to implement; may not be structured)

Recurssion (we'll talk more about recurssion next class)
	Recurssion is a function that calls itself, or in other words, a function that's defined in terms of itself
	Recall that stacks are LIFO (last in first out), whereas queues are FIFO (first in first out)
	If we make a stack of function calls, the last function that's called, i.e. put into the stack, is the first one to be executed, and so on 
		This is different from when we write iterative solutions, e.g. with loops, which are queues
	Recurssion also affects the variables that are declared/defined through each recurssion
		All of this means we have to think differently when writing recursive solutions vs iterative solutions
*/