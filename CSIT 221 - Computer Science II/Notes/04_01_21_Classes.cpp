/*
Notes (04/01/21)

	Classes are similar to structures, in that they are user-defined data types, but they have more functionality (hence they're used in object-oriented programming)
		
    The syntax for defining a class is also similar to structures: just replace "struct" with "class"

	By default, classes are private (whereas structures are public), so to create public data members (e.g. functions) within a class, we have to explicitly state "public:"

    private: member can't be accessed outside the class; 
    public: member is accessible outside the class; 
    protected: similar to private, but less "strict" since it can be inherited (accessed)

		  Objects of the same class can "see" only the public data members, not the private ones
		  Public (and private) data members of a given class can "see" its own private data members
			
	With classes, we can't initialize variables in the class definition, rather we can only initialize them when creating an object of that class

	No memory is allocated during class definition; memory is only allocated when declaring an object of that class

	Most built-in operations don't apply to classes, so they can't be used on class objects unless they're overloaded

		The only operators that work by default are the assignment "=" and member access "." operators (similar to structures)
*/

#include <iostream>
using namespace std;

class Rectangle {
	//these are data members of the class (both are private; note that although unnecessary, we could explicitly state that they're private/protected)
	double width;
	double height;
public:   //everything below will be public data members (i.e. they're visible to objects of this class); typically includes methods (operations) and accessed with reference to the object of this class (not always the case, sometimes methods can be private)

  //First, we should define some constructors, which typically shares the same name with the class it belongs to. Constructors allow us to initialize the object the way we want to. If no constructor is specified in our class declaration, C++ defines a default constructor for us that runs instead but doesn't initialize anything
	Rectangle () {   //assume a declaration with no arguments (aka non-argument constructor or default constructor), i.e. Rectangle a; This constructor is called whenever a new object of its class is created
		width = 1;
		height = 2;
		cout << "Default constructor: object created." << endl;   //message notifying us that object is initialized by default constructor
	}

	Rectangle (int w, int h) {   //assume a declaration with two arguments (aka two-argument constructor), i.e. Rectangle a (4, 8); (note that we can have any n-argument constuctor that's called when user provides n inputs during declaration)
		width = w;
		height = h;
		cout << "Two-argument constructor: object created." << endl;   //message notifying us that object is initialized by two-argument constructor
	}

	//although we could just define functions within this class declaration itself, we'll instead try declaring only headings within this class, and proceed to define the functions themselves outside the class
	void set_values (int w, int h);   //note that while this takes two inputs just like the two-argument constructor, this function has to be explicitly called by the user using the member access operator, whereas the constructor is automatically called at object declaration and cannot be accessed again after
	double get_width () const;   //returns only the width; note that this is a constant function (as indicated by "const"). Constant functions defined within a class can access the private data members, but they can't change their values
	double get_height () const;   //returns only the height; again, since this is a constant function, it can't change the values of the class' private data members
	double area ();   //doesn't need to take inputs since the function will have access to private data members height and width
	void print_object () const;   //again, doesn't need any inputs, and is a constant function as well, meaning height and width can't change

	~Rectangle () {   //this is a destructor (opposite of a constructor)
		cout << "Object deleted." << endl;
	}
};

void Rectangle::set_values (int w, int h) {   //"::" is the scope resolution, so the compiler knows this function is defined in the class Rectangle, even though we're defining it outside the class (can also be used to reference classes in different C++ files)
	width = w;
	height = h;
}

double Rectangle::get_width () const {
	return width;
}

double Rectangle::get_height () const {
	return height;
}

double Rectangle::area () {
	return width * height;
}

void Rectangle::print_object () const {
	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;
}


int main () {

	Rectangle smallRectangle (3, 4);
	smallRectangle.print_object ();
	cout << "Area: " << smallRectangle.area () << endl << endl;

	Rectangle defaultRectangle;
	defaultRectangle.print_object ();
	cout << "Area: " << defaultRectangle.area () << endl << endl;

	Rectangle otherRectangle (10, 7);
	cout << "Width: " << otherRectangle.get_width () << endl;
	cout << "Height: " << otherRectangle.get_height () << endl;
	cout << "Area: " << otherRectangle.area () << endl << endl;


	return 0;
}