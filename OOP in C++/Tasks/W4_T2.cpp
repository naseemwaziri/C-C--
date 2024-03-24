#include <iostream>
#include <string>
using namespace std;

class Student
{
    private:
    int admno;
    string sname;
    float eng, math, science;
    float total;

    float ctotal();

    public:
    void takeData();
    void showData();
};
float Student :: ctotal(){
    return math + eng + science;
}
void Student :: takeData(){
    cout<<"Enter Admission no: ";
    cin>>admno;
    cout<<"Enter Name: ";
    cin>>sname;
    cout<<"Enter English Marks:";
    cin>>eng;
    cout<<"Enter Math Marks:";
    cin>>math;
    cout<<"Enter Science Marks:";
    cin>>science;
}
void Student :: showData(){
    cout<<"Admission no is: "<< admno <<endl;
    cout<<"Student Name: "<< sname <<endl;
    cout<<"English's Marks: "<< eng << endl;
    cout<<"Math's Marks: "<< math << endl;
    cout<<"Science's Marks: "<< science << endl;
    
}
