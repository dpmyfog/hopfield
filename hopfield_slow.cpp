#include <random>
#include <fstream>

#include "hopfield_slow.h"



using namespace std;

Hopfield_Slow::Hopfield_Slow(int size, int newNumMemories){
  weights.resize(newNumMemories, vector<float>(size, 0));
  state.resize(size, 1);
  bias.resize(size);
  this->size = size;
  numMemories = newNumMemories;

  for(int entry = 0; entry < size; entry++){
    double randDoub = (double) rand()/RAND_MAX;
    bias[entry] = randDoub;
    double randProb = (double) rand()/RAND_MAX;
    if(randProb > .5){
      state[entry] = 1;
    }
    else{
      state[entry] = -1;
    }

    for(int memory = 0; memory < numMemories; memory++){
      randDoub = (double) rand()/RAND_MAX;
      weights[memory][entry] = randDoub;
    }

    
  }
  
}

float Hopfield_Slow::getStim(int neuron){
  float totalWeight = 0.0f;
  for(int memory = 0; memory < numMemories; memory++){
    for(int weightIdx = 0; weightIdx < weights[memory].size(); weightIdx++){
      if(weights[memory][neuron] = -1){
	for(int otherNeuron = 0; otherNeuron < state.size(); otherNeuron++){
	  if(otherNeuron == neuron) totalWeight += 0;
	  else totalWeight += -1 * weights[memory][otherNeuron] / weights[memory].size();
	}
      }
      else{
	for(int otherNeuron = 0; otherNeuron < state.size(); otherNeuron++){
	  if(otherNeuron == neuron) totalWeight += 0;
	  else totalWeight += weights[memory][otherNeuron] / weights[memory].size();
	}
      }
    }
  }
  return totalWeight;
}

float Hopfield_Slow::getEnergy(){
  float weightsEnergy = 0;
  float biasEnergy = 0;
  for(int row = 0; row < size; row++){
    biasEnergy += bias[row]*state[row];
    for(int col = 0; col < size; col++){
      weightsEnergy += weights[row][col]*state[row]*state[col];
    }
  }
  return -.5*weightsEnergy + biasEnergy;
}

void Hopfield_Slow::update(int steps){
  for(int i = 0; i < steps; i++){
    int randNeuron = rand()%size;
    //cout << "attempt to flip neuron #"  << randNeuron << endl;
    float stim = getStim(randNeuron);
    if(stim > bias[randNeuron]){
      state[randNeuron] = 1;
    }
    
    else if (stim < bias[randNeuron]){
      state[randNeuron] = -1;
    }

    cout << getEnergy() << endl;
  }
}

/**
 * 
 */
void Hopfield_Slow::trainWeights(vector<string> bitstrings){
  
  numMemories = bitstrings.size();
  size = bitstrings[0].length();
  int memLength = size;
  
  weights.resize(numMemories, vector<float>(memLength, 0));
  state.resize(memLength);
  bias.resize(memLength);

  
  for(int mem = 0; mem < numMemories; mem++){
    for(int idx = 0; idx < memLength; idx++){
      int wgt = bitstrings[mem][idx] - '0';
      if(wgt == 0) weights[mem][idx] = -1;
      else weights[mem][idx] = 1;
    }
  }
}

void Hopfield_Slow::setState(string instate){
  for(int i = 0; i < instate.length(); i++){
    state[i] = instate[i];
  }
}

void Hopfield_Slow::corrupt(int numstates){
  for(int i = 0; i < numstates; i++){
    int randInt = rand()%2;
    if(randInt == 1) state[i]*=1;
  }
}

void Hopfield_Slow::randomize(){
  
}

void Hopfield_Slow::printConfiguration(){
  /*
  cout << "WEIGHTS============================" << endl;
  for(int row = 0; row < size; row++){
    for(int col = 0; col < size; col++){
      cout << weights[row][col] << " ";
    }
    cout << endl;
  }
  */
  cout << "STATE==============================" << endl;
  for(auto e: state) cout << e << " ";
  cout << endl;

  //for(auto e: bias) cout << e << " ";
  //cout << endl;
}

void Hopfield_Slow::writeArrToFile(string filename, vector<float> myvec){
  ofstream myfile;
  myfile.open(filename);
  for(int i = 0; i < myvec.size(); i++){
    myfile << myvec[i] << endl;
  }
  myfile.close();
  
}

/*
 
  for(string str : bitstrings){
  for(int row = 0; row < str.length(); row++){
  if(str[row] == '0'){
  for(int col = 0; col < str.length(); col++){
  weights[row][col] = -1*(str[col] - '0');
  }
  }
  else{
  for(int col = 0; col < str.length(); col++){
  int weightVal = str[col] - '0';
  weights[row][col] = (float)weightVal/size;
  if(col == row) weights[row][col] = 0;
  }
  }
  }
  }


 */
