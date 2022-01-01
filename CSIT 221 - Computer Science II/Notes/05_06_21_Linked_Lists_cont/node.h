//here we define a class structure called a node, which points to a memory location that stores an integer value and a pointer, which then points to another node. Notice that the pointer variable is a private data member of the class, yet it's of the same type as the class it's defined in. This class definition is the underlying data structure for linked lists
class Node {
protected:
	int value;
	Node* next;

public:
	//constructors
  //if no arguments are provided, we initialize the node's value to 0, and the pointer to a nullptr (i.e. it points to nothing)
	Node() : value(0), next(nullptr) {}
	//if only a value is given as an argument, we initialize the node's value to the given value, and the pointer to a nullptr
	Node(int val) : value(val), next(nullptr) {}
	//if both a value and a memory location are given as arguments, we initialize the node's value to the given value, and the pointer to the given memory location
	Node(int val, Node* p) : value(val), next(p) {}

	//class member functions
	Node* getNextNodePtr() const { return next; }
	int getNodeVal() const { return value; }
	void setNextNodePtr(Node* p) { next = p; }
	void setNodeVal(int val) { value = val; }
};