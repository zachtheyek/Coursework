/*
Notes (04/20/21)

Inheritance is a "is-a" relationship
  e.g. every employee is a person, but not every person is an employee

Inheritance allows the creation of new classes from existing classes
  Base class: the original class 
  Derived	classes: new classes created from a base class
  
A derived class inherits the properties of its base classes, where we have to specify the type of inheritance:
  see attached image ("Inheritance_Table.png") for summary of different inheritance types

  note that it's convention to always avoid public inheritance
*/

#include <iostream>
using namespace std;

//this is our base class
class rectangleType {
protected:
	double width;
	double length;

public:
	rectangleType() {
		width = 1;
		length = 1;
		cout << "Base default constructor called." << endl;
	}

	rectangleType(double w, double l) {
		width = w;
		length = l;
		cout << "Base constructor called." << endl;
	}

	void setDimensions(double w, double l) {
		width = w;
		length = l;
	}

	double getLength() {return length;}
	double getWidth() {return width;}
	double area() const {return width * length;}
	void print() const {cout << "Width: " << width << " Length: " << length << endl;}

	~rectangleType() {cout << "Base destructor called." << endl;}
};

//this is our derived class (from the base class: rectangleType)
class boxType: private rectangleType {
private:   //note that length and width are private data members in this derived class
  double height;

public:
  boxType(): rectangleType() {   //when we call the (default) constructor of the derived class, we must first call the default constructor in the base class, so we don't need to initialize width and length
    height = 1;
    cout << "Derived class default constructor called." << endl;
  }

  boxType(double w, double l, double h): rectangleType() {   //even though we're declaring a 3-argument constructor in the derived class, we must still call the default constructor in the base class first
    width = w;
    length = l;
    height = h;
    cout << "Derived class constructor called." << endl;
  }

  //since setDimensions is an already-defined function in the base class, we're essentially redefining the function (this is called an overridden function). Depending on whether the declared object is of rectangleType or boxType, the appropriate setDimensions function will be called
  void setDimensions(double w, double l, double h) {
    width = w;
    length = l;
    height = h;
  }

  //here we override all the functions from the base class, as well as adding some extra ones for the derived class specifically (note that even though getLength and getWidth are defined in exactly the same way, in both the base and derived classes, because we're inheriting privately, our derived class can't access the functions defined in the base class since they're private: see "Inheritance_Table.png")
  double getLength() {return length;}
	double getWidth() {return width;}
  double getHeight() {return height;}
	double area() const {return 2 * (length * width) + 2 * (width * height) + 2 * (length * height);}
  double volume() const {return width * length * height;}
	void print() const {cout << "Width: " << width << " Length: " << length << " Height: " << height << endl;}

  ~boxType() {cout << "Derived base destructor called." << endl;}
};


int main() {
  
  rectangleType r(2, 2);
	r.print();
	cout << "Area: " << r.area() << endl << endl;

  boxType b;
  cout << "Width: " << b.getWidth() << endl;
  cout << "Length: " << b.getLength() << endl;
  cout << "Height: " << b.getHeight() << endl;
  cout << "Area: " << b.area() << endl;
  cout << "Volume: " << b.volume() << endl << endl;

	
	return 0;
}