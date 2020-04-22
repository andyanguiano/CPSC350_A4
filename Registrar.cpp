#include "Registrar.h"


Registrar::Registrar(){
  busyTime = 0;
  idleTime = 0;
  over5 = 0;
  longestIdle = 0;
  numberIdles = 0;
  mean = 0.0;
  totalIdleTime = 0;
  isBusy = false;
}

Registrar::~Registrar(){

}

bool Registrar::checkIsBusy(){
  return busyTime > 0;
}

Student Registrar::takeStudent(Student s){
  if(!(this->checkIsBusy())){
    busyTime = s.getReqTime();
    if(idleTime > longestIdle){
      longestIdle = idleTime;
    }
    //reset idle time because it has a student
    idleTime = 0;
  }
  return s;
}

void Registrar::update(){
  if(busyTime > 0){
    busyTime -= 1;
  }else{
    idleTime += 1;
    totalIdleTime += 1;
  }
  if(idleTime == 6){
    over5 += 1;
  }
  if(idleTime > longestIdle){
    longestIdle = idleTime;
  }
}

void Registrar::reset(){
  busyTime = 0;
  if(idleTime > longestIdle){
    longestIdle = idleTime;
  }
  idleTime = 0;
  this->checkOver5();
}

int Registrar::getIdleTime(){
  return idleTime;
}

int Registrar::getLongestIdlee(){
  return longestIdle;
}

void Registrar::checkOver5(){
  if(idleTime >= 5){
    over5 += 1;
  }
}

int Registrar::getOver5(){
    return over5;
}

void Registrar::checkLongestIdle(){
  totalIdleTime += idleTime;
  if(idleTime > longestIdle){
    longestIdle = idleTime;
  }
}

int Registrar::getLongestIdle(){
  return longestIdle;
}

int Registrar::meanIdleTime(){
  mean = totalIdleTime/numberIdles;
}

int Registrar::getTotalIdleTime(){
  return totalIdleTime;
}
