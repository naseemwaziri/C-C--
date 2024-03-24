#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string name;
    int id;
    double salary;

    void displayEmployeeInfo() {
        cout << "Employee Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Employee employee;
    
    cout << "Enter Employee Name: ";
    getline(cin, employee.name);
    cout << "Enter Employee ID: ";
    cin >> employee.id;
    cout << "Enter Employee Salary: ";
    cin >> employee.salary;
    employee.displayEmployeeInfo();

    return 0;
}
