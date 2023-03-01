#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

struct Node
{
  int m_value;
  Node* next;
  Node* prev;

  Node (int value)
  : m_value (value), next (nullptr), prev (nullptr) { };
  virtual ~Node () {};
};

class DoublyList
{
public:
  // Constructor and destructor
  DoublyList ();
  DoublyList (int value);
  virtual ~DoublyList ();

  // Methods
  void append (int value);
  void deleteLastItem ();
  void prepend (int value);
  void deleteFirstItem ();
  bool insert (int value, int index);
  void deleteNode (int index);
  Node* getAtIndex (int index);
  bool setAtIndex (int value, int index);
  void printList ();

  // getter
  void getHead () const;
  void getTail () const;
  void getLength () const;

private:
  Node* head;
  Node* tail;
  int m_length;
};

#endif /* DOUBLYLIST_H */

