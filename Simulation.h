#include "DLLQueue.h"
#include "Registrar.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Simulation{
  public:
    Simulation(string file);//default
    ~Simulation();//delete
    void runSimulation(string file);//runs simulation

  private:
    DoublyLinkedList<Student> allStudents;
    DLLQueue<Student> *queue;
    DoublyLinkedList<Student> finishedStudents;
};
