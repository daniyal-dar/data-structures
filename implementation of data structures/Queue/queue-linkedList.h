

// this header file contains the generic code of queue using linked list 
// note** dont forget to add the "linkedList-singly.h" library in the same root 

#pragma once
#include"linkedList-singly.h"

template <class T>
class Queue
{
private:
    LinkedList<T> list;         // object of linked list
    int current_size;           // holds the count of elements stored in array

public:
    Queue();                    // default constructor
    void enqueue(T value);      // stores value in queue
    T dequeue();                // removes first value stored in queue
    T peek();                   // returns the first value stored in queue
    bool isEmpty();             // check is queue empty
    void display();             // displays queue
};

template<class T>
Queue<T>::Queue()
{
    current_size = 0;
}

template<class T>
void Queue<T>::enqueue(T value)
{
    list.insertAtTail(value);
    current_size++;
}


template<class T>
T Queue<T>::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue Underflow! Cannot dequeue." << endl;
        return T();
    }
    T val = list.deleteFromHead();
    current_size--;
    return val;
}


template<class T>
T Queue<T>::peek()
{
    if (isEmpty())
    {
        cout << "Queue is empty!" << endl;
        return T();
    }
    else
    {
        T val = list.deleteFromTail();
        list.insertAtTail(val);
        return val;
    }
}

template<class T>
bool Queue<T>::isEmpty()
{
    return list.isEmpty();
}

template<class T>
void Queue<T>::display()
{
    list.display();
}

