#include <iostream>
using namespace std;

const int N = 10 + 1;
int a[N][N];

int main () {
    int n, r;
    cout << "Please input the size of the matrix: " << endl;
    cin >> n;
    cout << "Please input the matrix row by row: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    cout << "Please choose the direction of spiral (1 - Clockwise, 2 - Anticlockwise): " << endl;
    cin >> r;
    cout << "The " << (r == 1 ? "clockwise" : "anticlockwise") << " spiral form of the matrix is: " << endl;
    if (r == 1) {
        int lb = 1, rb = n;
        while (lb < rb) {
            for (int col = lb; col <= rb; col++) {
                cout << a[lb][col] << " ";
            } // a[lb][lb...rb]
            for (int row = lb + 1; row <= rb; row++) {
                cout << a[row][rb] << " ";
            } // a[lb+1...rb][rb]
            for (int col = rb - 1; col >= lb; col--) {
                cout << a[rb][col] << " ";
            } // a[rb][rb-1...lb]
            for (int row = rb - 1; row > lb; row--) {
                cout << a[row][lb] << " ";
            } // a[rb-1...lb+1][lb], nothing if rb-lb=1
            lb++, rb--;
        }
        if (lb == rb) { // odd
            cout << a[lb][lb];
        }
    } else {
        int lb = 1, rb = n;
        while (lb < rb) {
            for (int row = lb; row <= rb; row++) {
                cout << a[row][lb] << " ";
            }
            for (int col = lb + 1; col <= rb; col++) {
                cout << a[rb][col] << " ";
            }
            for (int row = rb - 1; row >= lb; row--) {
                cout << a[row][rb] << " ";
            }
            for (int col = rb - 1; col > lb; col--) {
                cout << a[lb][col] << " ";
            }
            lb++, rb--;
        }
        if (lb == rb) {
            cout << a[lb][lb];
        }
    }
    cout << endl;
    return 0;
}