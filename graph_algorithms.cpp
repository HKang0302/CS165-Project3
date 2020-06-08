#include "graph.h"
#include "helpers.h"
#include <list>
#include <iostream>
//using namespace std;

int get_diameter(Graph graph)
{
  //cout << "num nodes: " << graph.get_num_nodes() << endl;
  bool* visited = new bool[graph.get_num_nodes()];

  for (int i = 0; i < graph.get_num_nodes(); i++)
    visited[i] = false;

  int dMax = 0, id = 1;
  while (id != -1)
  {
    visited[id - 1] = true;
    int farNodeID = graph.BFS(id, dMax);
    id = visitedAll(graph, visited);
    if (id != -1 && !visited[farNodeID-1])
      id = farNodeID;
  }
  delete[] visited;
  return dMax;
}

float get_clustering_coefficient(Graph graph) 
{
  int nTri = countTriangles(graph);
  int denom = 0;
  std::vector<int> degrees = graph.getDegrees();
  for (int i : degrees)
  {
    denom += i * (i - 1) / 2;
  }
  return 3 * ((float)nTri / denom);
}

std::map<int, int> get_degree_distribution(Graph graph) 
{
  std::vector<int> degrees = graph.getDegrees();
  std::map<int, int> result;
  for (int i = 0; i < degrees.size(); i++)
  {
    int d = degrees[i];
    if (result.find(d) != result.end())
      result.find(d)->second++;
    else
      result.insert(std::make_pair(d, 1));
  }
	return result; // remove this line if you implement the function
}
