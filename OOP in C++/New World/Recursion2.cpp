#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "The Fibonacci of " << n << " is: " << fibonacci(n) << endl;
    return 0;
}
// Output:
// Enter the number: 10
// The Fibonacci of 10 is: 55