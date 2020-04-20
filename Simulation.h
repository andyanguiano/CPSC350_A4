#include "DLLQueue.h"
#include "Registrar.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Simulation{
  public:
    Simulation(string file);
    ~Simulation();
    void runSimulation(string file);
    int numBusyWindows();

  private:
    DLLQueue<Student>* queue;
    DoublyLinkedList<Registrar> windows;
    DoublyLinkedList<Student> finishedStudents;
};
