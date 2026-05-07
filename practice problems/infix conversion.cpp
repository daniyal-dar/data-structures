
// note* before compiling this code download and paste the stack-array
// header file in the same directory as this file
#include"stack-array.h"
#include<string>

char* convertToPrefix(char* infix);
char* convertToPostfix(char* infix);
void reverseAndFlip(char* arr, bool flipBrackets = true);
template<typename T>
void swapEle(T& a, T& b);
template<typename T>
void bracketReverse(T& c);
bool isOperator(const char c);
bool isOperand(const char c);
int getPrecedence(char c);
void display(char* arr);

int main()
{
	char expression[100];
	int choice;
	
	do {
		cout << "----Menu----" << endl
			<< "1. Convert to prefix." << endl
			<< "2. Convert to postfix." << endl
			<< "3. Exit." << endl
			<< "Enter your choice: ";
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
		switch (choice)
		{
		case 1:
		{
			cout << "Enter expression with brackets: ";
			cin.getline(expression, 100);
			char* prefix = convertToPrefix(expression);
			display(prefix);
			break;
		}
		case 2:
		{
			cout << "Enter expression with brackets: ";
			cin.getline(expression, 100);
			char* postfix = convertToPostfix(expression);
			display(postfix);
			break;
		}
		case 3:
			cout << "Terminating program!" << endl << endl;
			break;
		default:
			cout << "Invalid input!" << endl << endl;
		}
		} while (choice != 3);
		return 0;
}
	char* convertToPrefix(char* infix)
{
	reverseAndFlip(infix, true);
	char* prefix = convertToPostfix(infix);
	reverseAndFlip(prefix, false);
	return prefix;
}
	char* convertToPostfix(char* infix)
{
	int length = strlen(infix);
	Stack<char> s(length);
	// Allocate extra space for delimiters (spaces)
	char* postfix = new char[length * 2 + 1];
	int index = 0;
	for (int i = 0; i < length; i++)
	{
		char c = infix[i];
		if (c == ' ') 
			continue;
			// 1. Multi-figure Operand logic
		if (isOperand(c))
		{
			while (i < length && isOperand(infix[i]))
			{
				postfix[index++] = infix[i++];
			}
			postfix[index++] = ' '; // Delimiter
			i--; // Adjust for loop increment
		}
			// 2. Handle Opening Bracket
		else if (c == '(')
			s.push(c);
			// 3. Handle Closing Bracket
		else if (c == ')')
		{
			while (!s.isEmpty() && s.top() != '(')
			{
				postfix[index++] = s.pop();
				postfix[index++] = ' ';
			}
			if (!s.isEmpty()) s.pop(); // Pop '('
		}
		// 4. Operator logic with Precedence
		else if (isOperator(c))
		{
			while (!s.isEmpty() && s.top() != '(' && getPrecedence(s.top()) > getPrecedence(c))
			{
				postfix[index++] = s.pop();
				postfix[index++] = ' ';
			}
			s.push(c);
		}
	}
		// 5. Pop remaining operators
	while (!s.isEmpty())
	{
		postfix[index++] = s.pop();
		postfix[index++] = ' ';
	}
		// Remove the very last trailing space if it exists
	if (index > 0 && postfix[index - 1] == ' ') 
		index--;
		postfix[index] = '\0';
	return postfix;
}
	void display(char* arr)
{
	for (int i = 0;i < strlen(arr);i++)
		cout << arr[i];
		cout << endl << endl;
}
	// HELPING FUNCTIONS ----------------------------
	void reverseAndFlip(char* arr, bool flipBrackets)
{
	int size = strlen(arr);
	int i = 0, j = size - 1;
	for (; i < size / 2; i++, j--)
	{
		swapEle(arr[i], arr[j]);
		if (flipBrackets) 
		{
			bracketReverse(arr[i]);
			bracketReverse(arr[j]);
		}
	}

		if (size % 2 != 0 && flipBrackets)
			bracketReverse(arr[i]);
}

template<typename T>
void swapEle(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void bracketReverse(T& c)
{
	if (c == '(')
	c = ')';
	else if (c == ')')
		c = '(';
}

bool isOperator(const char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}


bool isOperand(const char c)	
{
	if (c >= '0' && c <= '9')
		return true;
	if (c >= 'A' && c <= 'Z')
		return true;
	if (c >= 'a' && c <= 'z')
		return true;
	return false;
}

int getPrecedence(char c) 
{
	if (c == '+' || c == '-') 
		return 1;
	if (c == '*' || c == '/') 
		return 2;
	if (c == '^') 
		return 3;
	return 0;
}