#include <iostream>
using namespace std;

void printNum(int n1, float n2){
    
    cout<<"The int number is: "<<n1<<endl;
    cout<<"The float number is: "<<n2<<endl;
}
int main(){
    int num1 = 34;
    float num2 = 54.6;
    printNum(num1, num2);

    return 0;
}
