
#include <iostream>
#include "BinarySearchTree.h"
#include "EmployeeInfo.h"

void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Add a new employee\n";
    std::cout << "2. Remove an employee\n";
    std::cout << "3. Search for an employee ID\n";
    std::cout << "4. Display all employees\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

void displayEmployee(EmployeeInfo& employee) {
    std::cout << "Employee ID: " << employee.id << ", Name: " << employee.name << std::endl;
}

int main() {
    BinarySearchTree<EmployeeInfo> tree;
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

    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
            case 1: {
                int id;
                std::string name;
                std::cout << "Enter Employee ID: ";
                std::cin >> id;
                std::cin.ignore(); // Ignore newline left in the input buffer
                std::cout << "Enter Name: ";
                std::getline(std::cin, name);
                EmployeeInfo newEmployee(id, name);
                tree.add(newEmployee);
                std::cout << "Employee added.\n";
                break;
            }
            case 2: {
                int id;
                std::cout << "Enter Employee ID to remove: ";
                std::cin >> id;
                try {
                    EmployeeInfo emp(id, "");
                    tree.remove(emp);
                    std::cout << "Employee removed.\n";
                } catch (NotFoundException& e) {
                    std::cout << e.what() << "\n";
                }
                break;
            }
            case 3: {
                int id;
                std::cout << "Enter Employee ID to search: ";
                std::cin >> id;
                try {
                    EmployeeInfo emp(id, "");
                    emp = tree.getEntry(emp);
                    std::cout << "Employee found: ";
                    displayEmployee(emp);
                } catch (NotFoundException& e) {
                    std::cout << e.what() << "\n";
                }
                break;
            }
            case 4: {
                tree.inorderTraverse(displayEmployee);
                break;
            }
            case 5: {
                std::cout << "Exiting program.\n";
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
