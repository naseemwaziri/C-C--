#include <iostream>
using namespace std;

struct Student{
    string name;
    int rollno;
    int age;
};
Student getdata(Student s){
    cout<<"Enter name: ";
    getline(cin, s.name);
    cout<<"Enter roll no: ";
    cin>>s.rollno;
    cout<<"Enter age";
    cin>>s.age;

    return s;
}
void displaydata(Student s){
    cout<<"\nDisplay Information"<<endl;
    cout<<"Name: "<<s.name<<endl;
    cout<<"Roll no: "<<s.rollno<<endl;
    cout<<"age: "<<s.age<<endl;

}

int main(){
    Student s, temp;
    temp = getdata(s);
    s = temp;
    displaydata(s);

    return 0;
}