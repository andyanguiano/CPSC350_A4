#include "Student.h"

Student::Student(){
  waitTime = 0;
  arrive = 0;
  reqTime = 0;
}

Student::Student(int arriveTime, int timeNeeded){
  arrive = arriveTime;
  reqTime = timeNeeded;
}

Student::~Student(){

}

int Student::getWaitTime(){
  return waitTime;
}

int Student::getArrive(){
  return arrive;
}

int Student::getReqTime(){
  return reqTime;
}

void Student::setWaitTime(int time){
  waitTime = time;
}
