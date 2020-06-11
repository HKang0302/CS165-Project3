#include "graph.h"
#include "helpers.h"
#include <iostream>
#include <cstring>
#include <unordered_set>
#include <queue>
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

int Graph::BFS(int nID, int& dist)
{
  std::unordered_set<int> seen;
  std::queue<int> q;
  dist = -1;
  int node = 0;
  q.push(nID);
  seen.insert(nID);

  while (!q.empty()) {
    std::vector<int> node_list;
    int recent_node;
    // aggregate all nodes to find all the neighbors at once
    while (!q.empty()) {
      node_list.push_back(q.front());
      q.pop();
    }
    for (const auto& current : node_list) {
      for (auto& neighbor : edges[current]) {
        if (seen.find(neighbor.id) == seen.end()) {
          recent_node = neighbor.id;
          seen.insert(neighbor.id);
          q.push(neighbor.id);
        }
      }
    }
    dist++;
    node = recent_node;
  }

  return node;

  //int startId = nID;
  //bool* visitedBFS = new bool[get_num_nodes()+1];
  ////for (int i = 0; i < get_num_nodes(); i++)
  ////  visitedBFS[i] = false;
  //memset(visitedBFS, false, sizeof(visitedBFS));

  //std::list<int> queue; // list of ids

  //visitedBFS[nID] = true;
  //queue.push_back(nID);

  //int firstID = nID;
  //int first_added = -1, temp = -1;
  //while (!queue.empty())
  //{
  //  nID = queue.front();
  //  queue.pop_front();

  //  std::vector<Node> adj = get_neighbors(getNode(nID));

  //  if (firstID == nID)
  //    first_added = -1;

  //  for (int i = 0; i < adj.size(); i++)
  //  {
  //    int id = adj[i].id;
  //    if (!visitedBFS[id - 1])
  //    {
  //      visitedBFS[id - 1] = true;
  //      queue.push_back(id);
  //      if (first_added == -1)
  //        first_added = id;
  //      else if (first_added == -100)
  //      {
  //        firstID = id;
  //        first_added = -1;
  //      }
  //    }
  //  }

  //  if (nID == firstID)
  //  {
  //    if (first_added != -1)
  //    {
  //      firstID = first_added;
  //      temp = first_added;
  //      first_added = -1;
  //    }

  //    else
  //    {
  //      firstID = -1;
  //      first_added = -100;
  //    }

  //    if (nID != startId)
  //      distance++;
  //  }
  //}

  //delete[] visitedBFS;
  //return nID; //or firstID?
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

std::vector<Node> Graph::getNodes()
{
  return nodes;
}

int Graph::getDegree(Node node)
{
  return edges[node.id].size();
}

int Graph::countTriangles()
{
  int cnt = 0;
  for (const auto& node : nodes) {
    std::vector<Node> neighbors = get_neighbors(node.id);
    for (unsigned int i = 0; i < neighbors.size(); ++i) {
      for (unsigned int j = i + 1; j < neighbors.size(); ++j) {
        int deg_v = getDegree(node);
        Node& left = neighbors[i];
        int left_deg = getDegree(left);
        Node& right = neighbors[j];
        int right_deg = getDegree(right);
        // using pseudocode from Stanford CS 167 paper http://theory.stanford.edu/~tim/s14/l/l1.pdf 
        // if both neighbors of v have higher degree than v or equal but higher lexicographically for individual ties
        if ((left_deg > deg_v && right_deg > deg_v)
          || (left_deg > deg_v && right_deg == deg_v && right.id > node.id)
          || (right_deg > deg_v && left_deg == deg_v && left.id > node.id)) {
          if (isNeighbor(left, right)) {
            ++cnt;
          }
        }

      }
    }
  }
  return cnt;
}

int Graph::getDenom()
{
  int total = 0;
  for (const auto& node : nodes)
  {
    if (node.id != 0)
    {
      int deg = getDegree(node);
      total += (deg * (deg - 1) / 2);
    }
  }
  return total;
}

std::map<int, int> Graph::vertex_to_degree_map(){
  std::map<int, int> ret;
  for (const auto& node : nodes)
  {
    if(node.id != 0)
      ret[node.id] = getDegree(node);
  }
  return ret;
}
