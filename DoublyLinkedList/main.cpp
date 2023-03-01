#include <iostream>
#include "DoublyList.h"

/*
    Doubly Linked List

    A data structure that consists of two nodes linked to each other
    by a pointer to the next node and a pointer to the previous node
  
    Operations that can be used from the header file
 
    append(int value);
        - Add a new node to the end of the list
 
    deleteLastItem();
        - Delete the last node from the end of the list
 
    prepend(int value);
        - Add a new node to the front of the list
   
    deleteFirstItem();
        - Delete the first node from the front of the list
  
    insert(int value, int index);
        - Insert a new node at a specified index
  
    deleteNode(int index);
        - Delete a node from a specified index
  
    getAtIndex(int index);
        - Get a pointer to the value at the specified index
  
    setAtIndex(int value, int index);
        - Replace a value from a specified index in the list
  
    printList();
        - Print the values of the list

    // getters
    getHead() const;
    getTail() const;
    getLength () const;
 
 */

int main(int argc, char** argv)
{

  std::cout << "Creating a doubly linked list with some values\n";
  DoublyList* myList = new DoublyList(1);
  
  myList->append(2);
  myList->append(3);
  
  myList->printList();
  
  std::cout << "Deleting last item from list\n";
  myList->deleteLastItem();
  
  myList->printList();
  
  std::cout << "Adding new nodes to list\n";
  myList->prepend(4);
  myList->prepend(5);
  
  myList->printList();
  
  std::cout << "Deleting first item from list\n";
  myList->deleteFirstItem();
  
  myList->printList();
  
  std::cout << "Getting item from index 2\n";
  std::cout << myList->getAtIndex(2)->m_value << '\n';
  
  std::cout << "Setting value 9 at index 1\n";
  myList->setAtIndex(9, 1);
  
  myList->printList();
  
  std::cout << "Inserting new nodes at index 2 and 3\n";
  myList->insert(17, 2);
  myList->insert(23, 3);
  
  myList->printList();
  
  std::cout << "Removing node from index 2\n";
  myList->deleteNode(2);
  
  myList->printList();
  
  myList->getLength();
  
  return 0;
}

