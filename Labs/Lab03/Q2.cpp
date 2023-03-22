#include <iostream>
using namespace std;

int main () {
    int a, b, c, d;
    cout << "Enter 4 integer values:\n";
    cin >> a >> b >> c >> d;

    int _max = a;
    if (b > _max) _max = b;
    if (c > _max) _max = c;
    if (d > _max) _max = d;

    int _min = a;
    if (b < _min) _min = b;
    if (c < _min) _min = c;
    if (d < _min) _min = d;

    cout << "The median of 4 values is: " << static_cast<double>(a + b + c + d - _max - _min) / 2 << endl;
    return 0;
}