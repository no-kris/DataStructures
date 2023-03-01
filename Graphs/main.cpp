#include <iostream>
#include "Graph.h"

/* 
    Graph
 
    A graph is a data structure that consists of vertices, or nodes,
    linked together by edges, this file implements a graph as
    an unordered map of char, with vertex as key and edge as value
  
    
    addVertex(const char &vertex);
        - Add a vertex to the graph
  
    removeVertex(const char &vertex);
        - Remove a vertex from the graph
  
    addEdge(const char &vertex1, const char &vertex2);
        - Add a link between two vertices
 
    removeEdge(const char &vertex1, const char &vertex2);
        - Remove a link between two vertices
  
    printGraph();
        - Prints the key value, and edge values
 */

int main(int argc, char** argv)
{
  Graph* myGraph = new Graph;
  
  myGraph->addVertex('A');
  myGraph->addVertex('B');
  myGraph->addVertex('C');
  myGraph->addVertex('D');
  
  // addEdge results should be
  // A = [B C]
  // B = [A D]
  // C = [A D]
  // D = [B C]
  myGraph->addEdge('A','B');
  myGraph->addEdge('A','C');
  myGraph->addEdge('C','D');
  myGraph->addEdge('B','D');
  
  // removeEdge results should be
  // A = [B]
  // B = [A]
  // C = [D]
  // D = [C]
  myGraph->removeEdge('A', 'C');
  myGraph->removeEdge('B', 'D');
  
  myGraph->removeVertex('D');
  
  myGraph->printGraph();
  
  
  return 0;
}

