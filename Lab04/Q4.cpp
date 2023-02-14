#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    cout << "Enter the diagonal length:" << endl;
    int n;
    while ((cin >> n) && (n <= 0 || n % 2 == 0)) {
        cout << "Please enter an odd positive number!" << endl;
    }
    for (int i = 1; i <= n; i++) {
        int mid = min(i, n - i + 1) * 2 - 1;
        int l = (n - mid) / 2;
        for (int j = 1; j <= l; j++) {
            cout << " ";
        }
        for (int j = 1; j <= mid; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}