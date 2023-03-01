#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>

struct Node
{
  std::string m_key;
  int m_value;
  Node* m_next;
  
  Node(const std::string &key, int value)
  : m_key(key), m_value(value), m_next(nullptr) {}
};

class HashTable
{
public:
  HashTable ();
  virtual ~HashTable ();
  
  int hash(const std::string &key);
  void setKeyValue(const std::string &key, int value);
  int getValue(const std::string &key);
  void printTable();
  
private:
  static const int S_SIZE = 7;
  Node* dataMap[S_SIZE];
};

#endif /* HASHTABLE_H */

