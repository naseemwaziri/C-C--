#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    int age;
    string address;
    double marks;

    void getData() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Marks: ";
        cin >> marks;
    }
    void displayData() {
        cout << "Student Information:" << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student students[15];

    for (int i = 0; i < 15; i++) {
        cout << "Enter details for Student " << i + 1 << ":" << endl;
        students[i].getData();
    }
    cout << "Student Details for 15 Students: " << endl;
    for (int i = 0; i < 15; i++) {
        students[i].displayData();
        cout << endl;
    }

    return 0;
}
