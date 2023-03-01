#include "Graph.h"
#include <iostream>

Graph::Graph() { }

Graph::~Graph() { }

//===================== addVertex ============================================//

// To add a vertex to graph, that is not repeated, check if vertex
// is already in the graph, by checking the count of that vertex in the
// adjList. If the count returns 0, insert the vertex in the adjList.

bool Graph::addVertex(const char &vertex)
{
  if (adjList.count(vertex) == 0)
    {
      adjList[vertex];
      return true;
    }
  return false;
}

//===================== removeVertex =========================================//

// To remove a vertex from a graph, we have to also remove
// the edges that are related to that vertex.
// Iterate through the vertex that is to be erased, 
// and erase that vertex from the other vertex that shares an edge
// with the vertex to be removed. Erase the vertex once all
// edges have been removed

bool Graph::removeVertex(const char &vertex)
{
  if (adjList.count(vertex) == 0)
    {
      return false;
    }
  else
    {
      for (auto otherVertex : adjList.at(vertex))
        {
          adjList.at(otherVertex).erase(vertex);
        }
      adjList.erase(vertex);
      return true;
    }
}

//===================== addEdge ==============================================//

// To add edges between vertices, first check to make sure the vertices
// are in the adjList. If they are, insert the other vertex
// at the original vertex.

bool Graph::addEdge(const char &vertex1, const char &vertex2)
{
  if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
    {
      adjList.at(vertex1).insert(vertex2);
      adjList.at(vertex2).insert(vertex1);
      return true;
    }
  return false;
}

//===================== removeEdge ===========================================//

// To remove edges between vertices, first check to make sure the vertices
// exist. If they do, remove the vertex from the other vertex

bool Graph::removeEdge(const char &vertex1, const char &vertex2)
{
    if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
    {
      adjList.at(vertex1).erase(vertex2);
      adjList.at(vertex2).erase(vertex1);
      return true;
    }
  return false;
}

//===================== printGraph ===========================================//

// To print the contents of the graph, iterate through each vertex
// and through each edges, using nested for loops

void Graph::printGraph()
{
  for (auto ve : adjList)
    {
      std::cout << ve.first << ": [ ";
      for (auto e : ve.second)
        {
          std::cout << e << " ";
        }
      std::cout << "]" << '\n';
    }
}

