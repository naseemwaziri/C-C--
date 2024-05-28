#include <iostream>
using namespace std;

int main()
{
    int arr[10], size, i;
    cout << "Enter size of array: ";
    cin >> size;
    cout << "Enter " << size << " array elements: ";
    for (i = 0; i < size; i++)
        cin >> arr[i];

    int index, newVal;
    cout << "Enter the index to update: ";
    cin >> index;
    cout << "Enter the new value: ";
    cin >> newVal;

    arr[index] = newVal;

    cout << "Updated array:\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}