
#include <iostream>

using namespace std;

template <class T>
class DoublyListNode{
  public:
    DoublyListNode();
    DoublyListNode(T d);
    ~DoublyListNode();
    T data;
    DoublyListNode *next;
    DoublyListNode *prev;

};


template <class T>
DoublyListNode<T>::DoublyListNode(){
  next = NULL;
  prev = NULL;
}

template <class T>
DoublyListNode<T>::DoublyListNode(T d){
  data = d;
  next = NULL;
  prev = NULL;
}

template <class T>
DoublyListNode<T>::~DoublyListNode(){

}
