/*
================================================================================
File: reverse_queue.cpp
Question : Queue Reversal with Constraints
================================================================================
Problem Statement :
You are given a queue Q containing integers.Your task is to reverse the
contents of Q.

Constraints :
	-You are ONLY allowed to use standard queue operations(e.g., enqueue,
		dequeue, isEmpty, front, size).
	- You are strictly FORBIDDEN from using a stack or recursion.
	- You may instantiate and use additional queue objects if required.

Input Example :
Q = [1, 2, 3, 4, 5]

Output Example :
Q = [5, 4, 3, 2, 1]
================================================================================
*/


#include"Queue.h"
// NOTE: This solution requires the dependency 'Queue.h'. 
// Please download and include the 'Queue.h' header file from the 
// implementation section to successfully compile this code.

template<class T>
bool reverseQueue(Queue<T>& original, int size)
{
	Queue<T> temp1(size);
	Queue<T> temp2(size);

	if (original.isEmpty())
		return false;

	// moving all the elements from original Queue to temp1
	while (!original.isEmpty())
	{
		temp1.enqueue(original.dequeue());
	}

	// applying reverse logic
	while (!temp1.isEmpty())
	{
		// moving elements from temp1 to temp2 
		while (!temp1.isEmpty())
		{
			T val = temp1.dequeue();
			// check is dequeued val is last element in queue
			if (temp1.isEmpty())
				original.enqueue(val);
			else
				temp2.enqueue(val);
		}

		// moving elements from temp2 to temp1
		while (!temp2.isEmpty())
		{
			T val = temp2.dequeue();
			// check is dequeued val is last element in queue
			if (temp2.isEmpty())
				original.enqueue(val);
			else
				temp1.enqueue(val);
		}
	}

	return true;
}

int main()
{
	const int size = 15;
	Queue<int> obj(size);
	obj.enqueue(1);
	obj.enqueue(2);
	obj.enqueue(3);
	obj.enqueue(4);
	obj.enqueue(5);
	obj.enqueue(6);
	cout << "Original Queue: ";
	obj.display();

	reverseQueue(obj, size);

	cout << "Reversed Queue: ";
	obj.display();


	return 0;
}

