// Input elements of array from user
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

    // Display array
    cout << "Array:\t";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
