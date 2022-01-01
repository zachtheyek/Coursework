#include <iostream>
using namespace std;

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

class cubeType: private rectangleType {
private:
  double height;

public:
  cubeType(): rectangleType() {
    height = 1;
    cout << "Derived class default constructor called." << endl;
  }

  cubeType(double w, double l, double h): rectangleType() {
    if((w == l) && (l == h)) {
      width = w;
      length = l;
      height = h;
      cout << "Derived class constructor called." << endl;
    }
    else {
      width = 1;
      length = 1;
      height = 1;
      cout << "Arguments are not equal, cube lengths initialized to 1." << endl;
    }
  }

  void setDimensions(double w, double l, double h) {
    if((w == l) && (l == h)) {
      width = w;
      length = l;
      height = h;
    }
    else {
      width = 1;
      length = 1;
      height = 1;
      cout << "Arguments are not equal, cube lengths set to 1." << endl;
    }
  }

  double getLength() {return length;}
	double getWidth() {return width;}
  double getHeight() {return height;}
	double area() const {return 2 * (width * length) + 2 * (length * height) + 2 * (width * height);}
  double volume() const {return width * length * height;}
	void print() const {cout << "Width: " << width << " Length: " << length << " Height: " << height << endl;}

  ~cubeType() {cout << "Derived base destructor called." << endl;}
};


int main() {
        
  cubeType c(2,2,1);
  c.print();
  cout << "Area: " << c.area() << endl;
  cout << "Volume: " << c.volume() << endl;

  
  return 0;
}