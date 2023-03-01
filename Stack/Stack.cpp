#include <iostream>
#include "Stack.h"


//================= constructor ==============================================//

// Create an instance of a stack and set the top to the newly created node
// set height to 1

Stack::Stack(int value)
{
  Node* newNode = new Node(value);
  top = newNode;
  m_height = 1;
}

//================= destructor ===============================================//

Stack::~Stack()
{
  Node* temp = top;
  while (top != nullptr)
    {
      top = top->next;
      delete temp;
      temp = top;
    }
}

//================= push =====================================================//

// To push an item into a stack, create a new node with a value passed,
// and set new node's pointer to top, and set top to new node,
// then increment the height

void Stack::push(int value)
{
  Node* newNode = new Node(value);
  newNode->next = top;
  top = newNode;
  m_height++;
}

//================= pop ======================================================//

// To pop values from a stack, that is not empty,
// set a temp node to top and move top to top's pointer.
// Delete temp and decrement height

void Stack::pop()
{
  if (m_height == 0)
    {
      return;
    }
  Node* temp = top;
  top = top->next;
  delete temp;
  m_height--;
}

//================= printStack ===============================================//

// To print the stack, use a temp node to point to top,
// display temp's current value and move temp to temp's next pointer
// repeat until temp is not equal to nullptr

void Stack::printStack()
{
  Node* temp = top;
  while (temp != nullptr)
    {
      std::cout << temp->m_value << '\n';
      temp = temp->next;
    }
}

//================= getters ==================================================//

void Stack::getTop()
{
  if (top == nullptr)
    {
      std::cout << "Top: nullptr\n";
    }
  else
    {
      std::cout << "Top: " << top->m_value << '\n';
    }
}

void Stack::getHeight()
{
  std::cout << "Height: " << m_height << '\n';
}



