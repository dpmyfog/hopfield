#include <random>
#include "hopfield.h"


using namespace std;

Hopfield::Hopfield(int size){
  weights.resize(size, vector<float>(size, 0));
  state.resize(size);
  bias.resize(size);
  this->size = size;
  srand(time(NULL));
  for(int row = 0; row < size; row++){
    double randProb = (double)  rand()/RAND_MAX;
    if(randProb < 0.5)	state[row] = 1;
    else state[row] = -1;
    
    randProb = (double) rand()/RAND_MAX;
    double randBias = (double) rand()/RAND_MAX;
    
    if(randProb < 0.5) bias[row] = -1* randBias;
    else bias[row] = randBias;

    for(int col = row; col < size; col++){
      if(row == col) weights[row][col] = 0;
      else{
	randProb = (double) rand()/RAND_MAX;
	double randWeight = (double) rand()/RAND_MAX;
	
	if(randProb < 0.5) {
	  weights[row][col] = -1*randWeight;
	  weights[col][row] = -1*randWeight;
	}
	else {
	  weights[row][col] = randWeight;
	  weights[col][row] = randWeight;
	}
      }
    }      
  }
}

void Hopfield::printConfiguration(){
  cout << "WEIGHTS============================" << endl;
  for(int row = 0; row < size; row++){
    for(int col = 0; col < size; col++){
      cout << weights[row][col] << " ";
    }
    cout << endl;
  }
  
  cout << "STATE==============================" << endl;
  for(auto e: state) cout << e << " ";
  cout << endl;

  for(auto e: bias) cout << e << " ";
  cout << endl;
}
