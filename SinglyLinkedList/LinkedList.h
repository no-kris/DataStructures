#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node
{
  int m_value;
  Node* next;

  Node (int value)
  : m_value (value), next (nullptr) { };

  virtual
  ~Node () { };

};

class LinkedList
{
public:
  // Constructor and destructor
  LinkedList ();
  LinkedList (int value);
  virtual ~LinkedList ();

  // Methods
  void append (int value);
  void deleteLastItem ();
  void prepend (int value);
  void deleteFirstItem ();
  bool insert (int index, int value);
  void deleteNode (int index);
  void reverseList ();
  void printList ();

  // Setter
  bool setAtIndex (int index, int value);

  // Getter
  Node* getAtIndex (int index);
  void getHead () const;
  void getTail () const;
  void getLength () const;


private:
  // Hold values for a node pointer to head and tail
  // and length for linked list
  Node* head;
  Node* tail;
  int m_length;
};

#endif /* LINKEDLIST_H */

