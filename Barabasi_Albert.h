#include "graph.h"
#include <vector>
#include <cmath>

class BAgraph
{
public:
  BAgraph(int numNodes, int d);
  int num_vertices;
  std::vector<int> startV, endV;
};
