#include <iostream>
#include <string>
using namespace std;

class REPORT 
{
private:
    int adno;
    string name;
    float marks[5];
    float average;

    void GETAVG();

public:
    void READINFO();
    void DISPLAYINFO();   
};
    void REPORT :: GETAVG()
    {
        float sum = 0;
        for(int i = 0; i < 5; i++)
        {
            sum = sum + marks[i];
        }
        average = sum / 5.0;
    }
    void REPORT :: READINFO()
    {
        cout<<"Enter admission number: ";
        cin>>adno;
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter marks for 5 subjects: ";
        for(int i = 0; i < 5; i++)
        {
            cin>>marks[i];
        }
        GETAVG();
    }

    void REPORT :: DISPLAYINFO()
    {
        cout<<"Admission Number: "<<adno<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Marks in 5 subjects: ";
        for (int i = 0; i < 5; i++)
        {
            cout<<marks[i] <<" ";
        }
        cout<<endl;
        cout<<"Average Marks: "<<average<<endl;
    }

int main()
{
    REPORT student;
    student.READINFO();
    cout<<"Student Report Information:\n";
    student.DISPLAYINFO();
    return 0;
}
