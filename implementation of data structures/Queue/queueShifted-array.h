

// this header file contains the generic implementation of the FIFO
// shifted Queue using array

#pragma once
#include <iostream>
using namespace std;

template<class T>
class Queue
{
private:
	T* data;			// pointer to dynamic array
	int current_size;	// holds the count of elements stored in array
	int max_size;		// holds the size of array

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

template <class T>
Queue<T>::Queue(const int size)
{
	this->data = new T[size];
	this->current_size = 0;
	this->max_size = size;
}

template<class T>
Queue<T>::~Queue() 
{
	delete[] data;
	data = nullptr;
}

template <class T>
void Queue<T>::enqueue(T value)
{
	if (!isFull())
	{
		this->data[this->current_size] = value;
		this->current_size++;
	}
	else
		cout << "Queue is full! operation can't performed!" << endl;
}

template <class T>
T Queue<T>::dequeue()
{
	if (!isEmpty())
	{
		T value = this->data[0];
		this->current_size--;

		// over writing elements one step back to deque first element from queue
		for (int i = 0; i < this->current_size; i++)
			this->data[i] = this->data[i + 1];

		return value;
	}
	else
	{
		cout << "Queue is empty! operation can't performed!" << endl;
		return T();
	}
}

template <class T>
bool Queue<T>::isEmpty() { return this->current_size == 0; }

template <class T>
bool Queue<T>::isFull() { return this->current_size == this->max_size; }

template <class T>
T Queue<T>::peek()
{
	if (!isEmpty())
		return this->data[0];
	else
	{
		cout << "Queue is empty! nothing to show." << endl;
		return T();
	}
}

template <class T>
void Queue<T>::display()
{
	cout << "Max_Size: " << this->max_size << endl
		<< "Current_Size: " << this->current_size << endl;
	for (int i = 0; i < this->current_size; i++)
		cout << i + 1 << ". " << this->data[i] << endl;
}

