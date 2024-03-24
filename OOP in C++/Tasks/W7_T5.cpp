#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double getArea() = 0;
    virtual void display() = 0; 
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double getArea()
    {
        return length * width;
    }
    void display()
    {
        cout << "This is a rectangle." << endl;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double getArea()
    {
        return 3.14 * radius * radius;
    }
    void display()
    {
        cout << "This is a circle." << endl;
    }
};

int main()
{
    Rectangle rect(5.0, 4.0);
    Circle circ(3.0);

    rect.display();
    cout << "Area: " << rect.getArea() << endl;

    circ.display();
    cout << "Area: " << circ.getArea() << endl;

    return 0;
}