# **Data Structures in C++**
This repository contains robust implementations of fundamental data structures in C++, along with solutions to real-world scenario problems and practice questions curated from various competitive programming platforms and academic sources.

**Note:** Problem solutions do not include the full data structure implementations. To run them, you must download the required header files from the [Implementations](#implementations-section) section or folder and save them in the same directory as the solution file. The solutions are pre-linked to these files via #include statements.

## 🚀 Quick Navigation
Use the links below to jump to specific files:

### 🔍 Algorithms
- [**Linear search**](algorithms/linear-search.cpp)
- [**Binary Search**](algorithms/binary-search.cpp)
- [**Bubble Sorting**](algorithms/bubble-sorting.cpp)
- [**Selection Sorting**](algorithms/selection-sorting.cpp)

<a id="implementations-section"></a>
### 🛠 Implementations
*Core data structures implemented from scratch.*
- [**Stack** using Array](implementation%20of%20data%20structures/Stack/stack-array.h)
- [**Stack** using linked list](implementation%20of%20data%20structures/Stack/Stack-linkedList.h)
- [Shifted **Queue** using Array](implementation%20of%20data%20structures/Queue/queueShifted-array.h)
- [Circular **Queue** using Array](implementation%20of%20data%20structures/Queue/queueCircular-array.h)
- [**Queue** using linked list](implementation%20of%20data%20structures/Queue/queue-linkedList.h)
- [Singly **Linked List** using head pointer only](implementation%20of%20data%20structures/Linked%20List/singly%20linked%20list/linkedListHeadPTROnly-singly.h)
- [Singly circular **Linked List** using tail pointer only](implementation%20of%20data%20structures/Linked%20List/singly%20linked%20list/linkedListTailPTRonly-singly.h)
- [Singly **Linked List** using both head and tail pointer](implementation%20of%20data%20structures/Linked%20List/singly%20linked%20list/linkedList-singly.h)
- [Doubly **Linked List** using both head and tail pointer](implementation%20of%20data%20structures/Linked%20List/doubly%20linked%20list/linkedList-doubly.h)
- [Doubly **Linked List** using head pointer only](implementation%20of%20data%20structures/Linked%20List/doubly%20linked%20list/linkedListHeadPTROnly-doubly.h)
- [Doubly circular **Linked List** using tail pointer only](implementation%20of%20data%20structures/Linked%20List/doubly%20linked%20list/linkedListTailPTRonly-doubly.h)
- [Binary Search **Tree**](implementation%20of%20data%20structures/Trees/BST/BST.h)
- [RedBlack **Tree**](implementation%20of%20data%20structures/Trees/RedBlackTree/RBT.h)
- [min **Heap**](implementation%20of%20data%20structures/heap/minHeap.h)
- [max **Heap**](implementation%20of%20data%20structures/heap/maxHeap.h)

### 🧩 Problems

#### 📚 Stack Problems
| Problem Link | Description | Category |
| :--- | :--- | :--- |
| [Maze-Escape](scenario%20based%20questions/maze%20escape) | Find a path out of a grid-based maze | Scenario based Question |
| [Next greater element](scenario%20based%20questions/next_greater_element.cpp) | Find the first greater element to the right for each array element | Scenario based Question |
| [Infix to pre and post fix conversion](practice%20problems/infix%20conversion.cpp) | Convert standard infix expressions to prefix and postfix notations | Practice Questions |
| [Reverse Stack](practice%20problems/reverse%20stack.cpp) | Reverse the elements of a stack using recursion or auxiliary space | Practice Questions |
| [Prefix evaluation](practice%20problems/prefix_evaluation.cpp) | solve the given equation present in the Queue using prefix method  | Practice Qustions |
| []() |  |  |
| []() |  |  |

#### 👥 Queue Problems
| Problem Link | Description | Category |
| :--- | :--- | :--- |
| [TotalSum of min+max in SlidingWindow](scenario%20based%20questions/sliding_window_min_max.cpp) | Calculate the sum of minimum and maximum elements in every subarray of size k | Scenario based Question |
| [Airport security destribution](scenario%20based%20questions/airport_security_distribution.cpp) | distribute the load in different queues according to given condition | Scenarion based Question |
| [Remove dublication](practice%20problems/remove_duplicates_queue.cpp) | remove dublication from the queue while following the constrains | prctice problems |
| [Reverse Queeu](practice%20problems/reverse_queue.cpp) | reverse the queue by using only the memberfunctions of queue and two extra queue obj | Practice Questions |


#### 🔗 Linked List Problems
| Problem Link | Description | Category |
| :--- | :--- | :--- |
| [Multiplayer board game implementation](scenario%20based%20questions/multiplayer%20boardGame%20implementation) | Implement the simple game mechanics using doublyLL (based on both pointers) | Scenario based Question |
| [Song playlist manager](scenario%20based%20questions/song%20playlist%20manager) | Implement the song playlist manager using DoublyLL (based on both pointers) | Scenario based Question |
| [Movie watchList manager](scenario%20based%20questions/watchList%20manager) | Implement the movie watchlist manager using DoublyLL (based on both pointers) | Scenario based Question |
| [DeleteNode in O1](practice%20problems/delete_node_constant_time.cpp) | code a global function which removes node from the linked list in O1 time complexity | Practice problem |
| [PalindromeList using stack](practice%20problems/palindrome_usingLL_and%20_stack.cpp) | code a global function which finds the LL is palindrome uising stack and given LL | Practice problem |
| [Reverse LL in k-groups](practice%20problems/reverse%20LL%20K-groups.cpp) | Given the head of a linked list, reverse the nodes of the list $k$ at a time and return the modified list. If the number of nodes left is smaller than $k$, they are left as-is. | Practise problem
| [Lottery winner check](scenario%20based%20questions/lottery_winner_check.cpp) | find the lottery winner and there prize money according to the given conditions | Scenario based Questions |
| [Sort linkedlist](practice%20problems/sort_linked_list.cpp) | sort the linkedlist, using only member functions of LL and one extrea obj of the LL | Practice problems |


#### 🔄 Recursion Problems
| Problem Link | Description | Category |
| :--- | :--- | :--- |
| [String reverse recursively](practice%20problems/StringReverse-rec.cpp) | Reverse a string without using loops | Practice Question |
| [Palindrome recursively](practice%20problems/Palindrome-rec.cpp) | Check if a string reads the same backward as forward using recursion | Practice Questions |
| [LCM of numbers](practice%20problems/LCM%20of%20numbers%20-rec.cpp) | Find the Least Common Multiple of an array of numbers recursively | Practice Questions |
| [Factorial](practice%20problems/Factorial-rec.cpp) | Compute the factorial of a given number using a recursive base case | Practice Questions |
| [StairsClimb](scenario%20based%20questions/climbStairs-rec.cpp) | Count the distinct ways to reach the top of a staircase | Scenario based Questions |
| [Maze escape recursively](scenario%20based%20questions/mazeEscape-rec.cpp) | Solve a maze problem pathfinder logic using recursion back-tracking | Scenario based Questions |
| [Print LinkedList recursively](practice%20problems/printLinkedList-rec.cpp) | Traverse and display linked list elements using recursive calls | Practice Question |
| [CountDigits](practice%20problems/countDigits.cpp) | count the number of digits present in the value | Practice Questions |
| [Fibonacci sequence](practice%20problems/fibonacci%20series.cpp) | Function which finds sequence till n terms | Practice Questions |
| [Integer to binary conversion](practice%20problems/int%20to%20binary%20conversion.cpp) | convert integer value into binary |  Practice Questions |
| [Reverse of given numeber](practice%20problems/reverse%20of%20number.cpp) | Find the reverse of the given number | Practice Questions |
| [Sum of entred number](practice%20problems/sum%20of%20entred%20number.cpp) | find the sum of entred number digits | Practice Questions |
| [Sum of N natural number](practice%20problems/sum%20of%20n%20natural%20num.cpp) | find the sum of N natural numbers | Practice Quesitons |
| [Display LL reverse order](practice%20problems/display%20LL%20reverse%20order.cpp) | Code the recursive function and display the LL in reverse order | Practice Questions |
| [Create Subsets](practice%20problems/subsets.cpp) | Find the susets of the given array of numbers using backtrackng and recursion | Practice Questions |

## 🤝 How to Contribute
Contributions are welcome! If you want to add a new data structure or any practice question follow the given steps:
1. **Fork** the repository.
2. **Create** a new branch (`git checkout -b feature-new-solution`).
3. **Commit** your changes (`git commit -m 'Add new DS solution'`).
4. **Push** to the branch (`git push origin feature-new-solution`).
5. Open a **Pull Request**.

## 🐛 Bug Reporting
If there is any bug supported, please report it! You can do this by:
1. Navigating to the **Issues** tab.
2. Clicking on **New Issue**.
3. Describing the bug and providing the code snippet where it occurs.

### **Happy Coding!**
