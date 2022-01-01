#include <iostream>
#include <string>
#include "node.h"
using namespace std;

int numNodes = 0;

void print_linked_list(Node *root) {
  Node *current = root;

  cout << "Linked list: [";
  while (current != nullptr) {
    cout << current->getNodeVal() << ", ";
    current = current->getNextNodePtr();
  }
  cout << '\b' << '\b' << "]" << endl;
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
    //declare a new node that has the user specified value
    Node *newNode = new Node(addVal);

    //since location 0 refers to the beginning of the list, regardless of how long the list is, we simply add the new node to the beginning of the list (before root), and shift the list accordingly
    if (location == 0) {
      cout << to_string(addVal) << " added to beginning of list, values shifted accordingly." << endl;
      newNode->setNextNodePtr(current);
      root = newNode;
    }

    //if location is between 0 and the list range, we move to the specified location, and add the new node there, shifting the list accordingly. Note that based on the way we defined location, location n is equivalent to index n+1 in the list
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
      cout << "Location outside list range, " << to_string(addVal) << " added to end of list." << endl;
      while (current->getNextNodePtr() != nullptr) {
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

//following on from what we did last class, let's define a function that allows us to delete a node in our linked list at any position. Note that we'll define this function such that it deletes the first node in the list with a value that matches the input (in the event that there are multiple nodes with values that match the input)
Node* delete_node(Node *root, int deleteVal) {
  //first, we check if the root is empty, and if so, we simply output an error message
  if (root == nullptr) {
    cout << "List is empty, no nodes deleted." << endl;
    numNodes += 1;
  }

  //if root is not empty, then we proceed as follows
  else {
    //save the root in a separate pointer: current, in case we lose the root
    Node *current = root;

    //then, we check if the first node is the correct node
    if (current->getNodeVal() == deleteVal) {
      //if the current node is the last node in the list, we make the current node a nullptr (same as deleting it)
      if (current->getNextNodePtr() == nullptr) {
        current = nullptr;
      }
      //otherwise, we delete the root using the delete function
      else {
        Node *temp = current;
        current = current->getNextNodePtr();
        delete(temp);
        root = current;
      }
      cout << to_string(deleteVal) << " deleted from list, values shifted accordingly." << endl;
    }

    //finally, if the node of interest is not the first node
    else {
      //declare two pointers to store the nodes before and after the node we want to delete
      Node *beforeDeleted = nullptr;
      Node *afterDeleted = nullptr;

      //we increment to the correct node
      while (current->getNodeVal() != deleteVal) {
        if (current->getNextNodePtr() != nullptr) {
          //we shift all three nodes together
          beforeDeleted = current;
          current = current->getNextNodePtr();
          afterDeleted = current->getNextNodePtr();
        } 
        else {
          cout << "No value in the list matches input, list unchanged." << endl;
          return root;
        }
      }
      //shift the list accordingly such that the current node (that we want to delete) is lost
      beforeDeleted->setNextNodePtr(afterDeleted);
      cout << to_string(deleteVal) << " deleted from list, values shifted accordingly." << endl;
    }
  }
  //we decrement the number of nodes by 1, and return root
  numNodes -= 1;
  return root;
}


int main() {

  //prompt the user for inputs to create a linked list
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


  //prompt the user for inputs to delete from the linked list
  int deleteVal = 1;

  while (deleteVal != 0) {
    cout << "Enter a number to remove from the list, or enter \'0\' to break: ";
    cin >> deleteVal;

    if (deleteVal != 0) {
      root = delete_node(root, deleteVal);
      print_linked_list(root);
      cout << endl;
    }
  }

  cout << "Break successful." << endl;
  print_linked_list(root);


  return 0;
}