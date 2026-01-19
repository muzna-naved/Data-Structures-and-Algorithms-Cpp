// Insertion Opeartion

#include <iostream>
using namespace std;

int main()
{
    int LA[3] = {}, i;

    cout << "Array before insertion:" << endl;
    for (i = 0; i < 3; i++)
    {
        cout << "LA[" << i << "]=" << LA[i] << endl;
    }

    cout << "Inserting elements.." << endl;
    cout << "Array after insertion:" << endl;

    for (i = 0; i < 3; i++)
    {
        LA[i] = i + 2;
        cout << "LA[" << i << "]=" << LA[i] << endl;
    }
    return 0;
}
