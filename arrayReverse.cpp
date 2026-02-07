// Display the array elements in reverse order.
#include <iostream>
using namespace std;

int main()
{
    int size;

    // Input size of array from user
    cout << "Enter size of array: ";
    cin >> size;

    int arr[size];

    // User input
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }

    // reversed array
    cout << "Array elements in reverse order: ";
    for (int i = size - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
}