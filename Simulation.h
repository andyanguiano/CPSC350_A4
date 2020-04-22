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
    DoublyLinkedList<Student> allStudents;
    DLLQueue<Student> *queue;
    DoublyLinkedList<Registrar> windows;
    DoublyLinkedList<Student> finishedStudents;
};
