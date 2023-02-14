#include <iostream>
#include <string>
#include <cctype>
using namespace std;
const string names[] = {
    "uppercase letters",
    "lowercase letters",
    "+",
    "-",
    "*",
    "/"
};
int cnt[6];
int main() {
    cout << "Enter the input chars: ";
    char c;
    while ((cin >> c) && (c != '0')) {
        if (isalpha(c)) {
            if (isupper(c)) {
                cnt[0]++;
            } else {
                cnt[1]++;
            }
        } else if (c == '+') {
            cnt[2]++;
        } else if (c == '-') {
            cnt[3]++;
        } else if (c == '*') {
            cnt[4]++;
        } else if (c == '/') {
            cnt[5]++;
        }
    }
    for (int i = 0; i < 6; i++) {
        if (!cnt[i]) {
            continue;
        }
        cout << "The number of " << names[i] << " is: " << cnt[i] << endl;
    }
    if (cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] == 0) {
        cout << "Cannot find any chars" << endl;
    }
}