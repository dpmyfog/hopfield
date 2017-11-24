#include <iostream>
#include <bitset>
#include "hopfield.h"
#include "hopfield_slow.h"

using namespace std;

void testDescent(){
  
  for(int i = 1; i <= 10; i++){
    Hopfield ex(100);
    vector<float> energies;
    
    for(int i = 0; i < 100000; i++){
      
      ex.update(1);
      energies.push_back(ex.getEnergy());
      
    }
    
    Hopfield::writeArrToFile("data/energies_"+to_string(i), energies);
    ex.randomize();
  }
}
void train(){
  //string faceString = "0000000000000100010000000000000000000000000010000000000000000001110000001000100001000001101000000001";
  //string treeString = "0001111000000111100000001100000000110000001111111000001100100000110000000011000000001100000000110000";
  string faceString = "00110110";
  string treeString = "10101011";
  cout << faceString.length() << endl;
  vector<string> stringarr;
  Hopfield ex(treeString.length());
  //Hopfield_Slow ex_slow(8, 2);
  stringarr.push_back(faceString);
  stringarr.push_back(treeString);
  ex.trainWeights(stringarr);
  
  // ex_slow.printConfiguration();
  
  ex.corruptRandom(faceString.size()/2);
  ex.printConfiguration();
  cout << ex.getEnergy() << " NRG AFTER CORRUPTION" << endl;
  ex.update();
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
    outarr.push_back(in);
  }
  for(int i = 0; i < outarr.size(); i++){
    cout << outarr[i] << endl;
  }

  return outarr;
}

vector<float> testMemory(int numMemories, int length){
  cout << "USING " << numMemories << " MEMORIES" << endl;
  vector<float> out;
  vector<string> memories = genRandomMemories(numMemories, length);
  Hopfield ex(length);
  ex.trainWeights(memories);

  //cout << "made past training" << endl;
  //ex.printConfiguration();
  
  int randomMem = rand() % memories.size();
  string remembered = memories[randomMem];
  vector<int> memState = Hopfield::toStateVector(remembered);
  //cout << "attempt to converge to: " << randomMem << endl;
  
  for(int i = 0; i < length; i++){
    float totalDist = 0;
    for(int j = 0; j < 20; j++){
      
      ex.setState(memState);
      ex.corruptRandom(i);
      //cout << "hamming after corruption: " << ex.hamming(memState) << endl;
      ex.update();
      //ex.printConfiguration();
      //cout << "hamming after converged: " << ex.hamming(memState) << endl;
      totalDist += ex.hamming(memState);
    }
    //cout << totalDist/30.0 << endl;
    //cout << "avg distance: " << totalDist/5 << endl;
    out.push_back(totalDist/30.0);
  }

  return out;
  
}





int main(){
  srand(time(NULL));
  
  //train();
  
  /*
  Hopfield ex(5);
  ex.printConfiguration();
  vector<int> newState;
  newState.push_back(1);
  newState.push_back(-1);
  newState.push_back(-1);
  newState.push_back(1);
  newState.push_back(-1);
  cout << ex.hamming(newState) << endl;
  ex.setState(newState);
  ex.printConfiguration();
  */


  vector<vector<float>> distMtx;
  for(int i = 1; i <= 100; i++){
    distMtx.push_back(testMemory(i, 100));
  }

  Hopfield::writeArrToFile("data/hamming/hammingMtx", distMtx);
  
  
  /*
  Hopfield ex(100);
  vector<int> remembered = ex.state;
  cout << "Hamming before corrupting: " << ex.hamming(remembered) << endl;
  ex.corruptRandom(25);
  cout << "Haming after corrupting: " << ex.hamming(remembered) << " (should be 25)" << endl;
  */

  
  //testDescent();
  

}
