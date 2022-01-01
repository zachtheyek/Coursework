#include <iostream>
#include "node.h"
using namespace std;

//here we define a function for printing linked lists, which passes by reference the first node of a linked list as an argument
void print_linked_list(Node *root) {

  //we could hard-code the function, like so: cout << rt->getNodeVal() << " " << rt->getNextNodePtr()->getNodeVal();
	//however, this is only practical when dealing with a few nodes. Usually we'll be dealing with a large number of nodes in a linked list, so we want to use a while loop to execute the function

  //note that it's convention to "save" the current node in a separate variable (pointer), in case we mess up the root, a.k.a. the first node of our linked list, which would mean we lose the entire linked list
	Node *current = root;   

  //now, we loop over the entire linked list, printing the value at each node until we reach a node that points to nullptr (i.e. an empty node)
	while (current != nullptr) {   
    //print the value at the current node
		cout << current->getNodeVal() << " ";  
    //then, move to the next node 
		current = current->getNextNodePtr();   
	}
}


int main() {

  //let's start by declaring a couple nodes for our linked list

	//notice that the following is a dynamic memory allocation (because of the use of new), where we reserve a memory location for a node that our pointer *root then points to
	Node *root = new Node(10, nullptr);
  //then, we do the same for the next node in the chain, initializing it to a different value
	root->setNextNodePtr(new Node(20));

	//now, we'll add a third node manually
	root->getNextNodePtr()->setNextNodePtr(new Node(30));
  //like the print_linked_list() function, doing this manually is only practical when we have a small number of nodes. Ideally, we'd like to automate this process by repeatedly taking an input from the user, and adding it to the end of the linked list

  //first, initialize uInput to a nonzero integer. Also save the current root (node) to a separate pointer variable as a backup
	int uInput = 1;   
	Node *current = root;

  //then, we prompt the user for an input, and keep looping until the user wants to stop (by entering 0)
	while(uInput != 0) {   
		cout << "Enter a number, or enter 0 to print: ";
		cin >> uInput;
		
    //we only continue if the user enters a nonzero integer
    if(uInput == 0) {
      cout << endl;
    }
		else if(uInput != 0) {

			//to add uInput to the end of the linked list, we first want to get to the node at the end of the linked list, using a loop
			while (current->getNextNodePtr() != nullptr) {
				current = current->getNextNodePtr();
			}

			//next, we set the last node to point to a new node, and initialize its value to uInput
			current->setNextNodePtr(new Node(uInput));
		}
	}

	//lastly, we simply print the linked list
	print_linked_list(root);

  //note: we can convert a linear linked list into a circular linked list, simply by having the last node's pointer point back to the first node's memory location.


	return 0;
}