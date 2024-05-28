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

    int position;
    cout << "Enter position of element to delete: ";
    cin >> position;

    for (i = position - 1; i < size - 1; i++)
        arr[i] = arr[i + 1];
        

    size--;

    cout << "Array after deletion: " << endl;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
