
/*
    In real life, consider a staircase with n steps. A person standing at the bottom can climb 
    the staircase by taking either 1 step or 2 steps at a time. For example, if the staircase 
    has 3 steps, the person can reach the top in 3 different ways: (1+1+1), (1+2), or (2+1).
    Your task is to write a recursive function in C++ that calculates the total number of 
    distinct ways to climb to the top of a staircase of size n. The recursive relation can be 
    defined as:
•	If there are 0 steps, there is only 1 way (doing nothing).
•	If there is 1 step, there is only 1 way (a single step).
•	For any n > 1, the number of ways to climb n steps is the sum of the ways to climb 
    n-1 steps and n-2 steps, because the last move could have been either a single step 
    or a double step.

This recursive problem is a classic example of how complex scenarios can be broken down into 
smaller subproblems. It also builds a strong foundation for understanding dynamic programming 
concepts, as the recursive approach generates overlapping subproblems that can be optimized later.
ExampleInput:n=4
Example Output: 5 

*/

#include <iostream>
using namespace std;

int climbStairs(int n) 
{
    // Base Cases
    if (n == 0) 
        return 1;

    if (n == 1)
        return 1;

    // Recursive Logic
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main() 
{
    cout << "Total distinct ways to climb 4 steps: " << climbStairs(4) << endl;
    cout << "Total distinct ways to climb 3 steps: " << climbStairs(3) << endl;

    return 0;
}

