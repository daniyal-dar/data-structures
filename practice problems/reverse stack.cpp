// ------------------------------------------------------
// you have a stack in main. code a reverse function which accepts the obj of 
// stack and reverse the stack content where you are only allowed to use the stack
// data structure and its member functions, use outside the class approch for this problem.
// ------------------------------------------------------


// note* download the stack-array.h header file from the project and 
// include it in this file to run the code successfully.

#include"stack-array.h"
template<typename T>
void reverseStack(Stack<T>& original, const int size)
{
	Stack<T> temp1(size);
	Stack<T> temp2(size);

	// storing in reverse order in temp1 stack
	while (!original.isEmpty())
		temp1.push(original.pop());
		
	// storing in original order in temp2 stack
	while (!temp1.isEmpty())
		temp2.push(temp1.pop());

	// storing in reverse order in original stack
	while (!temp2.isEmpty())
		original.push(temp2.pop());
}

int main()
{
	const int size = 5;
	Stack<char> original(size);
	for (int i = 0; i < 5; i++)		// pushing data in stack
		original.push('A' + i);

	cout << "Before reverse: " << original << endl;

	reverseStack<char>(original, size);

	cout << "After reverse: " << original << endl;

	return 0;
}
