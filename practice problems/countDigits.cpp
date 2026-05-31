

// Description: This program calculates the total number of digits in an integer
//              using a recursive approach. It manually handles negative numbers
//              and zero without relying on external libraries like <cmath>.
//
// Scenario: Given an integer 'n', the program repeatedly peels off the last 
//           digit using integer division (n / 10) and adds 1 to the recursive 
//           count until a single-digit base case (n < 10) is reached.


#include <iostream>
using namespace std;

int countDigits(int n) 
{
    // Handle negative numbers manually without <cmath>
    if (n < 0) 
        n = -n;

    // Base case: If the number is a single digit (0-9)
    if (n < 10) 
        return 1;

    // Recursive case: Remove the last digit and add 1
    return 1 + countDigits(n / 10);
}

int main() 
{
    int num1 = 24680;
    int num2 = -1357;
    int num3 = 0;

    cout << "Number of digits in " << num1 << " is: " << countDigits(num1) << endl
         << "Number of digits in " << num2 << " is: " << countDigits(num2) << endl
         << "Number of digits in " << num3 << " is: " << countDigits(num3) << endl;

    return 0;
}

