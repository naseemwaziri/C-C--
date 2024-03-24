#include <iostream>
using namespace std;

// Define the Employee structure
struct Employee {
    int employeeID;
    string name;
    string position;
    double salary;
};

void inputEmployeeData(Employee &employee) {
    cout << "Enter Employee ID: ";
    cin >> employee.employeeID;
    cin.ignore(); 
    cout << "Enter Name: ";
    getline(cin, employee.name);
    cout << "Enter Position: ";
    getline(cin, employee.position);
    cout << "Enter Salary: ";
    cin >> employee.salary;
}

void displayEmployeeData(const Employee &employee) {
    cout << "Employee ID: " << employee.employeeID << endl;
    cout << "Name: " << employee.name << endl;
    cout << "Position: " << employee.position << endl;
    cout << "Salary: $" << employee.salary << endl;
    cout << endl;
}

int main() {
    const int numEmployees = 5; // You can adjust the number of employees as needed
    Employee employees[numEmployees];

    // Input data for multiple employees
    for (int i = 0; i < numEmployees; i++) {
        cout << "Enter Employee #" << i + 1 << " details:" << endl;
        inputEmployeeData(employees[i]);
    }

    // Display data for all employees
    cout << "Employee Information:" << endl;
    for (int i = 0; i < numEmployees; i++) {
        cout << "Employee #" << i + 1 << ":" << endl;
        displayEmployeeData(employees[i]);
    }

    return 0;
}
