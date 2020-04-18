#include <iostream>

using namespace std;

class Student{
  public:
    Student();
    Student(int arriveTime, int timeNeeded);
    ~Student();

    int getWaitTime();
    int getArrive();
    int getReqTime();

    void setWaitTime(int time);

  private:
    int waitTime;
    int arrive;
    int reqTime;

    //T* GenQueue; //maybe access memory in queue
};
