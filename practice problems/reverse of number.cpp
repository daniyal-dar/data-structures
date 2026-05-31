



// Description: This program calculates the reverse of an integer recursively
//              by passing the accumulated result as a function parameter,
//              avoiding the use of global variables.
//
// Scenario: Given an integer 'n', the function peels off the last digit via 
//           modulo (n % 10) and passes it down into a local tracking parameter 
//           ('rev'). The recursion ends when 'n' reaches 0, returning 'rev'.
//           Example: reverseNumber(123) -> reverseNumber(12, 3) -> 321.



#include <iostream>
using namespace std;


int reverseNumber(int n, int rev = 0) 
{
    // Base case: When there are no digits left, return the accumulated reverse
    if (n == 0) 
        return rev;

    // Isolate the last digit
    int lastDigit = n % 10;

    // Recursive case: Multiply the current reverse by 10, add the last digit,
    // and pass the remaining digits (n / 10) forward.
    return reverseNumber(n / 10, (rev * 10) + lastDigit);
}

int main() 
{
    int num1 = 123;
    int num2 = 4567;

    // You call it normally with just one argument, thanks to the default parameter (rev = 0)
    cout << "Original: " << num1 << " | Reversed: " << reverseNumber(num1) << endl
         << "Original: " << num2 << " | Reversed: " << reverseNumber(num2) << endl;

    return 0;
}