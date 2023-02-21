#include <iostream>
using namespace std;

const int N = 20 + 1;

int a[N];

int main() {
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    cout << "Enter the elements of the array: " << endl;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << "The output is: " << endl;
    for (int i = 1; i < n; i++) {
        int maxn = -1;
        for (int j = i + 1; j <= n; j++) {
            if (a[j] < a[i] && a[j] > maxn) {
                maxn = a[j];
            }
        }
        cout << maxn << ", ";
    }
    cout << -1 << endl;
    return 0;
}