#include "DoublyListNode.h"
#include <iostream>

template <class T>
class DoublyLinkedList{
  public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertFront(T d);
    void insertBack(T d);
    void insertPos(int pos, T d);
    T removeFront();
    T removeBack();
    int search(T val); //return position of ListNode
    T removeAtPos(int pos);
    T getFront();
    T getBack();
    DoublyListNode<T>* getNPos(int pos);
    T getPos(int pos);

    int getSize();
    bool isEmpty();
    void printList();
    bool containsDuplicates();

    DoublyListNode<T> *front;
    DoublyListNode<T> *back;
  private:
    int size;
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){

}

template <class T>
int DoublyLinkedList<T>::getSize(){
  return size;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty(){
  return (size == 0);
}

template <class T>
void DoublyLinkedList<T>::printList(){
  DoublyListNode<T> *current = front;

  while(current != NULL){
    cout << current->data << endl;
    current = current->next;//listnode
  }

}

template <class T>
void DoublyLinkedList<T>::insertFront(T d){
  DoublyListNode<T> *node = new DoublyListNode<T>(d);
  if(isEmpty()){
    back = node;
  }else{
    //not empty
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d){
  DoublyListNode<T> *node = new DoublyListNode<T>(d);
  if(isEmpty()){
    front = node;
  }else{
    //not empty
    back->next = node;
    node->next = NULL;
    node->prev = back;
  }
  back = node;
  size++;
}

template <class T>
void DoublyLinkedList<T>::insertPos(int pos, T d){
  DoublyListNode<T>* curr = this->getNPos(pos);
  if(curr != NULL){
    DoublyListNode<T>* previous = curr->prev;
    DoublyListNode<T> *node = new DoublyListNode<T>(d);
    curr->prev = node;
    previous->next = node;
    node->prev = previous;
    node->next = curr;
  }
  size++;
}

template <class T>
T DoublyLinkedList<T>::removeFront(){
    DoublyListNode<T>* temp = front;
    //only one node in the list

    if(front->next == NULL){
        back = NULL;
      }else{
        //more than one node in the list
        front->next->prev = NULL;
        front = front->next;
        front->prev = NULL;
        temp->next = NULL;
      }
      T tempData = temp->data;
      size--;
      delete temp;
      return tempData;
}

template <class T>
T DoublyLinkedList<T>::removeBack(){
  DoublyListNode<T> *tempNode = back;

  if(!(isEmpty())){
    if(back->prev == NULL){
      front = NULL;
    }else{
      //more than one node in the list
      front->prev->next = NULL;
    }

    back = back->prev;
    tempNode->prev = NULL;
    T temp = tempNode->data;
    size--;
    delete tempNode;
    return temp;
  }
}

template <class T>
int DoublyLinkedList<T>::search(T val){
  int pos = -1;
  DoublyListNode<T> *curr = front;
  //loop and attempt to find the value
  while(curr != NULL){
    ++pos;
    if(curr->data == val){
      //we found it
      break;
    }else{
      //we didnt continue iterating
      curr = curr->next;
    }

    if(curr == NULL){
      //didnt find it
      pos = -1;
    }
    return pos;
  }
}

template <class T>
T DoublyLinkedList<T>::removeAtPos(int pos){
  //error to make sure pos does not exceed size of listnode
  int idx = 0;

  DoublyListNode<T> *curr = front;
  DoublyListNode<T> *prev = front;

  while(idx != pos){
    //loop until I find the position
    prev = curr;
    curr = curr->next;
    idx++;
  }
  //continue with the delete process
  prev->next = curr->next;
  curr->next = NULL;
  T temp = curr->data;
  delete curr;
  size--;

  return temp;
}

template <class T>
T DoublyLinkedList<T>::getFront(){
  if(!(isEmpty())){
    return front->data;
  }
}

template <class T>
T DoublyLinkedList<T>::getBack(){
  if(!(isEmpty())){
    return back->data;
  }
}

template <class T>
DoublyListNode<T>* DoublyLinkedList<T>::getNPos(int pos){
  int i = 0;
  if(pos < size){
    DoublyListNode<T>* current = front;//->next;
    while(i != pos){
      current = current->next;
      ++i;
    }
    return current;
  }
}

template <class T>
T DoublyLinkedList<T>::getPos(int pos){
  DoublyListNode<T>* current = this->getNPos(pos);
  return current->data;
}

template <class T>
bool DoublyLinkedList<T>::containsDuplicates(){
  int pos = -1;
  DoublyListNode<T> *curr = front;
  int arrayCheck[size];
  int test = 0;

  while(curr != NULL){
    ++pos;
    arrayCheck[test] = curr->data;
    for(int i = 0; i < pos + 1; ++i){
      if(curr->data == arrayCheck[i]){
        return true;
      }
    }
  }
  return false;
}
