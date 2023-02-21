#include <iostream>
using namespace std;

const int N = 6;
int a[N];

int main() {
    cout << "Enter the element in the array: " << endl;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int temp;
    for (int i = 1; i < N; i++) {
        // insert a[i] to a[0..i-1]
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) {
                temp = a[i];
                for (int k = i; k > j; k--) {
                    a[k] = a[k - 1];
                }
                a[j] = temp;
                break;
            }
        }
    }
    cout << "The sorted array is: " << endl;
    for (int i = 0; i < N - 1; i++) {
        cout << a[i] << ", ";
    }
    cout << a[N - 1] << endl;
    return 0;
}