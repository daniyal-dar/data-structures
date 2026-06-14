/*******************************************************************************
 * File: airport_security_distribution.cpp
 * Question: Airport Security Passenger Queue Distribution
 * * Problem Statement:
 * Passengers arriving at airport security form one long single queue, Q.
 * At the security checkpoint, four separate lanes/queues (q1, q2, q3, q4)
 * must be created for the security check. A passenger's lane is determined
 * by their passport number (integer) using specific divisibility rules.
 * * Distribution Rules:
 * - If passport number is divisible by 4:      Enters q4
 * - Else if passport number is divisible by 3: Enters q3
 * - Else if passport number is divisible by 2: Enters q2
 * - For all other cases:                       Enters q1
 * * Requirements:
 * - Write the logic inside the main() function to distribute all passengers
 * from Q into q1, q2, q3, and q4.
 * - At the end of execution, the original queue Q must be empty.
 * - Do not declare or implement the queues or their operations. They are
 * already instantiated and available for use via Q, q1, q2, q3, and q4.
 * - Available pre-implemented functions: enqueue, dequeue, peek, isEmpty,
 * isFull, createCopy.
 * * Example:
 * Initial State:
 * Q:  [12, 9, 5, 8, 7, 6, 3, 10] (where 12 is at the front)
 * Final State:
 * Q:  <empty>
 * q1: [5, 7]
 * q2: [10]
 * q3: [9, 6, 3]
 * q4: [12, 8]
 *******************************************************************************/

#include"Queue.h"
 // NOTE: This solution requires the dependency 'Queue.h'. 
 // Please download and include the 'Queue.h' header file from the 
 // implementation section to successfully compile this code.
#include<iostream>
using namespace std;


int main()
{
	Queue<int> passports(8);
	passports.enqueue(12);
	passports.enqueue(9);
	passports.enqueue(5);
	passports.enqueue(8);
	passports.enqueue(7);
	passports.enqueue(6);
	passports.enqueue(3);
	passports.enqueue(10);

	Queue<int> queue1(8);
	Queue<int> queue2(8);
	Queue<int> queue3(8);
	Queue<int> queue4(8);

	while (!passports.isEmpty())
	{
		int val = passports.dequeue();
		if (val % 4 == 0)
			queue4.enqueue(val);
		else if (val % 3 == 0)
			queue3.enqueue(val);
		else if (val % 2 == 0)
			queue2.enqueue(val);
		else
			queue1.enqueue(val);
	}

	cout << "Displaying all Queue after manipulation:--------------" << endl << endl;

	cout << "passports Queue" << endl;
	passports.display();
	cout << endl;

	cout << "Queue 1: " << endl;
	queue1.display();
	cout << endl;

	cout << "Queue 2: " << endl;
	queue2.display();
	cout << endl;

	cout << "Queue 3: " << endl;
	queue3.display();
	cout << endl;

	cout << "Queue 4: " << endl;
	queue4.display();

	return 0;
}

