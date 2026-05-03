

// this header file contains the generic implementation of the stack using linked list 
// note** dont forget to add the "linkedList-singly.h" library in the same root 


#pragma once
#include"linkedList-singly.h"

template <class T>
class Stack
{
private:
    LinkedList<T> list;     // linked list obj
    int current_size;       // current size of stack

public:
    Stack();                // default constructor
    void push(T value);     // pushes element in stack
    T pop();                // removes element from stack
    T top();                // returns the last element stack hold
    bool isEmpty();         // check is stack empty
    void display();         // displays stack
};

template<class T>
Stack<T>::Stack()
{
    current_size = 0;
}

template<class T>
void Stack<T>::push(T value)
{
    list.insertAtHead(value);
    current_size++;
}

template<class T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow! Cannot pop." << endl;
        return T();
    }
    T val = list.deleteFromHead();
    current_size--;
    return val;
}

template<class T>
T Stack<T>::top()
{
    if (isEmpty())
    {
        cout << "Stack is empty!" << endl;
        return T();
    }
    else
    {
        T val = list.deleteFromHead();
        list.insertAtHead(val);
        return val;
    }
}

template<class T>
bool Stack<T>::isEmpty()
{
    return list.isEmpty();
}

template<class T>
void Stack<T>::display()
{
    list.display();
}

