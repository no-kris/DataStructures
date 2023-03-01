#include <iostream>
#include "HashTable.h"

HashTable::HashTable() { }

//======================= destructor =========================================//

// To delete nodes from a has table, iterate through the table and set a head
// node to the index of the dataMap array.
// Set a temp node to head, and move head to where head's next pointer
// is pointing, delete temp and set temp to head, repeat until head is
// at nullptr

HashTable::~HashTable()
{
  for (int i = 0; i < S_SIZE; ++i)
    {
      Node* head = dataMap[i];
      Node* temp = head;
      while (head != nullptr)
        {
          head = head->m_next;
          delete temp;
          temp = head;
        }
    }
}

//======================= hash ===============================================//

int HashTable::hash(const std::string &key)
{
  int hash = 0;
  for (int i = 0; i < key.length(); ++i)
    {
      int asciiValue = static_cast<int> (key[i]);
      hash = (hash + asciiValue * 23) % S_SIZE;
    }
  return hash;
}


//======================= setKeyValue ========================================//

// To insert a key-value pair in a hash table, first get the index
// the pair is being inserted to.
// Create a new node with key and value passed in.
// If the index of the dataMap array is empty, insert the new node 
// in that index, else set a temp node to that index and iterate
// the list until temp finds an empty spot, when temp finds an empty
// spot insert the new node by having temp's pointer point to it

void HashTable::setKeyValue(const std::string &key, int value)
{
  int index = hash(key);
  Node* newNode = new Node(key, value);
  if (dataMap[index] == nullptr)
    {
      dataMap[index] = newNode;
    }
  else
    {
      Node* temp = dataMap[index];
      while (temp->m_next != nullptr)
        {
          temp = temp->m_next;
        }
      temp->m_next = newNode;
    }
}

//======================= getValue ===========================================//

// To get the value from a key-value pair, get the index the key is stored in
// and set a temp node to that index
// compare temp's key to the specified key, and if they are the same
// return the value using temp, else if there are more nodes in that index
// move temp to temp's pointer until the key is found.
// If temp ever is equal to nullptr, return 0

int HashTable::getValue(const std::string &key)
{
  int index = hash(key);
  Node* temp = dataMap[index];
  while (temp != nullptr)
    {
      if (temp->m_key == key)
        {
          return temp->m_value;
        }
      else 
        {
          temp = temp->m_next;
        }
    }
  return 0;
}

//======================= printTable =========================================//

// To print a hash table, iterate through the table, and if the index 
// at the dataMap array is not equal to nullptr set a temp node to that index
// display the key and value using temp, and if there are more key and
// value nodes move temp to temp's pointer

void HashTable::printTable()
{
  for (int i = 0; i < S_SIZE; ++i)
    {
      std::cout << i << ": \n";
      if (dataMap[i] != nullptr)
        {
          Node* temp = dataMap[i];
          while (temp != nullptr)
            {
              std::cout << "\t{" << temp->m_key << ", " << temp->m_value << "}\n";
              temp = temp->m_next;
            }
        }
    }
}

