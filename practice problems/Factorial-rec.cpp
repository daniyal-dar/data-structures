/*
	Write  In mathematics and computer science, factorials are widely used in probability,
	combinatorics, and algorithm design. Your task is to implement a recursive function in C++
	that calculates the factorial of a given number n. The factorial of n is defined as the
	product of all positive integers less than or equal to n, with the base case being 0! = 1.
	For example, if the input is 5, the recursive function should compute
	5 × 4 × 3 × 2 × 1 = 120 and return the result. This task will help you practice breaking
	down a large computation into smaller, repeated problems using recursion.
*/

#include<iostream>
using namespace std;

int factorial(int n)
{
	if (n == 0) return 1;
	else return n * factorial(n - 1);
}

int main()
{
	int n;
	cout << "Enter number for factorial: ";
	cin >> n;

	cout << "Result: " << factorial(n) << endl;

	return 0;
}

