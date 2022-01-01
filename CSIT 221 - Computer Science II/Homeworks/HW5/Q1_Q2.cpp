//Chp 16, Q1 & Q2
#include <iostream>
#include <string>
#include "node.h"
using namespace std;

int numNodes = 0;

void print_linked_list(Node *root) {
  if (root == nullptr) {
    cout << "Linked list: []" << endl;
  }
  else {
    Node *current = root;

    cout << "Linked list: [";
    while (current != nullptr) {
      cout << current->getNodeVal() << ", ";
      current = current->getNextNodePtr();
    }
    cout << '\b' << '\b' << "]" << endl;
  }
}

Node* add_node(Node *root, int addVal, int location = numNodes) {
  //first, we check if the root is empty, and if so, we simply declare a new node as the root initialized with the specified value
  if (root == nullptr) {
    cout << "List is empty, initialized with " << to_string(addVal) << "." << endl;
    root = new Node(addVal);
  }

  //if root is not empty, then we proceed as follows
  else if (location >= 0) {
    //save the root in a separate pointer: current, in case we lose the root
    Node *current = root;
    //declare a new node to store the previous node
    Node *previous = nullptr;
    //declare a new node that has the user specified value
    Node *newNode = new Node(addVal);

    //since location 0 refers to the beginning of the list, regardless of how long the list is, we simply add the new node to the beginning of the list (before root), and shift the list accordingly
    if (location == 0) {
      cout << to_string(addVal) << " added to beginning of list, values shifted accordingly." << endl;
      newNode->setNextNodePtr(current);
      root = newNode;
    }

    //if location is between 0 and the list range, we move to the specified location, and add the new node there, shifting the list accordingly. Note that based on the way we defined location, location n is equivalent to index n in the list
    else if (location > 0 && location <= numNodes) {
      if (location == numNodes) {
        cout << to_string(addVal) << " added to end of list." << endl;
      }
      else {
        cout << to_string(addVal) << " added to location " << to_string(location) << " of list, values shifted accordingly." << endl;
      }

      //increment current to user specified location 
      int count = 0;
      while (count < location - 1) {
        previous = current;
        current = current->getNextNodePtr();
        count += 1;
      }

      //split the list at the specified location, saving the rest (RHS) of the list in a separate pointer: temp
      Node *temp = current->getNextNodePtr();
      //finally, add the new node, and shift the list accordingly
      current->setPrevNodePtr(previous);
      current->setNextNodePtr(newNode);
      newNode->setNextNodePtr(temp);
    }

    //otherwise, if the given location is beyond the list's range, we output an error message and add the new node to the end of the list
    else if (location > numNodes) {
      cout << "Location outside list range, " << to_string(addVal) << " added to end of list." << endl;
      while (current->getNextNodePtr() != nullptr) {
        previous = current;
        current = current->getNextNodePtr();
      }
      current->setPrevNodePtr(previous);
      current->setNextNodePtr(newNode);
    }
  }

  //lastly, if the specified location is negative, we output an error message and leave the list unchanged
  else if (location < 0) {
    cout << "Location cannot be negative. List unchanged." << endl;
    return root;
  }

  //we increment the number of nodes by 1, and return root
  numNodes += 1;
  return root;
}


int main() {

  Node *root = nullptr;
  int addVal = 1, uLocation = 0;

  while (addVal != 0) {
    cout << "Enter a number and location (separated by a space), or enter \'0 0\' to break: ";
    cin >> addVal >> uLocation;

    if (addVal != 0) {
      //in each iteration, we want to reconfigure root as it changes depending on the input
      root = add_node(root, addVal, uLocation);
      print_linked_list(root);
      cout << endl;
    }
  }

  cout << "Break successful." << endl;
  print_linked_list(root);
  cout << endl;


  return 0;
}