// Define a C++ structure for a student, containing the following members: name, ID, and GPA.
// Write a function that takes an array of student structures and returns the index of the student with the highest GPA.
#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    string ID;
    double GPA;
};
int find_max_GPA_index(Student students[], int size){
    int max_index = 0;
    double maxindex = students[0].GPA;

    for(int i = 1; i < size; i++){
        if(students[i].GPA > max_index){
            max_index = students[i].GPA;
            max_index = i;
        }
    }
    return max_index;
}

int main(){
    int SIZE = 3;
    Student students[SIZE];
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter the name of student " << i + 1 << ": ";
        cin >> students[i].name;
        cout << "Enter the ID of student " << i + 1 << ": ";
        cin >> students[i].ID;
        cout << "Enter the GPA of student " << i + 1 << ": ";
        cin >> students[i].GPA;
    }
    int index = find_max_GPA_index(students, SIZE);
    cout << "The student with the highest GPA is: " << students[index].name << " with ID " << students[index].ID << endl;
    return 0;
}