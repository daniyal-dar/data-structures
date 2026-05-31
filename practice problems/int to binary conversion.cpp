


// Description: This program displays the binary representation of a decimal 
//              number using a recursive approach.
//
// Scenario: Given an integer 'n', the program recursively divides 'n' by 2 
//           to process higher-order bits first. As the recursion unwinds, 
//           it prints the remainders (n % 2) from left to right, creating 
//           the final binary string.



#include <iostream>
using namespace std;

void printBinary(int n) 
{
    // Handle negative numbers (displays the binary of its absolute value)
    if (n < 0) 
    {
       cout << "-";
        n = -n;
    }

    // Base case: If the number is 0 or 1, print it directly
    if (n <= 1) 
    {
        cout << n;
        return;
    }

    // Recursive case: Process the rest of the number first
    printBinary(n / 2);

    // Print the remainder as the recursion unwinds
    cout << (n % 2);
}

int main() 
{
    int num1 = 13;
    int num2 = 45;
    int num3 = 0;

    cout << "Binary of " << num1 << " is: ";
    printBinary(num1);
    cout << endl;

    cout << "Binary of " << num2 << " is: ";
    printBinary(num2);
    cout << endl;

    cout << "Binary of " << num3 << " is: ";
    printBinary(num3);
    cout << endl;

    return 0;
}

