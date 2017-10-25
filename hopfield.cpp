#include <random>
#include "hopfield.h"

Hopfield::Hopfield(int size){
	weights.resize(size, vector<int>(size, 0));
	state.resize(size);
	bias.resize(size);
	srand(time(NULL));
	for(int i = 0; i < size; i++){
		double randProb = (double)  rand()/RAND_MAX;
		if(randProb < 0.5)	state[i] = 1;
		else state[i] = -1;
		
		
	}

}
