#include <iostream>

#include "HashTable.h"

/*
    HashTable
 
    A hash table is a sorted map that maps a key to a value
 
    Operations that can be used from the header file 
  
    setKeyValue(const std::string &key, int value);
        - Create a key-value pair, of a string and integer
  
    getValue(const std::string &key);
        - Get the value from a specified key
  
    printTable();
        - Print the hash table
 
 */

int main(int argc, char** argv)
{

  HashTable* myHash = new HashTable;
  
  myHash->setKeyValue("nails", 150);
  myHash->setKeyValue("screws", 85);
  myHash->setKeyValue("bolts", 130);
  
  
  myHash->printTable();
  
  std::cout << "Nails: " << myHash->getValue("nails") << '\n';
  std::cout << "Saws: " << myHash->getValue("saws") << '\n';
  
  return 0;
}

