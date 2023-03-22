#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int a, b, c;
    cout << "Enter the value of A, B and C:\n";
    cin >> a >> b >> c;

    int _max = max(a, max(b, c));
    int _min = min(a, min(b, c));
    int _mid = a + b + c - _max - _min;

    if (_min <= 0 || _max >= (_mid + _min)) {
        cout << "Impossible\n";
    } else if (_max == _mid && _mid == _min) {
        cout << "Equilateral\n";
    } else if (_max == _mid || _mid == _min) {
        cout << "Isosceles\n";
    } else {
        cout << "Scalene\n";
    }

    return 0;
}