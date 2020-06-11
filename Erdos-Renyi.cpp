#include "Erdos-Renyi.h"
#include <iostream>

using namespace std;

ERgraph::ERgraph(int num_nodes)
{
  this->num_vertices = num_nodes;
  this->p = 2*log1p(num_nodes)/num_nodes;
  int v = 1, w = -1;
  while (v < num_nodes)
  {
    double r = ((double)rand() / (RAND_MAX));
    if (r == 1)
      r /= 2;
    w += 1 + int(log2(1 - r) / log2(1 - this->p));
    while (w >= v && v < num_nodes)
    {
      w -= v; v++;;
    }

    if (v < num_nodes)
    {
      startV.push_back(v+1); endV.push_back(w+1);
    }
  }
}
