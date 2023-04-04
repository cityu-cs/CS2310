#include <iostream>
using namespace std;
int n, *a, *b, _max = 0;
int main() {
    cout << "Enter the size of the array: ";
    cin >> n;
    a = new int[n];
    cout << "Enter the content of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > _max) {
            _max = a[i];
        }
    }
    // how do you calculate the mode?
    b = new int[_max + 1];
    for (int i = 0; i < _max + 1; i++) {
        b[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        b[a[i]]++;
    }
    int mode = 0;
    bool repeat = false;
    for (int i = 0; i < _max + 1; i++) {
        if (b[i] > b[mode]) {
            mode = i;
            repeat = false;
        } else if (b[i] == b[mode]) {
            repeat = true;
            // cerr << "repeat detected at i=" << i << endl;
        }
    }
    if (b[mode] == 1) {
        cout << "The array does not have a mode." << endl;
    } else if (repeat) {
        cout << "The modes of the array are:" << endl;
        for (int i = 0; i < _max + 1; i++) {
            if (b[i] == b[mode]) {
                cout << i << endl;
            }
        }
    } else {
        cout << "The mode of the array is " << mode << endl;
    }
}