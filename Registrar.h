#include <iostream>
#include "Student.h"

using namespace std;

class Registrar{
  public:
    Registrar();
    ~Registrar();

    bool checkIsBusy();
    Student takeStudent(Student s);
    void update();
    void reset();

    int getIdleTime();
    int getLongestIdlee();
    void checkOver5();
    int getOver5();
    void checkLongestIdle();
    int getLongestIdle();
    int meanIdleTime();
    bool isBusy;

  private:
    int busyTime;
    int idleTime;
    int over5;
    int longestIdle;
    int numberIdles;
    int totalIdleTime;
    float mean;
};
