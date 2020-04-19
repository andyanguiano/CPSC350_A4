#include "Simulation.h"

Simulation::Simulation(string file){
  file = "";
}

Simulation::~Simulation(){
}

int Simulation::runSimulation(string file){//does not recognize this method
  ifstream infs;
  infs.open(file);

  int lineNum = 1;
  string line = "";
  int totalNumStudents = 0;
  int currentTime = 0;

  getline(infs,line);
  int numWindows = stoi(line);
  for(int i = 0; i < numWindows; ++i){
    Registrar tempReg;
    windows.add(tempReg);
  }

  while(getline(file,line)){
    lineNum += 1;
    currentTime += 1;
    int time = stoi(line);

    getline(file,line)
    lineNum += 1;
    int numStudents = stoi(line);
    totalNumStudents += numStudents;

    for(int = 0; i < numStudents; ++i){
      getline(file,line);
      lineNum += 1;
      int timeNeeded = stoi(line);
      Student* tempStudent = new Student(time, timeNeeded);
      queue->insert(*tempStudent);
    }

    //temp node to iterate through list of registrars
    DoublyListNode<Registrar> curr = window->front;
    //while queue is not empty
    while(!queue->isEmpty()){
      //through number of windows
      for(int i = 0; i < windows.getSize(); ++i){
        //check if not busy
        if(!(curr.checkIsBusy())){
          //remove student from queue
          Student* tempStudent = queue->remove();
          //change to busy
          curr.isBusy = true;
        }else{
          //if busy move to next window
          temp = window->next;
        }
      }
    }
    delete temp;






  }
}


int Simulation::numBusyWindows(){
  /*int busy = 0;
  for(int i = 0; i>windows.getSize();++i){
    if(windows.getPos(i)->checkIsBusy()){
      busy += 1;
    }
  }
  return busy;*/
}
