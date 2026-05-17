
/*
	A palindrome is a word, phrase, or number that reads the same forwards and backwards, 
	such as "MADAM" or "LEVEL". Your task is to write a recursive function in C++ to check 
	whether a given string is a palindrome. The function should compare the first and last 
	characters, and if they match, recursively check the substring in between. If a mismatch 
	is found, the function should immediately return false. For example, the input "MADAM" 
	should return "Palindrome", whereas the input "HELLO" should return "Not a Palindrome".
	This task emphasizes how recursion is naturally suited for problems involving repeated 
	comparisons from both ends toward the center.
*/


#include<iostream>
using namespace std;

template <typename T>
bool check(T a, T b)
{
	return a == b;
}

bool palindrome(string& str, int i=0)
{
	bool status = false;
	int n = str.length();

	if (i >= n / 2) return true;
	
	if (!check<char>(str[i], str[n - 1 - i]))
		return false;

	return palindrome(str, i + 1);
}

int main()
{
	string str = "LEVEL";

	cout << "Status: " << (palindrome(str) ? "Palindrome" : "Not Palindrome") << endl;

	return 0;
}

