#include <iostream>
using namespace std;

int main() {
    int arr[100];

    for(int i = 0; i < 100; i++) {
        arr[i] = i + 1;
    }

    cout << "Odd numbers:" << endl;
    for(int i = 0; i < 100; i++) {
        if(arr[i] % 2 != 0) { 
            cout << arr[i] << " ";
        }
    }

    return 0;
}