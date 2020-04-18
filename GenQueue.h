#include <iostream>

using namespace std;

template <class T>
class GenQueue{
  public:
    GenQueue();
    GenQueue(int maxSize);
    ~GenQueue();

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

    T *myQueue; //array
};

//default constructor
template <class T>
GenQueue<T>::GenQueue(){
  myQueue = new T[128];
  mSize = 0;
  front = -1;
  rear = -1;
}

//overloaded constructor
template <class T>
GenQueue<T>::GenQueue(int maxSize){
  myQueue = new T[maxSize];
  mSize = maxSize;
  front = 0;
  rear = -1;
  numElements = 0;
}

//destructor
template <class T>
GenQueue<T>::~GenQueue(){
  delete myQueue;
}


template <class T>
void GenQueue<T>::insert(T d){
  //check if it is empty
  myQueue[++rear] = d;
  ++numElements;
}

template <class T>
T GenQueue<T>::remove(){
  //check is it is empty before it is removed
  T c = myQueue[front];
  ++front;
  --numElements;
  return c;
}

template <class T>
T GenQueue<T>::peek(){
  return myQueue[front];
}

template <class T>
bool GenQueue<T>::isFull(){
  return (numElements == mSize);
}

template <class T>
bool GenQueue<T>::isEmpty(){
  return (numElements == 0);
}
