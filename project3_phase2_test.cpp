#include "project3.h"
#include "Erdos-Renyi.h"
#include "Barabasi_Albert.h"
#include "graph.h"
#include <iostream>
#include <utility>
#include <string>
#include <cmath>
#include <fstream>
#include <map>
#include <numeric>

typedef void (*algorithm)(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space);
typedef std::map<std::string, algorithm> alg_map;

Graph generateBAGraph(int sz, int d)
{
  BAgraph ergraph = BAgraph(sz, d);
  return make_graph(sz, ergraph.startV, ergraph.endV);
}

Graph generateERGraph(int sz)
{
  ERgraph ergraph = ERgraph(sz);
  return make_graph(sz, ergraph.startV, ergraph.endV);
}

void create_DC_empty_file(std::string filename)
{
  std::ofstream f;
  f.open(filename, std::ios::trunc);
  f << "n,diameter,clustering\n";
  f.close();
}

void create_DD_empty_file(std::string filename)
{
  std::ofstream f;
  f.open(filename, std::ios::trunc);
  f << "degree,num\n";
  f.close();
}

void add_to_file(int n, int diam, float cc, std::string filename)
{
  std::ofstream f;
  f.open(filename, std::ios::app);
  f << n << "," << diam << "," << cc << "\n";
  f.close();
}

void add_to_DD_file(std::map<int, int> m, std::string filename)
{
  std::ofstream f;
  f.open(filename, std::ios::app);
  for (std::map<int,int>::iterator dd = m.begin(); dd!=m.end();dd++)
  {
    f << dd->first << "," << dd->second << "\n";
  }
  f.close();
}

int main()
{
  std::list<int> szs1 = { 10,50, 100, 1000, 5000, 10000, 50000, 100000 };

  std::string funcnameER = "Erdos_Ranyi_diam_cc";
  std::string filenameER = "csv_files/" + funcnameER + ".csv";
  std::cout << filenameER << std::endl;

  create_DC_empty_file(filenameER);

  int i = 0;
  for (int sz : szs1)
  {
    float p = 2 * log1p(sz) / sz;
    std::cout << "ER Test " << sz << "with p: " << p  << "\t1/n: " << (float) 1/sz << std::endl;
    int diam_tot = 0;
    float cc_tot = 0;
    for (int j = 1; j <= 8; j++)
    {
      std::cout << j << " ";
      Graph graph = generateERGraph(sz);
      diam_tot += get_diameter(graph);
      cc_tot += get_clustering_coefficient(graph);
      if (sz == 1000 || sz == 10000 || sz == 100000)
      {
        std::string funcnameER_dd = "Erdos_Ranyi_dd_";
        std::string filenameER_dd = "csv_files/" + funcnameER_dd + std::to_string(sz) + ".csv";
        std::cout << filenameER_dd << std::endl;

        create_DD_empty_file(filenameER_dd);
        std::map<int, int> dd = get_degree_distribution(graph);

        add_to_DD_file(dd, filenameER_dd);
      }
    }
    diam_tot /= 10; cc_tot /= 10;
    add_to_file(sz, diam_tot, cc_tot, filenameER);

    i++;
    std::cout << std::endl;
  }

  std::string funcnameBA = "Barabasi_Albert_diam_cc";
  std::string filenameBA = "csv_files/" + funcnameBA + ".csv";
  std::cout << filenameBA << std::endl;

  create_DC_empty_file(filenameBA);

  for (int sz : szs1)
  {
    std::cout << "BA Test " << sz << std::endl;
    int diam_tot = 0;
    float cc_tot = 0;
    for (int j = 1; j <= 8; j++)
    {
      std::cout << j << " ";
      Graph graph = generateBAGraph(sz,5);
      diam_tot += get_diameter(graph);
      cc_tot += get_clustering_coefficient(graph);
      if (sz == 1000 || sz == 10000 || sz == 100000)
      {
        std::string funcnameBA_dd = "Barabasi_Albert_dd_";
        std::string filenameBA_dd = "csv_files/" + funcnameBA_dd + std::to_string(sz) + ".csv";
        std::cout << filenameBA_dd << std::endl;

        create_DD_empty_file(filenameBA_dd);
        std::map<int, int> dd = get_degree_distribution(graph);

        add_to_DD_file(dd, filenameBA_dd);
      }
    }
    diam_tot /= 10; cc_tot /= 10;
    add_to_file(sz, diam_tot, cc_tot, filenameBA);

    std::cout << std::endl;
  }
  std::cout << std::endl;

  return 0;
}
