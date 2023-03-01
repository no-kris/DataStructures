#include <iostream>
#include "DoublyList.h"

//=========================== constructor ====================================//

// Empty list constructor

DoublyList::DoublyList()
: head(nullptr), tail(nullptr), m_length(0) { }

// When intitializing an instance of a doubly linked list with a value passed, 
// assign head and tail to a new node with value passed in, increase length

DoublyList::DoublyList(int value)
{
  Node* newNode = new Node(value);
  head = newNode;
  tail = newNode;
  m_length = 1;
}


//=========================== destructor =====================================//

// When destroying an instance of a doubly linked list
// Use a temp node and set it to head, iterate through list moving head
// up and having temp follow, while deleting the temp node

DoublyList::~DoublyList()
{
  Node* temp = head;
  while (head != nullptr)
    {
      head = head->next;
      delete temp;
      temp = head;
    }
}


//=========================== append =========================================//

// To add a new node to the end of a doubly linked list
// create a new node, if the list is empty, set head and tail to the new node
// else set tail pointer to the new node and set new nodes prev pointer 
// to tail, set tail to the new node and increment length

void DoublyList::append(int value)
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
      newNode->prev = tail;
      tail = newNode;
    }
  m_length++;
}

//=========================== deleteLastItem =================================//

// To delete the last item from a doubly linked list
// store a temp node to tail, and if the list is empty, then do nothing,
// If the list has 1 item, set head and tail to nullptr, else if
// there are more than 1 items set tail to tails prev pointer and set
// tails next pointer to nullptr, then delete the temp node and decrement length

void DoublyList::deleteLastItem()
{
  if (m_length == 0)
    {
      return;
    }
  Node* temp = tail;
  if (m_length == 1)
    {
      head = nullptr;
      tail = nullptr;
    }
  else
    {
      tail = tail->prev;
      tail->next = nullptr;
    }
  delete temp;
  m_length--;
}

//=========================== prepend ========================================//

// To add a new node to the start of a doubly linked list
// create a new node, and if the list is empty, set head and tail to
// new node, else set heads prev pointer to new node and set new nodes
// next pointer to head, move head to new node and increment length

void DoublyList::prepend(int value)
{
  Node* newNode = new Node(value);
  if (m_length == 0)
    {
      head = newNode;
      tail = newNode;
    }
  else
    {
      head->prev = newNode;
      newNode->next = head;
      head = newNode;
    }
  m_length++;
}

//=========================== deleteFirstItem ================================//

// To delete the first item from a doubly linked list, that is not empty
// set a temp node to head, if the list has only 1 item, set head and tail
// to nullptr, else set head to heads pointer and set heads prev pointer 
// to nullptr, delete temp and decrement length

void DoublyList::deleteFirstItem()
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
      head->prev = nullptr;
    }
  delete temp;
  m_length--;
}

//=========================== insert =========================================//

// To insert a new node in a doubly linked list, first make sure index is 
// not out of bounds
// If index is 0, use the prepend function
// If index is equal to the length, use the append function
// else, create a new node, set a before node to index - 1, 
// and a after node to before's pointer.
// Set new nodes next pointer to after and prev pointer to before
// Set after's prev pointer to new node and before's next pointer to new node
// increment length and return true

bool DoublyList::insert(int value, int index)
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
  Node* before = getAtIndex(index - 1);
  Node* after = before->next;
  newNode->next = after;
  newNode->prev = before;
  before->next = newNode;
  after->prev = newNode;
  m_length++;
  return true;
}

//=========================== deleteNode =====================================//

void DoublyList::deleteNode(int index)
{
  if (index < 0 || index >= m_length)
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
  Node* temp = getAtIndex(index);
  Node* after = temp->next;
  Node* before = temp->prev;
  delete temp;
  after->prev = before;
  before->next = after;
  m_length--;
}

//=========================== getAtIndex =====================================//

// To return the value at a specified index, that is in range,
// set a temp node to head, if the index is in the first half of the list
// iterate through list until index is reached and move temp to temps pointer
// else, set temp to tail and iterate backwards in the list moving temp
// to temps prev pointer, return a node pointer to temp

Node* DoublyList::getAtIndex(int index)
{
  if (index < 0 || index >= m_length)
    {
      return nullptr;
    }
  Node* temp = head;
  if (index < m_length / 2)
    {
      for (int i = 0; i < index; ++i)
        {
          temp = temp->next;
        }
    }
  else
    {
      temp = tail;
      for (int i = m_length - 1; i > index; --i)
        {
          temp = temp->prev;
        }
    }
  return temp;
}

//=========================== setAtIndex =====================================//

// To set a new value at a specified index of a doubly linked list
// use a temp node to get the index, using the getAtIndex(index) function
// and if temp is not out of bounds, or equal to nullptr, replace
// temps value with the new value 
// and return true if successful or false if failed

bool DoublyList::setAtIndex(int value, int index)
{
  Node* temp = getAtIndex(index);
  if (temp != nullptr)
    {
      temp->m_value = value;
      return true;
    }
  return false;
}

//=========================== printList ======================================//

// To print the list, use a temp node and iterate through the list,
// until temp reaches nullptr, print temp nodes value each time.

void DoublyList::printList()
{
  Node* temp = head;
  while (temp != nullptr)
    {
      std::cout << temp->m_value << '\n';
      temp = temp->next;
    }
}


//=========================== getters ========================================//

void DoublyList::getHead() const
{
  std::cout << "Head: " << head->m_value << '\n';
}

void DoublyList::getTail() const
{
  std::cout << "Tail: " << tail->m_value << '\n';
}

void DoublyList::getLength() const
{
  std::cout << "Length: " << m_length << '\n';
}

