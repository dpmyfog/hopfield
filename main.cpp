#include <iostream>
#include "hopfield.h"

using namespace std;

void testDescent(){
  
  for(int i = 1; i <= 10; i++){
    Hopfield ex(100);
    vector<float> energies;
    
    for(int i = 0; i < 1000; i++){
      
      ex.update(1);
      energies.push_back(ex.getEnergy());
      
    }
    
    Hopfield::writeArrToFile("data/energies_"+to_string(i), energies);
    ex.randomize();
  }
}
void train(){
  string faceString = "0000000000000100010000000000000000000000000010000000000000000001110000001000100001000001101000000001";
  //string faceString = "00110110";
  cout << faceString.length() << endl;
  vector<string> stringarr;
  Hopfield ex(faceString.length());
  stringarr.push_back(faceString);
  ex.trainWeights(stringarr);
  ex.setState(faceString);
  ex.printConfiguration();
  ex.corrupt(2);
  cout << ex.getEnergy() << " NRG AFTER CORRUPTION" << endl;
  ex.update(1000);
  cout << ex.getEnergy() << " NRG AFTER UPDATING" << endl;
  ex.printConfiguration();
}

int main(){
  srand(time(NULL));
  testDescent();
}
