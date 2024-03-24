// Define a C++ structure for a rectangle, containing the following members: width and height.
// Write a function that takes a rectangle structure and returns its area.

#include <iostream>
#include <string>
using namespace std;

struct Rectangle
{
    double width;
    double height;
};

double calculate_Area(Rectangle rect){
    return rect.width * rect.height;
}

int main(){
    Rectangle rect;
    cout<<"Enter Width Value: ";
    cin>>rect.width;
    cout<<"Enter Height Value: ";
    cin>>rect.height;
    double area = calculate_Area(rect);
    cout<<"Area of Rectangle is: "<< area << endl;

    return 0;
}