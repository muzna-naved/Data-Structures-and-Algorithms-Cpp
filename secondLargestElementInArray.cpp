// second largest element in the array.
#include <iostream>
using namespace std;

void secondLargestElement(int arr[], int size)
{
    if (size < 2)
    {
        cout << "Second largest element does not exist";
        return;
    }

    int largest, secondLargest;
    int index1, index2;

    // Initialize using first two elements
    if (arr[0] > arr[1])
    {
        largest = arr[0];
        index1 = 0;
        secondLargest = arr[1];
        index2 = 1;
    }
    else
    {
        largest = arr[1];
        index1 = 1;
        secondLargest = arr[0];
        index2 = 0;
    }

    // second largest
    for (int i = 2; i < size; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            index2 = index1;

            largest = arr[i];
            index1 = i;
        }
        else if (arr[i] < largest && arr[i] > secondLargest)
        {
            secondLargest = arr[i];
            index2 = i;
        }
    }

    cout << "The second largest element is: "
         << secondLargest << " at index: " << index2 << endl;
}

int main()
{
    int size;
    // inout size of array
    cout << "Enter size of array: ";
    cin >> size;

    int arr[size];

    // user inout of array elements
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }

    secondLargestElement(arr, size);
    return 0;
}
