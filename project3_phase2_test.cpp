//#include "project3.h"
//#include <iostream>
//#include <utility>
//#include <string>
//#include <cmath>
//#include <fstream>
//#include <map>
//#include <numeric>
//
//typedef void (*algorithm)(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space);
//typedef std::map<std::string, algorithm> alg_map;
//
//std::vector<double> generateTest(int sz)
//{
//  std::vector<double> result;
//  for (int i = 0; i < sz; i++)
//  {
//    result.push_back(((double)rand() / RAND_MAX) * 0.70); // 0-0.7
//  }
//  return result;
//}
//
//alg_map init_algs()
//{
//  alg_map bin_algs;
//  bin_algs.insert(std::pair<std::string, algorithm>("next_fit", &next_fit));
//  bin_algs.insert(std::pair<std::string, algorithm>("first_fit", &first_fit));
//  bin_algs.insert(std::pair<std::string, algorithm>("best_fit", &best_fit));
//  bin_algs.insert(std::pair<std::string, algorithm>("first_fit_decreasing", &first_fit_decreasing));
//  bin_algs.insert(std::pair<std::string, algorithm>("best_fit_decreasing", &best_fit_decreasing));
//  return bin_algs;
//}
//
//void create_empty_W_file(std::string filename)
//{
//  std::ofstream f;
//  f.open(filename, std::ios::trunc);
//  f << "Algorithm_Name,n,W(Algorithm)\n";
//  f.close();
//}
//
//void add_W_to_file(std::string funcname, waste w, std::string filename)
//{
//  std::ofstream f;
//  f.open(filename, std::ios::app);
//  f << funcname << "," << w.n << "," << w.w << "\n";
//  f.close();
//}
//
//
//int main22()
//{
//  alg_map algs = init_algs();
//  std::vector<std::vector<double>> tests;
//  tests.push_back(generateTest(100));
//  tests.push_back(generateTest(1000));
//  tests.push_back(generateTest(10000));
//  tests.push_back(generateTest(100000));
//  //tests.push_back(generateTest(50000));
//
//  std::string funcname = "Erdos-Renyi";
//  std::string filename = "csv_files/" + funcname + ".csv";
//  std::cout << filename << std::endl;
//
//  create_empty_W_file(filename);
//
//  int i = 0;
//  for (auto test : tests)
//  {
//    std::cout << "Test " << i << std::endl;
//    w = get_waste(test, algs[funcname]);
//    add_W_to_file(funcname, w, filename);
//    i++;
//  }
//  std::cout << std::endl;
//
//  return 0;
//}
//
