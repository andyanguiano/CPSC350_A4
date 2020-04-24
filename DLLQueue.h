#ifndef DLLQUEUE_H
#define DLLQUEUE_H

#include "DoublyLinkedList.h"
//implements doubly linked list queue
template <class T>
class DLLQueue{
  public:
    DLLQueue();//constructor
    ~DLLQueue();//delete

    void insert(T d);//insert to teh back of the list
    T remove();//removes from the front of the list

    //aux functions
    T peek();//returns front value
    bool isEmpty();//returns if empty
    int getSize();//returns size

  private:
    //vars
    DoublyListNode<T>* front;//head
    DoublyListNode<T>* rear;//tail
    int numElements;

    DoublyLinkedList<T>* myQueue; //array
};

#endif

//default constructor
template <class T>
DLLQueue<T>::DLLQueue(){
  myQueue = new DoublyLinkedList<T>;
  numElements = 0;
  front = NULL;
  rear = NULL;
}

//destructor
template <class T>
DLLQueue<T>::~DLLQueue(){
  delete myQueue;
}


template <class T>
void DLLQueue<T>::insert(T d){
  DoublyListNode<T>* node = new DoublyListNode<T>(d);
  if(isEmpty()){
    front = node;
    rear = node;
  }else{
    rear->next = node;
    node->next = NULL;
    node->prev = rear;
  }
  myQueue->insertBack(d);
  ++numElements;
}

template <class T>
T DLLQueue<T>::remove(){
  //check is it is empty before it is removed
  if(!(isEmpty())){
    DoublyListNode<T>* temp = front->next;
    //only one node in the list
    if(front->next == NULL){
        rear = NULL;
      }else{
        //more than one node in the list
        front->next->prev = NULL;
        front = front->next;
        front->prev = NULL;
        temp->next = NULL;
      }
      T tempData = myQueue->removeFront();
      --numElements;
      delete temp;
      return tempData;
  }
}

template <class T>
T DLLQueue<T>::peek(){
  return myQueue->getFront();
}

template <class T>
bool DLLQueue<T>::isEmpty(){
  return (numElements == 0);
}

template <class T>
int DLLQueue<T>::getSize(){
  return numElements;
}
