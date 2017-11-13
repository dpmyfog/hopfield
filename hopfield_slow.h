#ifndef HOPFIELD_SLOW_H
#define HOPFIELD_SLOW_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <utility>

using namespace std;


class Hopfield_Slow{
 public:
  vector<vector<float>> weights;
  vector<int> state;
  vector<float> bias;
  int size;
  int numMemories;
  
  Hopfield_Slow(int numMemories,int size);

  float getStim(int neuron);
  float getEnergy();
  void update(int steps);
  void trainWeights(vector<string> bitstrings);
  void setState(string state);
  void corrupt(int numstates);

  void randomize();
  
  void printConfiguration();
  static void writeArrToFile(string filename, vector<float> myvec);
  
  
};
#endif
