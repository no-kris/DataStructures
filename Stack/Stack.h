#ifndef STACK_H
#define STACK_H

struct Node
{
  Node (int value)
  : m_value (value), next (nullptr) { };

  virtual
  ~Node () { };

  int m_value;
  Node* next;
};

class Stack
{
public:
  // constructor and destructor
  Stack (int value);
  virtual ~Stack ();

  // methods
  void push (int value);
  void pop ();
  void printStack ();

  // getters  
  void getTop ();
  void getHeight ();

private:
  Node* top;
  int m_height;
};

#endif /* STACK_H */

