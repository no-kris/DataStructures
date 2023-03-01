#ifndef QUEUE_H
#define QUEUE_H

struct Node
{
  Node (int value)
  : m_value (value), next (nullptr) { };

  virtual
  ~Node () { };

  Node* next;
  int m_value;
};

class Queue
{
public:
  Queue (int value);
  virtual ~Queue ();

  // methods
  void enqueue (int value);
  void dequeue ();
  void printQueue ();

  // getters
  void getFirst ();
  void getLast ();
  void getLength ();

private:
  Node* first;
  Node* last;
  int m_length;
};

#endif /* QUEUE_H */

