#include "helpers.h"

#include <iostream>
using namespace std;

void printD(std::list<int>* D, int maxDegree)
{
  cout << "max: " << maxDegree << endl;
  for (int j = 0; j <= maxDegree; j++)
  {
    cout << j + 1 << ": ";
    std::list<int> dd = D[j];
    for (auto ddd : dd)
    {
      cout << ddd << " ";
    }
    cout << endl;
  }
}

void printN(std::vector<Node> adj)
{
  for (Node n : adj)
    cout << n.id << " ";
  cout << endl;
}

//template <typename T >
void printVector(std::vector<int> v)
{
  for (int x: v)
    cout << x << " ";
  cout << endl;
}

template <typename T >
void printList(std::list<T> l)
{
  for (T x : l)
    cout << x << " ";
  cout << endl;
}

int visitedAll(Graph graph, bool* visited)
{
  for (int i = 0; i < graph.get_num_nodes(); i++)
  {
    if (visited[i] == false)
      return i + 1;
  }
  return -1;
}

bool isInList(int v, std::list<int> l)
{
  for (int x : l)
    if (x == v)
      return true;
  return false;
}

int countTriangles(Graph graph)
{
  std::list<int>* idN = new std::list<int>[graph.get_num_nodes()];
  std::list<int> degeneracy = graph.getDegeneracy(idN);
  std::list<int> checked;
  int result = 0;

  for (int i = 0; i < degeneracy.size(); i++)
  {
    int v = *std::next(degeneracy.begin(), i);
    std::list<int> adj = idN[v - 1];
    if (adj.size() > 1)
    {
      for (int j = 0; j < adj.size() - 1; j++)
        for (int k = 1; k < adj.size(); k++)
        {
          int u = *std::next(adj.begin(), j), w = *std::next(adj.begin(), k);
          if (graph.isNeighbor(graph.getNode(u), graph.getNode(w)))
            result++;
        }
    }
  }
  delete[] idN;
  return result;
}
