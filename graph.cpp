#include "graph.h"
#include "helpers.h"
#include <iostream>
#include <cstring>
using namespace std;

bool debug = false;

Graph::Graph(int num_nodes, std::vector<int> u, std::vector<int> v)
{
  this->nNode = num_nodes;
  this->nEdge = u.size();
  edges = new std::vector<Node>[num_nodes+1];

  // create nodes
  for (int i = 0; i <= num_nodes; i++)
  {
    Node n = Node(i);
    nodes.push_back(n);
  }

  // add edges and adj of the nodes
  for (int i = 0; i < nEdge; i++)
  {
    edges[u[i]].push_back(nodes[v[i]]);
    edges[v[i]].push_back(nodes[u[i]]);
    nodes[v[i]].degree++; nodes[u[i]].degree++;
  }  
}

Graph make_graph(int num_nodes, std::vector<int> u, std::vector<int> v){
  return Graph(num_nodes, u, v); 
}

int Graph::get_num_nodes() {
	return nNode;
}

int Graph::get_num_edges() {
	return nEdge;
}

std::vector<Node> Graph::get_neighbors(Node u) {
  return edges[u.id];
}

std::map<int, Node>Graph::get_id_to_node_map(){
  std::map<int, Node> result;
  for (int i = 1; i <= nNode; i++)
  {
    result.insert(std::pair<int, Node>(i, nodes[i]));
  }
	return result;
}

Node Graph::getNode(int id)
{
  std::map<int, Node> m = get_id_to_node_map();
  return m.find(id)->second;
}

bool Graph::isNeighbor(Node u, Node v)
{
  std::vector<Node> adj = get_neighbors(u);
  for (Node x : adj)
  {
    if (x.id == v.id)
      return true;
  }
  return false;
}

int Graph::BFS(int nID, int& dMax, bool* visited)
{
  int startId = nID;
  int distance = 0;
  bool* visitedBFS = new bool[get_num_nodes()+1];
  //for (int i = 0; i < get_num_nodes(); i++)
  //  visitedBFS[i] = false;
  memset(visitedBFS, false, sizeof(visitedBFS));

  std::list<int> queue; // list of ids

  visitedBFS[nID] = true;
  queue.push_back(nID);

  int firstID = nID;
  int first_added = -1, temp = -1;
  while (!queue.empty())
  {
    nID = queue.front();
    queue.pop_front();

    std::vector<Node> adj = get_neighbors(getNode(nID));

    if (firstID == nID)
      first_added = -1;

    for (int i = 0; i < adj.size(); i++)
    {
      int id = adj[i].id;
      if (!visitedBFS[id - 1])
      {
        visitedBFS[id - 1] = true;
        queue.push_back(id);
        if (first_added == -1)
          first_added = id;
        else if (first_added == -100)
        {
          firstID = id;
          first_added = -1;
        }
      }
    }

    if (nID == firstID)
    {
      if (first_added != -1)
      {
        firstID = first_added;
        temp = first_added;
        first_added = -1;
      }

      else
      {
        firstID = -1;
        first_added = -100;
      }

      if (nID != startId)
        distance++;
    }
  }

  if (dMax < distance)
    dMax = distance;

  delete[] visitedBFS;
  return nID; //or firstID?
}

std::vector<int> Graph::getDegrees()
{
  std::vector<int> result;
  for (int i = 0; i < get_num_nodes(); i++)
  {
    result.push_back((get_neighbors(getNode(i + 1))).size());
  }
  return result;
}

int Graph::getMaxDegree(std::vector<int> degrees)
{
  int max = 0;
  for (int i = 0; i < degrees.size(); i++)
    if (max < degrees[i])
      max = degrees[i];
  return max;
}

std::list<int> Graph::getDegeneracy(std::list<int>* N)
{
  std::vector<int> degrees = getDegrees(); // ith's node's degree
  std::list<int> L; // output list
  int maxDegree = getMaxDegree(degrees);
  std::list<int>* D = new std::list<int>[maxDegree + 1]; // 0 to maxDegree

  bool* H = new bool[degrees.size()]; // index: id-1
  memset(H, false, sizeof(H));

  for (int i = 0; i < degrees.size(); i++)
    D[degrees[i]].push_back(i + 1);

  int k = 0;
  for (int n = 0; n < degrees.size(); n++)
  {
    for (int i = 0; i <= maxDegree; ++i)
    {
      if (!D[i].empty())
      {
        k = std::max(k, i);
        int v = D[i].front();
        L.push_front(v);
        D[i].pop_front();
        H[v - 1] = true;
        std::vector<Node> adj = get_neighbors(getNode(v));
        for (int j = 0; j < adj.size(); j++)
        {
          int w = adj[j].id;
          if (!H[w - 1])
          {
            degrees[w - 1]--;
            int d = degrees[w - 1];
            // remove the node from D[d+1]
            D[d + 1].remove(w);
            // add the node to D[d]
            D[d].push_back(w);
            N[v - 1].push_back(w);
            D[d].sort();
          }
        }
        break;
      }
    }
  }
  delete[] D;
  return L;
}
