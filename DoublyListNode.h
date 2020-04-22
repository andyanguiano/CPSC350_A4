#ifndef DOUBLYLISTNODE_H
#define DOUBLYLISTNODE_H
#include <iostream>

using namespace std;

//list node for a doubly linked list
//template class for any data
template <class T>
class DoublyListNode{
  public:
    //DoublyListNode();
    DoublyListNode(T d);
    ~DoublyListNode();
    T data;
    DoublyListNode *next;
    DoublyListNode *prev;

};

#endif

/*
template <class T>
DoublyListNode<T>::DoublyListNode(){
  next = NULL;
  prev = NULL;
}
*/

template <class T>
DoublyListNode<T>::DoublyListNode(T d){
  data = d;
  next = NULL;
  prev = NULL;
}

template <class T>
DoublyListNode<T>::~DoublyListNode(){
}
