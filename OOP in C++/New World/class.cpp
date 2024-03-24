#include <iostream>
#include <string>
using namespace std;

class Student{
public:
    string name;
    int rollno;
    double age;
    double marks;

    void inputdata(){
        cout<<"Enter Name: ";
        getline(cin, name);
        cout<<"Enter Roll no: ";
        cin>>rollno;
        cout<<"Enter age: ";
        cin>>age;
        cout<<"Enter Marks: ";
        cin>>marks;
    }
    void displaydata(){
        cout<<"\nDisplay Student's Information"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Roll no: "<<rollno<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Marks: "<<marks<<endl; 
    }
};

int main(){
    Student student;

    student.inputdata();
    student.displaydata();

    return 0;
}