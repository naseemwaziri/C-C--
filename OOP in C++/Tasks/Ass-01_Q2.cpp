#include <iostream>
using namespace std;
long factorialByValue(int n) {
    if (n < 0) {
        return 0; 
    }

    long factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}
void factorialByReference(int n, long &result) {
    if (n < 0) {
        result = 0;
        return;
    }

    result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
}

int main() {
    int choice, num;
     long result;

    cout << "Factorial Calculator Menu:" <<endl;
    cout << "1. Calculate factorial of number by using pass-by-value." <<endl;
    cout << "2. Calculate factorial of number by using pass-by-reference." <<endl;
    cout << "Enter 1 for pass by value"<<endl;
    cout<< "Enter 2 for pass by refrence: "<<endl;
    cin >> choice;

    if (choice == 1 || choice == 2) {
        cout << "Enter an integer: ";
        cin >> num;

        if (choice == 1) {
            result = factorialByValue(num);
        } else {
            factorialByReference(num, result);
        }

        cout << "Factorial of " << num << " is " << result << endl;
    } else {
        cout << "Invalid choice. Please enter 1 or 2." <<endl;
    }

    return 0;
}