// maximum and minimum value in the array.
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

    int max = arr[0];
    int min = arr[0];
    int maxIndex = 0;
    int minIndex = 0;

    // Maximum and minimum
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxIndex = i;
        }

        if (arr[i] < min)
        {
            min = arr[i];
            minIndex = i;
        }
    }

    cout << "Maximum element of array is: " << max << " at index " << maxIndex << endl;
    cout << "Minimum element of array is: " << min << " at index " << minIndex << endl;

    return 0;
}
