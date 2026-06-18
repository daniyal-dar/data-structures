#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class EmployeeManager {
private:
    // unordered_map storing unique integer employee IDs as keys and names as strings
    unordered_map<int, string> employeeDatabase;

public:
    EmployeeManager();                                                    // Default constructor
    void insertEmployee(int employeeId, string employeeName);             // Insert a new employee's ID and name into the map
    string searchEmployee(int employeeId);                                // Search for an employee's name given an ID
    void printAllEmployees();                                             // Print all employee IDs and their corresponding names
};


EmployeeManager::EmployeeManager() {}

void EmployeeManager::insertEmployee(int employeeId, string employeeName) 
{
    employeeDatabase[employeeId] = employeeName;            // Inserts or updates the key-value pairing efficiently
}


string EmployeeManager::searchEmployee(int employeeId) 
{
    // Use .find() to safely look up keys without accidentally auto-creating blank values
    auto iterator = employeeDatabase.find(employeeId);

    if (iterator != employeeDatabase.end()) 
    {
        // key found, return the name (stored in iterator->second)
        return iterator->second;
    }

    // key not found
    return "Employee not found";
}


void EmployeeManager::printAllEmployees() 
{
    if (employeeDatabase.empty()) 
    {
        cout << "Database is empty!" << endl;
        return;
    }

    // Traverse the map using a range-based loop
    // pair.first holds the ID (key), pair.second holds the Name (value)
    for (const auto& pair : employeeDatabase) 
    {
        cout << "Employee ID: " << pair.first << ", Name: " << pair.second << endl;
    }
}