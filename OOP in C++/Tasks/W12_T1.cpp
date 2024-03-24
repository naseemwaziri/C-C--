#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double getArea() const override
    {
        return 3.14 * radius * radius;
    }
    double getPerimeter() const override
    {
        return 2 * 3.14 * radius;
    }
};

class Rectangle : public Shape
{
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double getArea() const override
    {
        return length * width;
    }
    double getPerimeter() const override
    {
        return 2 * (length + width);
    }
};

int main()
{
    Shape *shape = 0;
    int choice;
    double radius, length, width;
    while (true)
    {
        cout << "Choose an option: " << endl;
        cout << "1. Circle" << endl;
        cout << "2. Rectangle" << endl;
        cout << "-1. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter radius: ";
            cin >> radius;
            shape = new Circle(radius);
            cout << "Area: " << shape->getArea() << endl;
            cout << "Perimeter: " << shape->getPerimeter() << endl;
            break;
        case 2:
            cout << "Enter length and width: ";
            cin >> length >> width;
            shape = new Rectangle(length, width);
            cout << "Area: " << shape->getArea() << endl;
            cout << "Perimeter: " << shape->getPerimeter() << endl;
            break;
        case -1:
            delete shape;
            return 0;
        default:
            cout << "Invalid choice." << endl;
        }
    }
    return 0;
}