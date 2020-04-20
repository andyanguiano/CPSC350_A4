#include "Simulation.h"

int main(int argc, char **argv) {
  string fileName = "";
  if(argc > 1){
    fileName = argv[1];
    Simulation* run = new Simulation(fileName);
    run->runSimulation(fileName);
  }else{
    cout << "Too Run: ./a.out [fileName]" << endl;
  }
  return 0;
}
