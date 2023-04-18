#include <iostream>
#include <cstring>
using namespace std;

void Merge(int*, int, int, int);
void Sort(int*, int, int);

int main() {
    int *a = NULL;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    a = new int[n];
    cout << "Enter the content of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Sort(a, 0, n - 1);
    cout << "The sorted array is:" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    } 
    cout << endl;
}

void Sort(int* a, int l, int r) {
    if (l < r) { // one number is sorted
        // cerr << "l = " << l << ", r = " << r << endl;
        int m = (l + r) / 2;
        Sort(a, l, m); // [l...m]
        Sort(a, m + 1, r); // [m+1...r]
        Merge(a, l, m, r);
    }
}

void Merge(int* a, int l, int m, int r) {
    int lidx = l, ridx = m + 1, idx = 0;
    int* tmp = new int[r - l + 1];
    while (lidx <= m && ridx <= r) {
        if (a[lidx] < a[ridx]) {
            tmp[idx++] = a[lidx++];
        } else {
            tmp[idx++] = a[ridx++];
        }
    }
    while (lidx <= m) {
        tmp[idx++] = a[lidx++];
    }
    while (ridx <= r) {
        tmp[idx++] = a[ridx++];
    }
    memcpy(a + l, tmp, sizeof(int) * (r - l + 1));
    // lidx = l;
    // while (lidx <= r) {
    //     a[lidx] = tmp[lidx - l];
    //     lidx++;
    // }
    // for (int i = 0; i < r - l + 1; i++) {
    //     cout << tmp[i] << " ";
    // }
    // cout << endl;
    delete [] tmp;
    tmp = NULL;
}