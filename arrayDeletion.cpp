// Deletion Operation

#include <iostream>
using namespace std;

int main()
{
    int LA[] = {1, 3, 5};
    int i, n = 3;
    cout << "The original array elements are:" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "LA[" << i << "]:" << LA[i] << endl;
    }

    for (i = 1; i < n; i++)
    {
        LA[i] = LA[i + 1];
    }
    n = n - 1;

    cout << "The array elements after deletion:" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "LA[" << i << "]:" << LA[i] << endl;
    }
}

