#include <iostream>
#include "Stack.h"


int main(int argc, char** argv)
{
  
  Stack* myStack = new Stack(1);
  
  myStack->printStack();
  
  std::cout << "Pushing items into stack\n";
  myStack->push(2);
  myStack->push(3);
  myStack->push(4);
  myStack->printStack();
  
  std::cout << "Popping items from stack\n";
  myStack->pop();
  myStack->printStack();

  return 0;
}

