#include "Registrar.h"

Registrar::Registrar(){
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
  return isBusy;
}

void Registrar::reset(){
  idleTime = 0;
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
