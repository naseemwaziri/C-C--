#include <iostream>
using namespace std;

void add(int a, int b){
    cout<<"Sum is: "<< a + b;
}
void add(int a, int b, int c){
    cout<<"Sum is: "<< a + b + c;
}
void add(int a, int b, int c, int d){
    cout<<"Sum is: "<< a + b + c + d;
}
int main(){
    int a, b, c, d;
    cout<<"Enter 1st number: ";
    cin>>a;
    cout<<"Enter 2nd number: ";
    cin>>b;
    cout<<"Enter 3rd number: ";
    cin>>c;
    cout<<"Enter 4th number: ";
    cin>>d;

    add(a, b) ;
    cout<<endl;
    add(a, b, c) ;
    cout<<endl;
    add(a, b, c, d) ;
    cout<<endl;
}
