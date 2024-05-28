#include <iostream>
using namespace std;

void printReversed(int arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[10];
    cout << "Enter 10 elements: ";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    cout << "Reversed array is: ";
    printReversed(arr, 10);

    return 0;
}  