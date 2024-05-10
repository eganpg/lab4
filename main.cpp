/**
 * Employee Management System using Binary Search Tree
 * 
 * This program implements an employee management system using a binary search tree
 * to store and manipulate employee data. It provides functionalities for adding,
 * removing, searching for, and displaying employee information based on their ID numbers.
 * 
 * The system uses the EmployeeInfo class to represent individual employee data,
 * including the employee's ID and name. The BinarySearchTree class is utilized to
 * manage these EmployeeInfo instances in a binary search tree structure, allowing
 * efficient data management operations such as insertion, deletion, and search.
 * 
 * The user interacts with the system through a console-based menu that offers options
 * to add a new employee, remove an existing employee, search for an employee by ID,
 * display all employees, and exit the program. Exception handling is incorporated to
 * manage scenarios where operations may fail, such as removing a non-existent employee.
 * 
 * Detailed comments within the code explain the functionality of each segment, ensuring
 * readability and maintainability.
 */


#include <iostream>
#include "BinarySearchTree.h"
#include "EmployeeInfo.h"

// Function to display menu
void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Add a new employee\n";
    std::cout << "2. Remove an employee\n";
    std::cout << "3. Search for an employee ID\n";
    std::cout << "4. Display all employees\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

// Function to display employee information
void displayEmployee(EmployeeInfo& employee) {
    std::cout << "Employee ID: " << employee.id << ", Name: " << employee.name << std::endl;
}

// Main function where program execution starts
int main() {
    // Create a binary search tree to store EmployeeInfo objects
    BinarySearchTree<EmployeeInfo> tree;
    // Predefined list of employees to add to the binary search tree
    EmployeeInfo employees[] = {
        {6702, "James B W Bevis"}, {1255, "Romney Wordsworth"}, {1071, "Revis Jacara"},
        {2390, "Clegg Forbes"}, {1558, "Kalin Tros"}, {7406, "Archibald Beechcroft"},
        {7562, "Penthor Mul"}, {3004, "Bartlet Finchley"}, {4922, "Latham Bine"},
        {8483, "Jeff Myrtlebank"}
    };

    // Insert all employees into the tree
    for (auto& emp : employees) {
        tree.add(emp);
    }
    // Variable to store the user's menu choice
    int choice;
    do {
        displayMenu(); // Display the menu options
        std::cin >> choice; // Read the user's choice
        switch (choice) {
            // Add a new employee
            case 1: {
                int id;
                std::string name;
                std::cout << "Enter Employee ID: ";
                std::cin >> id;
                // Ignore newline left in the input buffer
                std::cin.ignore(); 
                std::cout << "Enter Name: ";
                std::getline(std::cin, name);
                EmployeeInfo newEmployee(id, name);
                // Add the new employee to the tree
                tree.add(newEmployee);
                std::cout << "Employee added.\n";
                break;
            }
            // Remove an employee
            case 2: {
                int id;
                std::cout << "Enter Employee ID to remove: ";
                std::cin >> id;
                try {
                    // Create an employee to use as key for removal
                    EmployeeInfo emp(id, "");
                    // Attempt to remove the employee
                    tree.remove(emp);
                    std::cout << "Employee removed.\n";
                    // Employee not found
                } catch (NotFoundException& e) {
                    std::cout << e.what() << "\n";
                }
                break;
            }
            // Search for an employee by ID
            case 3: {
                int id;
                std::cout << "Enter Employee ID to search: ";
                std::cin >> id;
                try {
                    // Create an employee to use as a search key
                    EmployeeInfo emp(id, ""); 
                    // Attempt to find the employee
                    emp = tree.getEntry(emp);
                    std::cout << "Employee found: ";
                    // Display found employee's details
                    displayEmployee(emp);
                    // Execption if employee is not found
                } catch (NotFoundException& e) {
                    std::cout << e.what() << "\n";
                }
                break;
            }
            // Display all employees
            case 4: {
                tree.inorderTraverse(displayEmployee);
                break;
            }
            // Exit program
            case 5: {
                std::cout << "Exiting program.\n";
                break;
            }
            // Invalid choice
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
