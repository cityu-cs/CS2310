#include <iostream>
using namespace std;

int hlen;

int getValue(int num) {
    // get the last ceil[len(num) / 2] digits
    int len = 0;
    int tmp = num;
    while (tmp) {
        len++;
        tmp /= 10;
    }
    tmp = 1;
    len = (len + 1) / 2;
    hlen = len;
    while (len--) {
        tmp *= 10;
    }
    return num % tmp;
}

int main() {
    cout << "Enter the number: ";
    int num;
    cin >> num;
    int ans = getValue(num);
    cout << "The value of last " << hlen << (hlen == 1 ? " digit" : " digits") << " of " << num << " is: " << ans << endl;
    return 0;
}