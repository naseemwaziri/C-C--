#include <iostream>
using namespace std;
struct Student {
    int studentId;
    string name;
    int age;
    char grade;
};
void InputStudent(Student &student) {
    cout << "Enter Student ID: ";
    cin >> student.studentId;
    cin.ignore();
    cout << "Enter Name: ";
     cin >> student.name;
    cout << "Enter Age: ";
    cin >> student.age;
    cout << "Enter Grade: ";
    cin >> student.grade;
}
void PrintStudent( Student &student) {
    cout << "Student ID: " << student.studentId << endl;
    cout << "Name: " << student.name << endl;
    cout << "Age: " << student.age << endl;
    cout << "Grade: " << student.grade << endl;
    cout << endl;
}
void UpdateGrade(Student &student, char newGrade) {
    student.grade = newGrade;
}

int main() {
    const int numStudents = 3;
    Student students[numStudents];
        for (int i = 0; i < numStudents; i++) {
        cout << "Enter Student #" << i + 1 << " details:" << endl;
        InputStudent(students[i]);
    }
    cout << "Student Information:" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Student #" << i + 1 << ":" << endl;
        PrintStudent(students[i]);
    }
    for (int i = 0; i < numStudents; i++) {
        float newGrade;
        cout << "Enter new grade for Student #" << i + 1 << ": ";
        cin >> newGrade;
        UpdateGrade(students[i], newGrade);
    }
    cout << "Updated Student Information:" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Student #" << i + 1 << " (Updated):" << endl;
        PrintStudent(students[i]);
    }

    return 0;
}