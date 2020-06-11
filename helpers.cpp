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
