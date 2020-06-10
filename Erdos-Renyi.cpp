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
    //cout << "v: " << v << endl;
    double r = ((double)rand() / (RAND_MAX));
    if (r == 1)
      r /= 2;
    w += 1 + int(log2(1 - r) / log2(1 - this->p));
    //cout << "initial W, V, R: " << w << ", " << v << ", " << r << "\tlog2(1-r), log2(1-p): " << log2(1 - r)  << " " << log2(1 - this->p) << " " << int(log2(1 - r) / log2(1 - this->p)) <<endl;
    while (w >= v && v < num_nodes)
    {
      w -= v; v++;;
    }

    if (v < num_nodes)
    {
      //cout << "here" << endl;
      startV.push_back(v+1); endV.push_back(w+1);
    }
  }
}
