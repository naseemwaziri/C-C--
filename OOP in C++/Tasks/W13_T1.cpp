#include <iostream>
using namespace std;

class Employee
{   
    public:
    int id;
    string name;
    string position;
    double salary;

    Employee(int id, string name, string position, double salary) : id(id), name(name), position(position), salary(salary) {}

};

class Department
{   
    public:
    string name;
    Employee **employees;
    int employeeCount;

    public:
    Department(string name) : name(name), employeeCount(0) {
        employees = new Employee*[100];
    }

    void add_employee(Employee* employee) {
        if (employeeCount >= 100) {
            cout << "Cannot add more employees" << endl;
            return;
        }
        employees[employeeCount] = employee;
        ++employeeCount;
    }


    void search_employee(int employee_id) {
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i]->id == employee_id) {
            cout << "Employee found: " << employees[i]->name << endl;
            return;
        }
    }
    cout << "Employee not found" << endl;
}


    double calculate_total_salary() {
        double total_salary = 0;
        for (int i = 0; i < employeeCount; i++) {
            total_salary += employees[i]->salary;
        }
        return total_salary;
    }
    
};


int main(){

    Department department("Science");

    department.add_employee(new Employee(1, "Ahmad", "Teacher", 50000));
    department.add_employee(new Employee(2, "Ali", "Teacher", 60000));

    department.search_employee(2);

    cout << "Total salary: " << department.calculate_total_salary() << endl;

    return 0;
}