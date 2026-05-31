


// Description: This program calculates the sum of the first 'n' natural numbers
//              using a recursive approach.
//
// Scenario: Given a positive integer 'n', the program recursively breaks down
//           the problem into (n + sum(n - 1)) until it reaches the base case
//           where n equals 1.
//           Example: If n = 4, sum = 4 + 3 + 2 + 1 = 10.



#include <iostream>
using namespace std;

int sumOfNaturalNumbers(int n) 
{
    // Base case: The sum of the first 1 natural number is 1
    if (n <= 1) 
        return 1;

    // Recursive case: n + sum of first (n - 1) numbers
    return n + sumOfNaturalNumbers(n - 1);
}

int main() 
{
    int n1 = 4;
    int n2 = 10;
    int n3 = 100;

    cout << "Sum of first " << n1 << " natural numbers is: " << sumOfNaturalNumbers(n1) << endl
         << "Sum of first " << n2 << " natural numbers is: " << sumOfNaturalNumbers(n2) << endl
         << "Sum of first " << n3 << " natural numbers is: " << sumOfNaturalNumbers(n3) << endl;

    return 0;
}

