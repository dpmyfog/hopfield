#ifndef HOPFIELD_H
#define HOPFIELD_H

#include <iostream>
#include <math>
#include <string>
#include <vector>
#include <utility>




class Hopfield{
	public:
		vector<vector<float>> weights;
		vector<int> state;
		vector<float> bias;
		int size;	

		Hopfield(int size);

};
#endif
