#include "DoublyListNode.h"

template <class T>
class DoublyLinkedList{
  public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertFront(T d);
    void insertBack(T d);
    T removeFront();
    T removeBack();
    int search(T val); //return position of ListNode
    T removeAtPos(int pos);

    int getSize();
    bool isEmpty();
    void printList();
    bool containsDuplicates();

  private:
    DoublyListNode<T> *front;
    DoublyListNode<T> *back;
    int maxSize;
    int size;
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  size = 0;
  maxSize = 128;
  front = NULL;
  prev = NULL;
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
  size++;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d){
  DoublyListNode<T> *node = new DoublyListNode<T>(d);
  if(isEmpty()){
    back = node;
  }else{
    //not empty
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

template <class T>
T DoublyLinkedList<T>::removeFront(){
  if(isEmpty()){
    cout << "List is Empty" << endl;
    return NULL;
  }
  DoublyListNode<T>* temp  ;

  return temp;
}

template <class T>
T DoublyLinkedList<T>::removeBack(){
  if(isEmpty()){
    cout << "List is Empty" << endl;
    return NULL;
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

  DoublyListNode<T> *curr;
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
bool DoublyLinkedList<T>::containsDuplicates(){
  int pos = -1;
  DoublyListNode<T> *curr = front;
  int arrayCheck[maxSize];
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
