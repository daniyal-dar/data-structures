


// Description: This program generates and prints the Fibonacci sequence 
//              up to 'n' terms using a recursive approach.
//
// Scenario: The program uses a core recursive function to find the Nth 
//           Fibonacci number (Fib(n) = Fib(n-1) + Fib(n-2)). It pairs this with 
//           a helper function that recursively loops from 0 up to n-1 to 
//           print the sequence in chronological order.
//           Example: n = 5 -> 0 1 1 2 3



#include <iostream>
using namespace std;


int fibonacci(int n) 
{
    // Base cases: 0th term is 0, 1st term is 1
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Recursive case: Sum of the two previous terms
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Helper recursive function to iterate and print from 0 up to n-1
void printSequence(int n, int current = 0) 
{
    // Base case: Stop when we have printed 'n' terms
    if (current == n)
        return;

    // Print the Fibonacci number at the 'current' index
    cout << fibonacci(current) << " ";

    // Recursive step: Move to the next term
    printSequence(n, current + 1);
}

int main() 
{
    int terms1 = 5;
    int terms2 = 10;

    cout << "Fibonacci sequence of " << terms1 << " terms: " << endl;
    printSequence(terms1);
    cout << endl << endl;

    cout << "Fibonacci sequence of " << terms2 << " terms: " << endl;
    printSequence(terms2);
    cout << endl;

    return 0;
}

