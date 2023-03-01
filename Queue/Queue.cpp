#include "Queue.h"
#include <iostream>

//=================== constructor ============================================//

Queue::Queue(int value) 
{
  Node* newNode = new Node(value);
  first = newNode;
  last = newNode;
  m_length = 1;
}

//=================== destructor =============================================//

// To destroy a Queue, set a temp node to first,
// and move firs to first's pointer, then delete temp and move temp to first
// repeat until first is equal to nullptr

Queue::~Queue()
{ 
  Node* temp = first;
  while (first != nullptr)
    {
      first = first->next;
      delete temp;
      temp = first;
    }
}

//=================== enqueue ================================================//

// To add items to the end of a queue, create a new node,
// and if queue is empty set first and last to new node,
// else set last's pointer to new node and set last to new node
// increment the length of the queue

void Queue::enqueue(int value)
{
  Node* newNode = new Node(value);
  if (m_length == 0)
    {
      first = newNode;
      last = newNode;
    }
  else
    {
      last->next = newNode;
      last = newNode;
    }
  m_length++;
}

//=================== dequeue ================================================//

// To remove an item from the start of a queue, that is not empty,
// set a temp node to first, and if the length of the queue is 1, 
// set first and last to nullptr, else set first to first's pointer
// delete temp and decrement queue's length

void Queue::dequeue()
{
  if (m_length == 0)
    {
      return;
    }
  Node* temp = first;
  if (m_length == 1)
    {
      first = nullptr;
      last = nullptr;
    }
  else
    {
      first = first->next;
    }
  delete temp;
  m_length--;
}

//=================== printQueue =============================================//

// TO print a queue that is not empty,
// set a temp node to first and loop through Queue and print
// temp's value, until temp is equl to nullptr

void Queue::printQueue()
{
  if (m_length == 0)
    {
      std::cout << "Queue is empty\n";
    }
  Node* temp = first;
  while (temp != nullptr)
    {
      std::cout << temp->m_value << '\n';
      temp = temp->next;
    }
}

//=================== getters ================================================//

void Queue::getFirst()
{
  std::cout << "First: " << first->m_value << '\n';
}

void Queue::getLast()
{
  std::cout << "Last: " << last->m_value << '\n';
}

void Queue::getLength()
{
  std::cout << "Length: " << m_length << '\n';
}

