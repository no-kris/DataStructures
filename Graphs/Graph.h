#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_map>
#include <unordered_set>


class Graph
{
public:
  Graph ();
  virtual ~Graph ();
  
  bool addVertex(const char &vertex);
  bool removeVertex(const char &vertex);
  bool addEdge(const char &vertex1, const char &vertex2);
  bool removeEdge(const char &vertex1, const char &vertex2);
  void printGraph();
  
private:
  std::unordered_map< char, std::unordered_set<char> > adjList;
};

#endif /* GRAPH_H */

