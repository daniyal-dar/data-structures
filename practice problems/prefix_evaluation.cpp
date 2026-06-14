
/*******************************************************************************
 * File: prefix_evaluation.cpp
 * Question: Prefix Expression Evaluation Using Queue and Stack
 * * Problem Statement:
 * In a programming system, prefix expressions (operators first, operands second)
 * are evaluated using a stack. The values (both operators and operands) are
 * already placed in a queue from left to right, following prefix order.
 * * Data Mappings:
 * - Positive Integer: Operand (multi-digit allowed)
 * - Negative Integer: Operator according to the following mapping:
 * o -1 represents PLUS (+)
 * o -2 represents MULTIPLY (*)
 * o -3 represents DIVIDE (/) [Integer division, quotient only]
 * * Requirements:
 * - Read elements from the queue one-by-one and use a stack to evaluate the
 * expression in main().
 * - At the end of execution, the stack must contain exactly one value, which
 * is the final result.
 * - Do not implement helper functions like enqueue, dequeue, push, pop, etc.
 * Assume they are already available for use.
 * * Hint:
 * When the top stack values follow the pattern [operator, operand, operand]
 * (or as elements are processed), pop them, evaluate the result, and push it back.
 * * Example 1:
 * Queue contents: [-3, -2, 7, 3, 2]
 * Evaluation Steps:
 * Step 0: Queue: [-3, -2, 7, 3, 2]  Stack: []
 * Step 1: Queue: [-2, 7, 3, 2]      Stack: [-3]
 * Step 2: Queue: [7, 3, 2]          Stack: [-3, -2]
 * Step 3: Queue: [3, 2]             Stack: [-3, -2, 7]
 * Step 4: Queue: [2]                Stack: [-3, -2, 7, 3]
 * Step 5: Queue: [2]                Stack: [-3, 21]       // 7 * 3 = 21
 * Step 6: Queue: []                 Stack: [-3, 21, 2]
 * Step 7: Queue: []                 Stack: [10]           // 21 / 2 = 10
 * Result stored in stack: 10
 * * Example 2:
 * Queue contents: [-1, 5, -2, 2, 3]
 * Result stored in stack: 11
 *******************************************************************************/

#include "Queue.h"
#include "stack.h"
#include <iostream>
using namespace std;

// NOTE: This solution requires the dependency 'Queue.h' and 'stack.h'. 
// Please download and include the 'Queue.h' and 'stack.h' header file from the 
// implementation section to successfully compile this code.

int main()
{
    const int size = 10;
    Stack<int> s(size);
    Queue<int> q(size);
    q.enqueue(-1);
    q.enqueue(5);
    q.enqueue(-2);
    q.enqueue(2);
    q.enqueue(3);

    while (!q.isEmpty())        // loops until queue gets empty
    {
        int current = q.dequeue();
        s.push(current);

        while (s.getSize() >= 3) // loops until stack contains equal or more then 3 values
        {
            int right = s.pop();       
            int left = s.pop();        
            int op = s.pop();

            if (left > 0 && right > 0 && op < 0)    // data validation check
            {
                int result = 0;

                switch (op)
                {
                case -1:
                    result = left + right;
                    break;
                case -2:
                    result = left * right;
                    break;
                case -3:
                    result = left / right;
                    break;
                default:
                    cout << "invalud operator found!" << endl;
                }
                s.push(result);
            }
            else
            {
                s.push(op);
                s.push(left);
                s.push(right);
                break;
            }
        }
    }

    if (s.getSize() == 1)
        cout << "Result stored in stack: " << s.top() << endl;
    else
        cout << "Error: Invalid expression, stack size = " << s.getSize() << endl;

    return 0;
}

