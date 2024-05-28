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

    int element;
    cout << "Enter element to insert: ";
    cin >> element;
    int position;
    cout << "Enter position: ";
    cin >> position;
    for (i = size; i >= position; i--)
        arr[i] = arr[i - 1];
    arr[position - 1] = element;
    size++;
    cout << "New arry is: " << endl;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}