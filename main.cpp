#include <iostream>
#include <bitset>
#include "hopfield.h"
#include "hopfield_slow.h"

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
  string treeString = "0001111000000111100000001100000000110000001111111000001100100000110000000011000000001100000000110000";
  //string faceString = "00110110";
  //string treeString = "11100011";
  cout << faceString.length() << endl;
  vector<string> stringarr;
  Hopfield ex(faceString.length());
  //Hopfield_Slow ex_slow(8, 2);
  stringarr.push_back(faceString);
  stringarr.push_back(treeString);
  //ex_slow.trainWeights(stringarr);
  
  // ex_slow.printConfiguration();
  
  ex.corrupt(faceString.size()/2);
  cout << ex.getEnergy() << " NRG AFTER CORRUPTION" << endl;
  ex.update(1000);
  cout << ex.getEnergy() << " NRG AFTER UPDATING" << endl;
  ex.printConfiguration();
  
}

vector<string> genRandomMemories(int numMemories, int length){
  vector<string> outarr;

  for(int i = 0; i < numMemories; i++){
    string in = "";
    for(int j = 0; j < length; j++){
      double randDouble = (double) rand()/RAND_MAX;
      if(randDouble > 0.5){
	in+="0";
      }
      else{
	in+="1";
      }
    }
    cout << in << endl;
    outarr.push_back(in);
  }

  return outarr;
}

void testMemory(int numMemories, int length){
  vector<string> memories = genRandomMemories(numMemories, length);
  Hopfield ex(length);
  ex.trainWeights(memories);

  cout << "made past training" << endl;
  ex.printConfiguration();
  
  int randomMem = rand() % memories.size();
  cout << randomMem << endl;
  cout << "attempt to converge to: " << randomMem << endl;
  
  for(int i = 0; i < 0.6*length; i++){
    float totalDist = 0;
    for(int j = 0; j < 30; j++){
      ex.setState(memories[randomMem]);
      ex.corrupt(1);
      ex.update(1000);
      //ex.printConfiguration();
      
      totalDist += ex.hamming(Hopfield::toStateVector(memories[randomMem]));
    }
    cout<< "avg distance: " << totalDist/20.0 << endl;
  }
  
}





int main(){
  srand(time(NULL));

  Hopfield ex(5);
  ex.printConfiguration();
  vector<int> newState;
  newState.push_back(1);
  newState.push_back(-1);
  newState.push_back(-1);
  newState.push_back(1);
  newState.push_back(-1);
  ex.setState(newState);
  ex.printConfiguration();
  //testMemory(10, 50);
}
