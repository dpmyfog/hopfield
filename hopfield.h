#ifndef HOPFIELD_H
#define HOPFIELD_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <utility>

using namespace std;


class Hopfield{
 public:
  vector<vector<float>> weights;
  vector<int> state;
  vector<float> bias;
  int size;	
  
  Hopfield(int size);
  void printConfiguration();
  
  
};
#endif
