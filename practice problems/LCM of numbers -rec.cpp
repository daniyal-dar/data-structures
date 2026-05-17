
/*
    The least common multiple (LCM) of two numbers is the smallest number that is a multiple 
    of both. Write and test a method LCM with the following specification.  
    PARAMETERS: positive integers j and k  
    RETURN VALUE: the least common multiple (LCM) of j and k   
    EXAMPLES: LCM (3, 5) is 15      LCM (6, 8) is 24  
*/

#include <iostream>
using namespace std;


int find_lcm_counter(int current_multiple, int step, int other_number) 
{
    // Base Case: If the current multiple is divisible by the other number
    if (current_multiple % other_number == 0)
        return current_multiple;

    // Recursive Logic: Increase the multiple by the step size and try again
    return find_lcm_counter(current_multiple + step, step, other_number);
}

int LCM(int j, int k) 
{
    if (j > k) 
        return find_lcm_counter(j, j, k);
    else
        return find_lcm_counter(k, k, j);
}

int main() 
{
    cout << "LCM(3, 5) is " << LCM(3, 5) << endl;
    cout << "LCM(6, 8) is " << LCM(6, 8) << endl;

    return 0;
}

