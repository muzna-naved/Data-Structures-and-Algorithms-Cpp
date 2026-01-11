// Display

#include <iostream>
using namespace std;

int main() {
    int LA[] = {1, 3, 5, 7, 8};
    int i, n = 5;
    cout << "The original array elements are:\n";
    for (i = 0; i < n; i++) {
        cout << "LA[" << i << "]=" << LA[i] << endl;
    }
    return 0;
}
