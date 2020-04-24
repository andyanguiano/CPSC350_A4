#include <iostream>
#include "Student.h"
//object of a registrar
using namespace std;

class Registrar{
  public:
    Registrar();//defalut
    ~Registrar();//delete

    bool checkIsBusy();//returns if busy
    Student takeStudent(Student s);//takes a students requrired time
    void update();//updats every clocktick

    int getIdleTime();//returns how long the idle was
    int getLongestIdlee();//returns the longest idle
    void checkOver5();//checks to see if over 5 idle time
    int getOver5();//returns over 5
    void checkLongestIdle();//check to see if it a longest idle
    int getLongestIdle();//returns the longest idle
    int getTotalIdleTime();//returns totalIdleTime
    int getBusyTime();//returns how long was busy

  private:
    int busyTime;
    int idleTime;
    int over5;
    int longestIdle;
    int numberIdles;
    int totalIdleTime;
};
