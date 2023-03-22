#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    if (n <= 0) {
        cout << "Please enter positive integer." << endl;
        return 0;
    }
    for (int col = 0; col < n; col++) {
        for (int row = 0; row < n; row++) {
            cout << abs(row - col) << " ";
        }
        cout << endl;
    }
    return 0;
}