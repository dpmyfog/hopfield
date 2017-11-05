#include <iostream>
#include "hopfield.h"

using namespace std;

int main(){
  Hopfield ex(100);
  vector<float> energies;
  for(int i = 0; i < 100; i++){
    
    ex.update(1);
    energies.push_back(ex.getEnergy());
    
  }

  Hopfield::writeArrToFile("data/energies_1", energies);
}
