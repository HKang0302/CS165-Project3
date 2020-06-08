#include "graph.h"
#include <vector>
#include <cmath>

class ERgraph
{
public:
  ERgraph(int numNodes);
  int num_vertices;
  double p;
  std::vector<int> startV, endV;
};
