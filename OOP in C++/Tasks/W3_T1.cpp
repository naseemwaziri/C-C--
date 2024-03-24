#include <iostream>
using namespace std;

struct Student
{
    string name;
    int rollno;
    float age;
    float marks;
};

int main(){
    Student s;

    cout<<"Enter full name: ";
    getline(cin, s.name);
    cout<<"Enter roll no: ";
    cin>>s.rollno;
    cout<<"Enter age: ";
    cin>>s.age;
    cout<<"Enter marks: ";
    cin>>s.marks;

    cout << "\nDisplaying Information." << endl;
    cout<<"Name: "<<s.name<<endl;
    cout<<"Roll no: "<<s.rollno<<endl;
    cout<<"Age: "<<s.age<<endl;
    cout<<"Marks: "<<s.marks<<endl;


    return 0;
}