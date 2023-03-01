#include <iostream>
#include "LinkedList.h"

/*
 Linked List
 
    A linked list is a data structure that consists of nodes of data
    and pointers to the next node 
  
    Operations that can be used from the header file
 
    append(int value);
        - Add a new node to the end of a list
  
    deleteLastItem();
        - Delete the last node from the end of the list
  
    prepend(int value);
        - Add a new node to the front of the list
 
    deleteFirstItem();
        - Delete the node at the front of the list
  
    insert(int index, int value);
        - Insert a new node at a specified index
  
    deleteNode(int index);
        - Delete a node from a specified inde
  
    reverseList();
        - Reverse the linked list
  
    setAtIndex(int index, int value); 
        - Replace a node from a specified index
   
    getAtIndex(int index);
        - Get a pointer to the value at a specified index
  
    printList(); 
        - Print the linked list
  
    // Getters
    getHead() const;
    getTail() const;
    getLength() const;
  
 */

int main(int argc, char** argv)
{

  LinkedList* myList = new LinkedList(1);

  myList->append(2);
  myList->append(3);
  myList->append(4);
  myList->append(5);

  myList->prepend(0);

  myList->deleteFirstItem();

  myList->printList();

  myList->getHead();
  myList->getTail();
  myList->getLength();
  
  
  std::cout << "Index 3: " << myList->getAtIndex(3)->m_value << '\n';
  myList->setAtIndex(3, 7);
  std::cout << "New Index 3: " << myList->getAtIndex(3)->m_value << '\n';

  myList->insert(2, 10);

  std::cout << "New Index 2: " << myList->getAtIndex(2)->m_value << '\n';
  myList->deleteNode(2);
  std::cout << "New Index 2: " << myList->getAtIndex(2)->m_value << '\n';
  
  myList->reverseList();
  std::cout << "Reversed list\n";
  myList->printList();
  
  std::cout << "New Index 4: " << myList->getAtIndex(4)->m_value << '\n';


  return 0;
}

