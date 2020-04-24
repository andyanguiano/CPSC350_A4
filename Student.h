#include <iostream>

using namespace std;

//Student Object
class Student{
  public:
    Student();//default
    Student(int arriveTime, int timeNeeded);
    ~Student();//delete

    int getWaitTime();//returns how long student waited
    int getArrive();//returns what time the student arrived
    int getReqTime();//returns the required time for the student

    void setWaitTime(int time);//sets how long the student waited

  private:
    int waitTime;
    int arrive;
    int reqTime;
    int currentTime;

};
