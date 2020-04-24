#include "Simulation.h"

Simulation::Simulation(string file){
  file = "";
  queue = new DLLQueue<Student>();
}

Simulation::~Simulation(){
}

void Simulation::runSimulation(string file){
  ifstream infs;
  infs.open(file);

  int lineNum = 1;
  string line = "";
  int totalNumStudents = 0;

  //getn numWindows
  getline(infs,line);
  int numWindows = stoi(line);
  Registrar windows[numWindows];
  for(int i = 0; i < numWindows; ++i){
    Registrar tempReg;
    windows[i] = tempReg;
  }

  int totalWaitingTime = 0;
  if(!infs.fail()){
    //this gets time students arrive
    while(getline(infs,line)){
      //lineNum += 1;
      int time = stoi(line);
      //gets numStudents at time
      getline(infs,line);
      //lineNum += 1;
      int numStudents = stoi(line);
      totalNumStudents += numStudents;

      for(int i = 0; i < numStudents; ++i){
        //gets timeNeeded for wach student
        getline(infs,line);
        lineNum += 1;
        int timeNeeded = stoi(line);
        Student* tempStudent = new Student(time, timeNeeded);
        allStudents.insertBack(*tempStudent);
      }
    }
  }

  //clock;
  int currentTime = 1;
  int totalBusy = 0;

  //main body loop
  while(allStudents.getSize() != 0 || queue->getSize() != 0 || totalBusy != 0){
    int busy = 0;
    for(int i = 0; i < numWindows; ++i){
      if(windows[i].checkIsBusy()){
        busy += 1;
      }
    }
    totalBusy = busy;

    int numAllStudents = allStudents.getSize();
    //add students to queue if their time
    while(allStudents.getSize() > 0 && currentTime == allStudents.getFront().getArrive()){
        queue->insert(allStudents.removeFront());
    }

    //go through windows
    for(int i = 0; i < numWindows; ++i){
      //if not busy than take a student
      if(!(windows[i].checkIsBusy()) && queue->getSize() > 0){
        Student tempStudent = queue->remove();
        tempStudent.setWaitTime(currentTime - tempStudent.getArrive());
        windows[i].takeStudent(tempStudent);
        finishedStudents.insertFront(tempStudent);
        tempStudent = finishedStudents.getBack();
      }
    }

    //update all windows in clock tick
    for(int i = 0; i < numWindows; ++i){
      windows[i].update();
    }

    //update time
    currentTime += 1;

  }

  //calculate
  //for mean

  //int totalWaitingTime = 0;
  //for median
  DoublyLinkedList<int>* orderedWaitTimes = new DoublyLinkedList<int>;
  int longestWaitTime = 0;
  int waitOver10 = 0;

  for(int i = 0; i < finishedStudents.getSize()-1; ++i){

    int currentWaitTime = finishedStudents.getPos(i).getWaitTime();//here is seg fault
    cout << finishedStudents.getBack().getWaitTime() << endl;

    if(currentWaitTime > longestWaitTime){
      longestWaitTime = currentWaitTime;
    }
    if(currentWaitTime > 10){
      waitOver10 += 1;
    }
    //check is wait time was added if not then add to end
    bool checkAdded = false;
    //for loop to insert wait times from greatest to least
    for(int j = 0; j < orderedWaitTimes->getSize(); ++j){
      if(currentWaitTime < orderedWaitTimes->getPos(j)){
        orderedWaitTimes->insertPos(j, currentWaitTime);
        checkAdded = true;
        break;
      }
    }

    if(!checkAdded){
      orderedWaitTimes->insertBack(currentWaitTime);
    }
    totalWaitingTime += currentWaitTime;
  }

  //mean wait
  float meanWaitTime = totalWaitingTime/(orderedWaitTimes->getSize());
  //median wait
  int middlePos = orderedWaitTimes->getSize()/2;
  float medianWaitTime = orderedWaitTimes->getPos(middlePos);

  //for mean idle time
  int totalIdleTime = 0;
  int longestIdleTime = 0;
  int idleOver5 = 0;

  for(int i = 0; i < numWindows; ++i){
    int currIdleTime = windows[i].getTotalIdleTime();
    totalIdleTime += currIdleTime;
    if(currIdleTime > longestIdleTime){
      longestIdleTime = currIdleTime;
    }
    int currIdleOver5 = windows[i].getOver5();
    idleOver5 += currIdleOver5;
  }

  double meanIdleTime = totalIdleTime/numWindows;

  cout << "1. The mean student wait time: " << meanWaitTime << endl;
  cout << "2. The median student wait time: " << medianWaitTime << endl;
  cout << "3. The longest student wait time: " << longestWaitTime << endl;
  cout << "4. The number of students waiting over 10 minutes: " << waitOver10 << endl;
  cout << "5. The mean window idle time: " << meanIdleTime << endl;
  cout << "6. The longest window idle time: " << longestIdleTime << endl;
  cout << "7. Number of windows idle for over 5 minutes: " << idleOver5 << endl;
}
