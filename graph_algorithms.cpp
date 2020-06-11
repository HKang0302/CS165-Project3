#include "graph.h"
#include "helpers.h"
#include "Erdos-Renyi.h"
#include <list>
#include <iostream>
#include <cstring>
#include<string>
using namespace std;

int get_diameter(Graph graph)
{
  //cout << "get diameter" << endl;
  int dMax = 0, id = rand() % graph.get_num_nodes() + 1;
  int tempDist = 0;

  id = graph.BFS(id, tempDist);

  while (dMax < tempDist)
  {
    dMax = tempDist;
    tempDist = 0;
    id = graph.BFS(id, tempDist);
  }

  //cout << "done " << endl;
  return dMax;
}

float get_clustering_coefficient(Graph graph) 
{
  //cout << "cc" << endl;
  int nTri = graph.countTriangles();
  int denom = graph.getDenom();
  return 3 * ((float)nTri / denom);
  //cout << "done" << endl;
}

std::map<int, int> get_degree_distribution(Graph graph) 
{
  std::map<int, int> pre_progress = graph.vertex_to_degree_map();
  std::map<int, int> post;
  for (std::map<int, int>::iterator itr = pre_progress.begin(); itr != pre_progress.end(); itr++)
    post[itr->second]++;
  return post;
}
