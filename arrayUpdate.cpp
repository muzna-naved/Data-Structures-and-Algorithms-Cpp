#include <iostream>
using namespace std;

int main()
{
    int LA[] = {1, 3, 5, 7, 8};
    int item = 10, k = 3, n = 5;
    int i;

    cout << "The original array elements are:\n";
    for (i = 0; i < n; i++)
    {
        cout << "LA[" << i << "] = " << LA[i] << endl;
    }

    if (k >= 0 && k < n)
    {
        LA[k] = item;
    }

    cout << "The array elements after updation are:\n";
    for (i = 0; i < n; i++)
    {
        cout << "LA[" << i << "] = " << LA[i] << endl;
    }

    cin.get();  
    return 0;
}
