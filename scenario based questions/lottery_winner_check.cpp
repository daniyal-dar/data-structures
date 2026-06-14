/*******************************************************************************
 * File: lottery_winner_check.cpp
 * Question: Lottery Ticket Prize Evaluator
 * * Problem Statement:
 * A game show stores each participant’s lottery ticket number in a singly linked
 * list, where each digit is placed in a separate node. For example, the ticket
 * number 1234 is represented as: 1 -> 2 -> 3 -> 4
 * * Prize Conditions (Corrected):
 * - Rs. 2000: The ticket number forms a palindrome.
 * - Rs. 1000: The ticket number has exactly 4 digits AND the sum of digits
 * is greater than or equal to 20 (>= 20).
 * - Rs. 3000: The ticket number forms a palindrome, has exactly 4 digits,
 * AND the sum of digits is greater than or equal to 20 (>= 20).
 * - Rs. 0   : If the ticket does not meet any of the prize criteria.
 * * Requirements:
 * - Implement the function: int checkIfWon(ticketLinkedList)
 * - The linked list is already created in main() and passed as a parameter.
 * - Head and tail pointers are private; you do not have direct access to them.
 * - You have access to the following pre-implemented member functions (do not
 * write their code): insertAtHead, insertAtTail, deleteFromHead,
 * deleteFromTail, isEmpty, createCopy.
 * * Examples:
 * - List: 4 -> 2 -> 1 -> 2 -> 4  | Output: 2000 (Palindrome only)
 * - List: 5 -> 6 -> 5 -> 7       | Output: 1000 (4 digits, sum = 23 > 20)
 * - List: 9 -> 1 -> 1 -> 9       | Output: 3000 (Palindrome, 4 digits, sum = 20)
 * - List: 2 -> 1 -> 1 -> 7 -> 1 -> 8 | Output: 0 (No match)
 *******************************************************************************/


#include"linkedList.h"
 // NOTE: This solution requires the dependency 'linkedList.h'. 
 // Please download and include the 'linkedList.h' header file from the 
 // implementation section to successfully compile this code.
#include<iostream>
using namespace std;

template < typename T>
int checkIfWon(LinkedList<T>& original)
{
	if (original.isEmpty())		// case 01: empty linked list
		return 0;

	bool isPalindrome = true;
	int digitsCount = 0;
	int sum = 0;

	while (!original.isEmpty())
	{
		T front = 0, rear = 0;
		bool pairedCheck = false;

		if (!original.isEmpty())
		{
			front = original.deleteFromHead();
			digitsCount++;						// counting digits
		}

		if(!original.isEmpty())
		{
			rear = original.deleteFromTail();
			digitsCount++;						// counting digits
			pairedCheck = true;
		}


		sum = sum + front + rear;				// finding sum of the linked list elements

		if (front != rear && pairedCheck)	// palindrome condition and last node case
			isPalindrome = false;
	}

	cout << "Is Palindrome: " << (isPalindrome ? "true" : "false") << endl
		<< "Sum: " << sum << endl
		<< "Digits Count: " << digitsCount << endl;

	if (isPalindrome && digitsCount == 4 && sum > 20)	// OR && sum >= 20 according to given example 3
		return 3000;
	else if (digitsCount == 4 && sum > 20)
		return 1000;
	else if (isPalindrome)
		return 2000;
	else
		return 0;
}

int main()
{
	int amount;

	LinkedList<int> ticketOne;
	ticketOne.insertAtTail(4);
	ticketOne.insertAtTail(2);
	ticketOne.insertAtTail(1);
	ticketOne.insertAtTail(2);
	ticketOne.insertAtTail(4);
	cout << "Original Ticket One:" << endl;
	ticketOne.display();
	amount = checkIfWon(ticketOne);
	cout << "Ticket One won Price: " << amount << endl << endl;

	LinkedList<int> ticketTwo;
	ticketTwo.insertAtTail(5);
	ticketTwo.insertAtTail(6);
	ticketTwo.insertAtTail(5);
	ticketTwo.insertAtTail(7);
	cout << "Original Ticket Two:" << endl;
	ticketTwo.display();
	amount = checkIfWon(ticketTwo);
	cout << "Ticket Two won Price: " << amount << endl << endl;

	LinkedList<int> ticketThree;
	ticketThree.insertAtTail(9);
	ticketThree.insertAtTail(1);
	ticketThree.insertAtTail(1);
	ticketThree.insertAtTail(9);
	cout << "Original Ticket Three:" << endl;
	ticketThree.display();
	amount = checkIfWon(ticketThree);
	cout << "Ticket Three won Price: " << amount << endl << endl;

	LinkedList<int> ticketFour;
	ticketFour.insertAtTail(2);
	ticketFour.insertAtTail(1);
	ticketFour.insertAtTail(1);
	ticketFour.insertAtTail(7);
	ticketFour.insertAtTail(1);
	ticketFour.insertAtTail(8);
	cout << "Original Ticket Four:" << endl;
	ticketFour.display();
	amount = checkIfWon(ticketFour);
	cout << "Ticket Four won Price: " << amount << endl << endl;

	LinkedList<int> ticketFive;
	ticketFive.insertAtTail(9);
	ticketFive.insertAtTail(21);
	ticketFive.insertAtTail(2);
	ticketFive.insertAtTail(9);
	cout << "Original Ticket Five:" << endl;
	ticketFive.display();
	amount = checkIfWon(ticketFive);
	cout << "Ticket Five won Price: " << amount << endl << endl;
}

