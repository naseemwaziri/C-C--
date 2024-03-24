#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    int age;

    void getdata() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
    }
    void displaydata() {
        cout << "Student Information:" << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    Student students[5];
    for (int i = 0; i < 5; i++) {
        cout << "Enter details for Student " << i + 1 << ":" << endl;
        students[i].getdata();
    }
    for (int i = 0; i < 5; i++) {
        if (students[i].rollNo == 2) {
            students[i].displaydata();
            break;
        }
    }

    return 0;
}
