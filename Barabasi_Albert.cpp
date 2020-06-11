#include "Barabasi_Albert.h"
#include <iostream>

using namespace std;

BAgraph::BAgraph(int num_nodes, int d)
{
  this->num_vertices = num_nodes;
  std::vector<int> M(2 * num_nodes * d, -1);
  for (int v = 0; v < num_nodes; v++)
  {
    for (int i = 0; i < d; i++)
    {
      M[2 * (v * d + i)] = v;
      int r = ((double)rand() / (RAND_MAX)) * 2 * (v * d + i);
      M[2 * (v * d + i) + 1] = M[r];
    }
  }
  for (int i = 0; i < num_nodes * d; i++)
  {
    startV.push_back(M[2 * i]); endV.push_back(M[2 * i + 1]);
  }
}
