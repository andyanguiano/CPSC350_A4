#include "DLLQueue.h"
#include "Student.h"
#include "Registrar.h"
#include <iostream> 
#include <fstream>

using namespace std;

class Simulation{
  public:
    Simulation(string file);
    ~Simulation();
    int runSimulation(string file);
    int numBusyWindows();

  private:
    DLLQueue<Student> queue;
    DoublyLinkedList<Registrar> windows;
    DoublyLinkedList<Student> finishedStudents;
};
