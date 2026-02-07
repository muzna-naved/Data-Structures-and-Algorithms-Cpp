// calculate the sum and average of all array elements.
#include <iostream>
using namespace std;

// Function for sum of array elements
int sumOfArray(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

// Function for average of array elements
int avgOfArray(int arr[], int size)
{
    float avg = 0;
    int sum = sumOfArray(arr, size);
    return (float)sum / size;
}

// Main
int main()
{
    int size;

    // Input size of array from user
    cout << "Enter size of array: ";
    cin >> size;

    int arr[size];

    // User input for array elements
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }

    cout << "Sum of array: " << sumOfArray(arr, size) << endl;
    cout << "Average of array: " << avgOfArray(arr, size) << endl;
}