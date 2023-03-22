#include <iostream>
#include <cstring>
using namespace std;
const int N = 20 + 1;
char a[2 * N], b[2 * N];
char rev[N], opt[N];

void Swap(char& lhs, char& rhs) {
    char tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

int main() {
    cout << "Please input a string: ";
    cin.getline(a, N);
    cout << "The shortest palindrome is: ";
    int len = strlen(a);
    if (!len) {
        cout << endl;
        cout << "Please input the sorting order (ASC/DESC): ";
        cin >> opt;
        cout << "The sorted result: " << endl;
        return 0;
    }
    for (int i = 0; i < len; i++) {
        rev[i] = a[len - i - 1];
    }

    // find the longest palindrome in rev that must be prefix of rev
    int ans = 0;
    for (int j = len - 1; j > 0; j--) { // test rev[0...j]
        bool flag = true;
        for (int k = j / 2; k >= 0; k--) {
            // cerr << "rev[" << k << "] = " << rev[k] << ", rev[" << j - k << "] = " << rev[j - k] << endl;
            if (rev[k] != rev[j - k]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans = j;
            // cerr << "ans = " << ans << endl;
            break;
        }
    }
    // append rev[ans+1...len-1] to a
    strncpy(a + len, rev + ans + 1, len - ans - 1);
    cout << a << endl;

    // dedup and sort
    cout << "Please input the sorting order (ASC/DESC): ";
    cin >> opt;
    cout << "The sorted result: ";
    len = strlen(a);
    int blen = 0;
    for (int i = 0; i < len; i++) {
        bool flag = true;
        for (int j = 0; j < blen; j++) {
            if (a[i] == b[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            b[blen++] = a[i];
        }
    }
    if (opt[0] == 'A') {
        for (int i = 0; i < blen - 1; i++) {
            for (int j = blen - 1; j > i; j--) {
                if (b[j] < b[j - 1]) {
                    Swap(b[j], b[j - 1]);
                }
            }
        }
    } else {
        for (int i = 0; i < blen - 1; i++) {
            for (int j = blen - 1; j > 0; j--) {
                if (b[j] > b[j - 1]) {
                    Swap(b[j], b[j - 1]);
                }
            }
        }
    }
    cout << b << endl;
}