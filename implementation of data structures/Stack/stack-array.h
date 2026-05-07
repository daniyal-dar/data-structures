

// this header file contains the generic implementation of LIFO Stack using array 

#pragma once
#include<iostream>
using namespace std;

template<class T>
class Stack
{
private:
	T* data;						// dynamic array
	int current_size;				// holds the current size of the array
	int max_size;					// holds the max size of array

public:
	Stack(const int size);			// default constructor
	~Stack();						// destructor
	bool isEmpty();					// check is stack empty
	bool isFull();					// check is stack full 
	T top();						// returns recent value added in the stack
	void push(const T value);		// add values in stack 
	T pop();						// removes recent added value from stack
	void display();					// displays stack

	//-------------------------------------------------------------------------
	// operator overloading is not necessory but it helps to simplify code 
	// while dealing with scenario based questions
	template <class T>
	friend ostream& operator<<(ostream& output, const Stack<T>& obj);
};

template<class  T>
Stack<T>::Stack(const int size)
{
	current_size = 0;
	max_size = size;
	data = new T[size];
}

template<class T>
Stack<T>::~Stack()
{
	delete[] data;
	data = nullptr;
}

template<class  T>
bool Stack<T>::isEmpty() { return this->current_size == 0; }

template<class  T>
bool Stack<T>::isFull() { return this->current_size == this->max_size; }

template<class  T>
T Stack<T>::top()
{
	if (isEmpty())
	{
		cout << "Stack is empty! Nothing to see." << endl;
		return T();
	}

	return this->data[this->current_size - 1];
}

template<class  T>
void Stack<T>::push(const T value)
{
	if (!isFull())
	{
		this->data[this->current_size] = value;
		this->current_size++;
	}
	else
		cout << "Stack is full! operation terminatied." << endl;
}

template<class  T>
T Stack<T>::pop()
{
	if (!isEmpty())
	{
		this->current_size--;
		return this->data[this->current_size];
	}
	else
	{
		cout << "Stack is empty! operation terminated." << endl;
		return T();
	}
}

template<class  T>
void Stack<T>::display()
{
	cout << "Current Size: " << this->current_size << endl
		<< "Max Size: " << this->max_size << endl;
	for (int i = 0;i < this->current_size;i++)
		cout << i + 1 << ". " << this->data[i] << endl;
}


template<class  T>
ostream& operator<<(ostream& output, const Stack<T>& obj)
{
	for (int i = 0;i < obj.current_size;i++)
		output << obj.data[i] << " ";
	return output;
}