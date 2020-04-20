#include "Simulation.h"

int main(int argc, char **argv) {
  if(argc > 1){
    string fileName = argv[1];
    Simulation* run = new Simulation(fileName);
    run->runSimulation(fileName);
  }else{
    cout << "Too Run: ./a.out [fileName]" << endl;
  }
  return 0;
}
