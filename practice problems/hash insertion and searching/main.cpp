/***************************************************************************************
 * Accomplishments in this code:
 * 1. Modular Architecture: Split into separate .h, .cpp, and Task_1.cpp files[cite: 119, 121].
 * 2. Task 1 (Insertion): Built insertEmployee() to add data in average O(1) time[cite: 128, 130].
 * 3. Task 2 (Search): Built searchEmployee() using safe boundary checks (.find() and .end())
 *    to return the name or "Employee not found" without creating empty keys[cite: 131, 132, 133].
 * 4. Task 3 (Print): Built printAllEmployees() using an efficient 'const auto&'
 *    range-based for loop to display all records sequentially with std::endl[cite: 134].
 * 5. Formatting Style: Followed strict camelCase for variables/functions and PascalCase
 *    for classes with zero underscores per manual instructions[cite: 123, 124, 125, 126].
 ***************************************************************************************/

#include <iostream>
#include <string>
#include "EmployeeManager.h"

using namespace std;

int main() 
{
    EmployeeManager manager;

    cout << "--- Executing Task 1: Inserting Employees ---" << endl;
    manager.insertEmployee(1001, "Alice Smith");
    manager.insertEmployee(1002, "Bob Jones");
    manager.insertEmployee(1003, "Charlie Brown");
    manager.insertEmployee(1004, "Diana Prince");
    cout << "Data insertion completed successfully." << endl << endl;

    cout << "--- Executing Task 3: Printing Database Content ---" << endl;
    manager.printAllEmployees();
    cout << endl;

    cout << "--- Executing Task 2: Searching Database Records ---" << endl;
    int testId1 = 1002;
    int testId2 = 9999; // Non-existent key edge-case

    cout << "Searching ID " << testId1 << ": " << manager.searchEmployee(testId1) << endl;
    cout << "Searching ID " << testId2 << ": " << manager.searchEmployee(testId2) << endl;

    return 0;
}