


// Description: This program calculates the sum of all digits in an integer
//              using a recursive approach. It manually handles negative numbers
//              and extracts digits without relying on external math libraries.
//
// Scenario: Given an integer 'n' (e.g., 123), the program extracts the last 
//           digit using the modulo operator (n % 10) and adds it to the 
//           recursive sum of the remaining digits (n / 10) until a single-digit 
//           base case is reached.
//           Example: 123 -> 3 + 2 + 1 = 6.

#include <iostream>
using namespace std;

int sumDigits(int n) 
{
    // Handle negative numbers manually
    if (n < 0)
        n = -n;

    // Base case: If the number is a single digit, the sum is the number itself
    if (n < 10)
        return n;

    // Recursive case: Add the last digit (n % 10) to the sum of the remaining digits (n / 10)
    return (n % 10) + sumDigits(n / 10);
}

int main() 
{
    int num1 = 123;
    int num2 = 4567;
    int num3 = -98;

    cout << "Sum of digits in " << num1 << " is: " << sumDigits(num1) << endl
         << "Sum of digits in " << num2 << " is: " << sumDigits(num2) << endl
         << "Sum of digits in " << num3 << " is: " << sumDigits(num3) << endl;

    return 0;
}

