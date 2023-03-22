#include <iostream>
using namespace std;

int main() {
    int a[3][4];

    cout << sizeof(a) << endl;

    cout << sizeof(a[0][0]) << endl;

    // number of rows
    cout << sizeof(a) / sizeof(a[0]) << endl;

    // number of columns
    cout << sizeof(a[0]) / sizeof(a[0][0]) << endl;

    return 0;
}