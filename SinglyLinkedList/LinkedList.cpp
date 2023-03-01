#include <iostream>
#include "LinkedList.h"

//============================ constructor ===================================//

// Empty linked list constructor

LinkedList::LinkedList()
: head(nullptr), tail(nullptr), m_length(0) { }

// Construct an instance of a LinkedList with a value passed
// and set the head and tail to a new node that takes a value
// set the length of the linked list equal to 1

LinkedList::LinkedList(int value)
{
  Node* newNode = new Node(value);
  head = newNode;
  tail = newNode;
  m_length = 1;
}

//============================================================================//

//========================== destructor ======================================//

// Destruct an instance of a LinkedList
// create a temp node and set the temp node to the head of linked list
// iterate through list by moving head to next and having the temp node
// follow the head node, delete the temp node each time.
// repeat until head and temp are at nullptr

LinkedList::~LinkedList()
{
  Node* temp = head;
  while (head != nullptr)
    {
      head = head->next;
      delete temp;
      temp = head;
    }
}

//============================================================================//

//============================ append ========================================//

// Insert a new node at the end of the linked list
// If the list is empty, set head and tail to the new node
// else set tails pointer to the new node and set tail to new node
// increment the length of the list

void LinkedList::append(int value)
{
  Node* newNode = new Node(value);
  if (m_length == 0)
    {
      head = newNode;
      tail = newNode;
    }
  else
    {
      tail->next = newNode;
      tail = newNode;
    }
  m_length++;
}

//============================================================================//

//================== deleteLastItem ==========================================//

// Delete the last item from the linked list
// If there are no nodes, then do nothing.
// If there is one node, store the head in a temp node, 
// set head and tail to nullptr and delete the temp node, decrement the length.
// If there are more than one nodes, store head in a temp and pre node
// while temps pointer is not pointing to nullptr, iterate through list
// by setting temp to next and the pre node follows the temp node.
// at the end, set the tail to the pre node, and set tails pointer to nullptr
// delete the temp node and decrement length

void LinkedList::deleteLastItem()
{
  if (m_length == 0)
    {
      return;
    }
  Node* temp = head;
  if (m_length == 1)
    {
      head = nullptr;
      tail = nullptr;
    }
  else
    {
      Node* pre = head;
      while (temp->next != nullptr)
        {
          pre = temp;
          temp = temp->next;
        }
      tail = pre;
      tail->next = nullptr;
    }
  m_length--;
  delete temp;
}

//============================================================================//

//======================== prepend ==========================================//

// Insert a new node at the beginning of the linked list
// Allocate a new node and if the list is empty, set head and tail to new node
// else set new node's pointer to head and set head to the new node
// Increment the length

void LinkedList::prepend(int value)
{
  Node* newNode = new Node(value);
  if (m_length == 0)
    {
      head = newNode;
      tail = newNode;
    }
  else
    {
      newNode->next = head;
      head = newNode;
    }
  m_length++;
}

//============================================================================//

//========================= deleteFirstItem ==================================//

// Delete the first item in the list
// If the list is empty, then do nothing
// If list has 1 item, set a temp node to head and set head and tail to nullptr
// If list has more than 1 items, set the head to where head is pointing to
// delete the temp node and decrement the length

void LinkedList::deleteFirstItem()
{
  if (m_length == 0)
    {
      return;
    }
  Node* temp = head;
  if (m_length == 1)
    {
      head = nullptr;
      tail = nullptr;
    }
  else
    {
      head = head->next;
    }
  delete temp;
  m_length--;
}

//============================================================================//

//============================ insert ========================================//

// Insert a new node somewhere in the linked list
// return either true or false if node was inserted or not
// First check if index is out of bounds, if it is, do nothing
// If the index is 0, then use prepend(value) function to insert new 
// node in the front of list
// If index is equal to the length of the list, use append(value) to 
// add a new node to the end of the list
// If index is somewhere else, use a temp node to reach the position 
// behind the index, set the new nodes pointer to temps pointer, then
// set temps pointer to the new node.
// Increment length and return true

bool LinkedList::insert(int index, int value)
{
  if (index < 0 || index > m_length)
    {
      return false;
    }
  if (index == 0)
    {
      prepend(value);
      return true;
    }
  if (index == m_length)
    {
      append(value);
      return true;
    }
  Node* newNode = new Node(value);
  Node* temp = getAtIndex(index - 1);
  newNode->next = temp->next;
  temp->next = newNode;
  m_length++;
  return true;

}

//============================================================================//

//============================ deleteNode ====================================//

// Delete a node at a specific index of the list
// check if index is out of bounds, if its is, do nothing
// If index is 0, run deleteFirstItem();
// If index is length - 1, the last node, then run deleteLastItem();
// If index is somewhere else, set a pre node to index - 1
// and a temp node to pre's pointer, or the actual index,
// then set pre's pointer to temps pointer and delete temp, decrement length

void LinkedList::deleteNode(int index)
{
  if (index < 0 || index > m_length)
    {
      return;
    }
  if (index == 0)
    {
      return deleteFirstItem();
    }
  if (index == m_length - 1)
    {
      return deleteLastItem();
    }
  Node* pre = getAtIndex(index - 1);
  Node* temp = pre->next;
  pre->next = temp->next;
  delete temp;
  m_length--;
}

//============================================================================//

//============================ reverseList ===================================//

// To reverse a linked list, swap the head and tail
// use a temp to hold the head, and set head to tail and tail to temp
// set an after node to temp next and a before node to nullptr
// iterate through the list and each time
// set after to temp next, temp next to before
// move before to temp and move temp to after

void LinkedList::reverseList()
{
  Node* temp = head;
  head = tail;
  tail = temp;
  Node* after = temp->next;
  Node* before = nullptr;
  for (int i = 0; i < m_length; ++i)
    {
      after = temp->next;
      temp->next = before;
      before = temp;
      temp = after;
    }
}

//============================================================================//

//============================ printList =====================================//

// Print the values of the linked list
// Create a temp node and set that equal to the head of the linked list
// Iterate through linked list by setting temp to next node and print the value
// repeat until temp is not at the nullptr

void LinkedList::printList()
{
  Node* temp = head;
  while (temp != nullptr)
    {
      std::cout << temp->m_value << '\n';
      temp = temp->next;
    }
}

//============================================================================//

//============================ setAtIndex ====================================//

// Set a new value at a specified index
// Use a temp node to access a specific index from the list
// If temp's index is not out of bounds, store temps value as the new value
// return true if function was successful or false if it failed

bool LinkedList::setAtIndex(int index, int value)
{
  // getAtIndex(index) is a function in this class
  Node* temp = getAtIndex(index);
  if (temp != nullptr)
    {
      temp->m_value = value;
      return true;
    }
  return false;
}

//============================================================================//

//========================= getAtIndex =======================================//

// Get value at index from list
// Don't let the function go beyond the list boundary,
// that is before head and after tail
// Store head in a temp node and use the index to iterate
// through the list by setting temp to next,
// return temp when it has reached the index

Node* LinkedList::getAtIndex(int index)
{
  if (index < 0 || index >= m_length)
    {
      return nullptr;
    }
  Node* temp = head;
  for (int i = 0; i < index; ++i)
    {
      temp = temp->next;
    }
  return temp;
}

//============================================================================//

//=========================== getters ========================================//

void LinkedList::getHead() const
{
  std::cout << "Head: " << head->m_value << '\n';
}

void LinkedList::getTail() const
{
  std::cout << "Tail: " << tail->m_value << '\n';
}

void LinkedList::getLength() const
{
  std::cout << "Length: " << m_length << '\n';
}