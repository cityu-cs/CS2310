#include <iostream>
using namespace std;

int main() {
    int a[13][2] = {0};
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            a[i + j][0]++;
        }
    }
    for (int i = 2; i <= 12; i++) {
        a[i][1] = i;
        cout << a[i][0] << " occurence(s) of " << a[i][1] << endl;
    }
    cout << endl;
    for (int j = 2; j < 11; j++) {
        for (int k = 11; k > j; k--) {
            if (a[k][0] > a[k - 1][0]) {
                int temp = a[k][0];
                a[k][0] = a[k - 1][0];
                a[k - 1][0] = temp;
                temp = a[k][1];
                a[k][1] = a[k - 1][1];
                a[k - 1][1] = temp;
            }
        }
    }
    for (int i = 2; i <= 12; i++) {
        cout << a[i][0] << " occurence(s) of " << a[i][1] << endl;
    }
}