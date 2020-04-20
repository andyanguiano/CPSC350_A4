#ifndef DLLQUEUE_H
#define DLLQUEUE_H

#include "DoublyLinkedList.h"

template <class T>
class DLLQueue{
  public:
    DLLQueue();
    DLLQueue(int maxSize);
    ~DLLQueue();

    void insert(T d);
    T remove();

    //aux functions
    T peek();
    bool isFull();
    bool isEmpty();
    int getSize();

  private:
    //vars
    int front;//head
    int rear;//tail
    int mSize;
    int numElements;

    DoublyLinkedList<T>* myQueue; //array
};

#endif

//default constructor
template <class T>
DLLQueue<T>::DLLQueue(){
  myQueue = new DoublyLinkedList<T>;
  mSize = 0;
  front = -1;
  rear = -1;
}

//overloaded constructor
template <class T>
DLLQueue<T>::DLLQueue(int maxSize){
  myQueue = new DoublyLinkedList<T>;
  mSize = maxSize;
  front = 0;
  rear = -1;
  numElements = 0;
}

//destructor
template <class T>
DLLQueue<T>::~DLLQueue(){

}


template <class T>
void DLLQueue<T>::insert(T d){
  myQueue->insertBack(d);
  ++numElements;
}

template <class T>
T DLLQueue<T>::remove(){
  //check is it is empty before it is removed
  if(!(isEmpty())){
    T c = myQueue->removeFront();
    --numElements;
    return c;
  }

}

template <class T>
T DLLQueue<T>::peek(){
  return myQueue->getFront();
}

template <class T>
bool DLLQueue<T>::isFull(){
  return (numElements == mSize);
}

template <class T>
bool DLLQueue<T>::isEmpty(){
  return (numElements == 0);
}

template <class T>
int DLLQueue<T>::getSize(){
  return myQueue->getSize();
}
