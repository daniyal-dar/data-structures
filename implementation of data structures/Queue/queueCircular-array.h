
// this header file contains the generic implementation of the FILO  
// circular Queue using array 

#pragma once
#include<iostream>
using namespace std;

template<class T>
class Queue
{
private:
	T* data;			// pointer to dynamic array
	int current_size;	// holds the count of elements stored in array
	int max_size;		// holds the size of array
	
	int rear;			// index of last element in queue
	int front;			// index of first element in queue

public:
	Queue(const int size);		// default constructor
	~Queue();					// destructor
	void enqueue(T value);		// stores value in queue
	T dequeue();				// removes first value stored in queue
	bool isEmpty();				// check is queue empty
	bool isFull();				// check is queue full
	T peek();					// returns the first value stored in queue
	void display();				// displays queue
};

template<class T>
Queue<T>::Queue(int size)
{
	max_size = size;
	current_size = 0;
	data = new T[size];

	front = 0;
	rear = 0;
}

template<class T>
Queue<T>::~Queue() 
{
	delete[] data;
	data = nullptr;
}

template<class T>
void Queue<T>::enqueue(T value)
{
	if (isFull())
		cout << "Queue is full!" << endl;
	else
	{
		this->data[rear] = value;
		rear = (rear + 1) % max_size;
		this->current_size++;
	}		
}

template<class T>
T Queue<T>::dequeue()
{
	if (isEmpty())
	{
		cout << "Queue is Empty, returning JUNK zero" << endl;
		return T();
	}
	else
	{
		T returningValue = this->data[front];
		front = (front + 1) % max_size;
		this->current_size--;
		return returningValue;
	}
}

template<class T>
T Queue<T>::peek()
{
	if (isEmpty())
	{
		cout << "Queue is Empty!" << endl;
		return T();
	}

	else
		return this->data[this->front];
}

template<class T>
bool Queue<T>::isEmpty() { return (this->current_size == 0); }

template<class T>
bool Queue<T>::isFull() { return (this->current_size == this->max_size); }

template<class T>
void Queue<T>::display()
{
	cout << "Max Size = " << this->max_size << endl
		<< "Current Size = " << this->current_size << endl
		<< "Front = " << this->front << endl
		<< "Rear = " << this->rear << endl;

	for (int i = 0; i < this->current_size; i++)
    {
        int index = (this->front + i) % this->max_size;
        cout << i + 1 << ". " << this->data[index] << endl;
    }
}


