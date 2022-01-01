#include <iostream>
using namespace std;

//recall that we can overload functions, e.g. the add function, where the specific function that's called depends on the data type(s) of the object(s) that are passed through the function
int add(int a, int b) {
	return a + b;
}
double add(double a, double b) {
	return a + b;
}

//we can instead use templates to streamline this process (a.k.a. a templated function). Note that it's convention to call the class ItemType, though we could also call it T, F, etc. Note also that not every single input has to be a template, but as long as there is one templated input, the function will also be templated
template <class ItemType>
ItemType add(ItemType a, ItemType b) {
	return a + b;
}

//we can also write a templated class. Note that in C++, a template header must be present for every structure definition. This means that we don't have to include a template header before each function definition within a class, however if we define the class functions outside the class definition, then we need to rewrite the template header each time
template <class V>
class number {
	V num1;
	V num2;

public:
	number() {
		num1 = 0;
		num2 = 0;
		cout << "Default constructor called." << endl;
	}

	number(V x, V y) {
		num1 = x;
		num2 = y;
		cout << "Constructor called." << endl;
	}

	void set_values(V x, V y);
	V find_max() const;
	V find_min() const;

	~number() {
		cout << "Default destructor called." << endl;
	}
};

template <class V>
void number<V>::set_values(V x, V y) {
	num1 = x;
	num2 = y;
}

//note that a short form for this function definition can be written like so: return (num1 >= num2) ? num1 : num2;, which states that if num1 >= num2, return num1, else return num2, which is exactly what we have below
template <class V>
V number<V>::find_max() const {
	if(num1 >= num2) {
		return num1;
	}
	else {
		return num2;
	}
}

//similar to the previous function , a short form for this function definition can be written like so: return (num1 >= num2) ? num2 : num1;, which states that if num1 >= num2, return num2, else return num1, which is again exactly what we have below
template <class V>
V number<V>::find_min() const {
	if (num1 <= num2) {
		return num1;
	}
	else {
		return num2;
	}
}


int main() {

	//we don't have to do this, but it's useful to specify explicitly what ItemType is when calling a templated function
	cout << "2 + 3 = " << add<int>(2, 3) << endl;
	cout << "3.4 + 5.8 = " << add<double>(3.4, 5.8) << endl << endl;

	//we have to specify the data type of our class template at declaration
	number<int> myNum1(1, 2);
	cout << "Max: " << myNum1.find_max() << endl << endl;

	number<double> myNum2(1.1, 1.2);
	cout << "Min: " << myNum2.find_min() << endl << endl;


	return 0;
}