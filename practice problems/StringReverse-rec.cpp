
/*
	Reversing a string is a common operation in text processing, and recursion offers an 
	elegant way to solve it. Your task is to write a recursive function in C++ that reverses 
	a given string without using loops or built-in reverse functions. The function should swap 
	the first and last character of the string, then recursively reverse the remaining substring.
	For example, the input "HELLO" should produce the output "OLLEH". This task will help you 
	understand how recursion can be used to manipulate strings by focusing on base cases and 
	combining results from smaller subproblems.
*/

#include <iostream>
using namespace std;

void swap(char &a, char &b)
{
	char temp = a;
	a = b;
	b = temp;
}

void reverse(string &str, int i = 0)
{
	int n = str.length();
	if (i >= n / 2)
		return;
	swap(str[i], str[n - 1 - i]);
	reverse(str, i + 1);
}

int main()
{
	string str = "HELLO";
	cout << "Before reverse: " << str << endl;

	reverse(str);

	cout << "After reverse: " << str << endl;
	return 0;
}
