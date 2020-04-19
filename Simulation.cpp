#include "Simulation.h"

Simulation::Simulation(string file){
  file = "";
}

Simulation::~Simulation(){
}

int Simulation::runSimulation(string file){
  ifstream infs;
  infs.open(file);

  int lineNum = 1;
  string line = "";
  int totalNumStudents = 0;

  getline(infs,line);
  int numWindows = stoi(line);
  for(int i = 0; i < numWindows; ++i){
    Registrar tempReg;
    windows.insertBack(tempReg);
  }

  while(getline(infs,line)){
    //lineNum += 1;
    int time = stoi(line);

    getline(infs,line);
    //lineNum += 1;
    int numStudents = stoi(line);
    totalNumStudents += numStudents;

    for(int i = 0; i < numStudents; ++i){
      getline(infs,line);
      lineNum += 1;
      int timeNeeded = stoi(line);
      Student* tempStudent = new Student(time, timeNeeded);
      queue.insert(*tempStudent);
    }

    //clock;
    int currentTime = 0;
    //loop while there are students in queue and there are busy windows
    while(queue.getSize() != 0 && numBusyWindows() != 0){
      //loop while there are students in queue and windows are not full
      while(queue.getSize() > 0 && numBusyWindows() != numWindows){
        //go through windows
        for(int i = 0; i < numWindows; ++i){
          //if not busy than take a student
          if(!(windows.getPos(i).checkIsBusy())){
            Student tempStudent = queue.remove();
            windows.getPos(i).takeStudent(tempStudent);
            finishedStudents.insertBack(tempStudent);
            tempStudent = finishedStudents.getBack();
            tempStudent.setWaitTime(i);
          }
        }
      }

      //update all windows in clock tick
      for(int i = 0; i < numWindows; ++i){
        windows.getPos(i).update();
      }

      //update time
      currentTime += 1;


    }

    for(int i = 0; i < numWindows; ++i){
      windows.getPos(i).reset();
    }

    lineNum += 1;
  }



}

int Simulation::numBusyWindows(){
  int busy = 0;
  for(int i = 0; i>windows.getSize();++i){
    if(windows.getPos(i).checkIsBusy()){
      busy += 1;
    }
  }
  return busy;
}
