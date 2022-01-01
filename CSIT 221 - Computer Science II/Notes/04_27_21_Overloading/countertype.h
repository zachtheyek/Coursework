class counterType {
public:
  //constructors
  counterType();
  counterType(int val);

  //normally, these would be the functions we'd have to define in a class if we don't overload the operators
  void set_counter(int val);
  void init_counter();
  int get_count() const;
  void increment();
  void decrement();

  //overloading binary operators
  //function heading for overloading the '+' operator
  const counterType& operator+(const counterType&);
  //function heading for overloading the '-' operator
  const counterType& operator-(const counterType&);

  //overloading unary operators
  //function heading for overloading the '++' operator
  counterType& operator++(int);
  //function heading for overloading the '--' operator
  counterType& operator--(int);

  //overloading output stream objects (operators)
  //function heading for overloading the '<<' operator
  friend ostream& operator<<(ostream&, const counterType&);

private:
  int counter;
};

counterType::counterType() { counter = 0; }
counterType::counterType(int val): counter(val) {}

//since we're overloading the operators, these functions become redundant
void counterType::set_counter(int val) { counter = val;}
void counterType::init_counter() { counter = 0; }
int counterType::get_count() const { return counter; }
void counterType::increment() { counter++; }
void counterType::decrement() { if(counter > 0) counter--; }

//take note of the syntax for overloading binary operators
//function definition for overloading the '+' operator, where the leftObject (denoted using the reserved word "this") is the one that calls this method on the rightObject (given in the input)
const counterType& counterType::operator+(const counterType& rightObject) {
  this->counter = this->counter + rightObject.counter;

  return *this;   //note that since the leftObject is passed in as a memory address, we are returning an address as well using a pointer, hence the * symbol (in other words, "this" is a pointer)
}
//function definition for overloading the '-' operator
const counterType& counterType::operator-(const counterType& rightObject) {
  this->counter = rightObject.counter - this->counter;

  return *this;
}

//take note of the syntax for overloading unary operators
//function definition for overloading the '++' operator. Note that we could instead pass an ordinary class object (not a memory address) into the definition, but we'd have to use a workaround method by defining a temporary pointer in the definition, and returning that instead
counterType& counterType::operator++(int u) {
  this->counter++;

  return *this;
}
//function definition for overloading the '--' operator
counterType& counterType::operator--(int u) {
  this->counter--;

  return *this;
}

//take note of the syntax for overloading output stream objects (operators)
//function definition for overloading the '<<' operator. Note that this is a friend function, which is not a member of the class (hence we don't have the scope resolution "counterType::" before "operator"), but still has access to private data members of the class (kinda like a trusted function of the class)
ostream& operator<<(ostream& osObject, const counterType& cObject) {
  osObject << cObject.counter;

  return osObject;
}