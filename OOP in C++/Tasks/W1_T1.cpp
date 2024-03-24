#include <iostream>
using namespace std;

int main() {
    int size;
    // Get the size of the array from user.
 cout << "Enter the size of the array: ";
 cin >> size;
    // Check if the size is non-negative.
    if (size <= 0) {
     cout << "Array size should be a positive integer." << endl;
        return 1;
    }
    // Create an array of user's size.
    int arr[size]; 

    // Initialize the array elements from user.
 cout << "Enter " << size << " integer values:" << endl;
    for (int i = 0; i < size; i++) {
     cin >> arr[i];
    }
    // Print the array
 cout << "The array you entered is: ";
    for (int i = 0; i < size; i++) {
     cout << arr[i] << " ";
    }
 cout << endl;

    return 0;
}