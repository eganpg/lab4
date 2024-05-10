
#ifndef EMPLOYEE_INFO_H
#define EMPLOYEE_INFO_H

#include <string>

// Class to store employee information
class EmployeeInfo {
public:
    int id; // Employee ID Number
    std::string name; // Employee Name

    // Default constructor initializes an employee with ID as 0 and name as an empty string.
    EmployeeInfo() : id(0), name("") {}

    // Parameterized constructor to initialize an employee with a specific ID and name.
    EmployeeInfo(int id, std::string name) : id(id), name(name) {}

    // Overloads the less than operator to compare employees based on their ID.
    // Returns true if this employee's ID is less than the other employee's ID.
    bool operator<(const EmployeeInfo& rhs) const {
        return this->id < rhs.id;
    }

    // Overloads the greater than operator to compare employees based on their ID.
    // Returns true if this employee's ID is greater than the other employee's ID.
    bool operator>(const EmployeeInfo& rhs) const {
        return this->id > rhs.id;
    }
    
    // Overloads the equality operator to compare employees based on their ID.
    // Returns true if this employee's ID is equal to the other employee's ID.
    bool operator==(const EmployeeInfo& rhs) const {
        return this->id == rhs.id;
    }
};

#endif
