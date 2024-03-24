#include <iostream>

bool isPrime(int number) {
    if (number <= 1) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

int main() {
    const int size = 100;
    int arr[size];

    // Filling the array with numbers 1 to 100
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }

    std::cout << "Prime numbers in the array are: ";
    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i])) {
            std::cout << arr[i] << " ";
        }
    }

    return 0;
}