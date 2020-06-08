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
    w += 1 + int(log(1 - r) / log(1 - this->p));
    //cout << "initial W and V: " << w << ", " << v << endl;
    while (w >= v && v < num_nodes)
    {
      w -= v; v++;;
    }

    if (v < num_nodes)
    {
      startV.push_back(v); endV.push_back(w);
    }
  }
}
