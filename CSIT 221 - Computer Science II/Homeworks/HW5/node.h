class Node {
protected:
	int value;
  Node *prev;
	Node *next;

public:
	//constructors
	Node(): value(0), prev(nullptr), next(nullptr) {}
	Node(int val): value(val), prev(nullptr), next(nullptr) {}
	Node(int val, Node *p1, Node *p2): value(val), prev(p1), next(p2) {}

	//class member functions
  Node* getPrevNodePtr() const { return prev; }
	Node* getNextNodePtr() const { return next; }
	int getNodeVal() const { return value; }
  void setPrevNodePtr(Node* p) { prev = p; }
	void setNextNodePtr(Node* p) { next = p; }
	void setNodeVal(int val) { value = val; }
};