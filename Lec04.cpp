#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter the diagonal length:\n";
    cin >> n;
    while (n <= 0 || n % 2 == 0) {
        cout << "Please enter an odd positive number!\n";
        cin >> n;
    }
    for (int i = 1; i <= n; i++) {
        int k = min(i, n - i + 1) * 2 - 1; // number of stars
        int l = (n - k) / 2; // number of spaces
        for (int j = 1; j <= l; j++) {
            cout << " ";
        }
        for (int j = 1; j <= k; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}