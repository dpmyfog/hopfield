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

  bool isConverged();
  float getStim(int neuron);
  float getEnergy();
  void update(int steps);
  void update();
  void trainWeights(vector<string> bitstrings);
  void setState(string state);
  void setState(vector<int> & instate);
  void corrupt(int numstates);
  void corruptRandom(int numstates);

  void randomize();
  float hamming(vector<int> otherState);
  
  void printConfiguration();
  void printState();
  static void writeArrToFile(string filename, vector<float> myvec);
  static void writeArrToFile(string filename, vector<vector<float>> myvec);
  static vector<int> toStateVector(string stringVec);
  
};
#endif
