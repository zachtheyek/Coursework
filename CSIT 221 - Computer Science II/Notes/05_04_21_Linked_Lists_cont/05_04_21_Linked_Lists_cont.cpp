/*
Notes (05/04/21)

  An array is random access (i.e. we can access the value at any index at any point in time), whereas a linked list is sequential access (to access a value at one index, we must first access all the values before/after it)

  Stacks and queues are like linked lists, except stacks require new values (nodes) to be added from the top of the stack, and queues require them to be added from the bottom of the queue. We won't have enough time to cover stacks and queues in this class, but the overall concept builds upon the idea of linked lists.
*/

#include <iostream>
#include <string>
#include "node.h"
using namespace std;

//we define a global variable to keep track of how many nodes are in the linked list. So if the user doesn't specify the location of the new value when calling the add_node() function, we still know where the end of the linked list is
int numNodes = 0;

//following on from what we did last class, let's define a function that allows us to add a new node into our linked list at any position
Node* add_node(Node *root, int newVal, int location = numNodes) {
  //first, we check if the root is empty, and if so, we simply declare a new node as the root initialized with the specified value
  if (root == nullptr) {
    cout << "List is empty, initialized with " << to_string(newVal) << "." << endl;
    root = new Node(newVal);
  }

  //if root is not empty, then we proceed as follows
  else if (location >= 0) {
    //save the root in a separate pointer: current, in case we lose the root
    Node *current = root;
    //declare a new node that has the user specified value
    Node *newNode = new Node(newVal);

    //since location 0 refers to the beginning of the list, regardless of how long the list is, we simply add the new node to the beginning of the list (before root), and shift the list accordingly
    if (location == 0) {
      cout << to_string(newVal) << " added to beginning of list, values shifted accordingly." << endl;
      newNode->setNextNodePtr(current);
      root = newNode;
    }

    //if location is between 0 and the list range, we move to the specified location, and add the new node there, shifting the list accordingly. Note that based on the way we defined location, location n is equivalent to index n+1 in the list
    else if (location > 0 && location <= numNodes) {
      if (location == numNodes) {
        cout << to_string(newVal) << " added to end of list." << endl;
      }
      else {
        cout << to_string(newVal) << " added to location " << to_string(location) << " of list, values shifted accordingly." << endl;
      }
    
      //increment current to user specified location
      int count = 0;
      while (count < location - 1) {
        current = current->getNextNodePtr();
        count += 1;
      }

      //split the list at the specified location, saving the rest (RHS) of the list in a separate pointer: temp
      Node *temp = current->getNextNodePtr();
      //finally, add the new node, and shift the list accordingly
      current->setNextNodePtr(newNode);
      newNode->setNextNodePtr(temp);
    }

    //otherwise, if the given location is beyond the list's range, we output an error message and add the new node to the end of the list
    else if (location > numNodes) {
      cout << "Location outside list range, " << to_string(newVal) << " added to end of list." << endl;
      while(current->getNextNodePtr() != nullptr) {   
        current = current->getNextNodePtr();
      }
      current->setNextNodePtr(newNode);
    }
  }

  //lastly, if the specified location is negative, we output an error message and leave the list unchanged
  else if (location < 0) {
    cout << "Location cannot be negative. List unchanged." << endl;
    numNodes -= 1;
  }

  //we increment the number of nodes by 1, and return root
  numNodes += 1;
  return root;
}

void print_linked_list(Node *root) {
  Node *current = root;

  cout << "Linked list: ["; 
	while (current != nullptr) {   
		cout << current->getNodeVal() << ", ";  
		current = current->getNextNodePtr();   
	}
  cout << '\b' << '\b' << "]" << endl; 
}


int main() {

  Node *root = nullptr;
  int uInput = 1, uLocation = 0;

	while(uInput != 0) {   
		cout << "Enter a number and location (separated by a space), or enter \'0 0\' to break: ";
		cin >> uInput >> uLocation;
		
    if(uInput != 0) {
      //in each iteration, we want to reconfigure root as it changes depending on the input
			root = add_node(root, uInput, uLocation);
      print_linked_list(root);
      cout << endl;
		}
	}

  cout << "Break successful." << endl;

	return 0;
}