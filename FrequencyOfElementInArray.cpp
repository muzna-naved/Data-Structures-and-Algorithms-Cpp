// frequency of each unique element in the array
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

    int visited[size] = {0};
    for (int i = 0; i < size; i++)
    {
        if (visited[i] == 1)
        {
            continue;
        }
        int count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                visited[j] = 1;
            }
        }
        cout << "Element: " << arr[i] << " Frequency: " << count << endl;
    }
    return 0;
}