#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Please input a non-negative integer: ";
    cin >> n;
    int sum = 0, temp = n;
    while (temp) {
        sum += temp % 10;
        temp /= 10;
    }
    cout << "The sum of the digits is: " << sum << endl;

    if (sum % 2 == 0) {
        if (sum == 2) {
            cout << "Output: The result is: Yes" << endl;
            return 0;
        }
        cout << "Output: The result is: No" << endl;
    } else {
        bool flag = true;
        for (int fac = 3; fac * fac <= sum; fac += 2) {
            if (n % fac == 0) {
                flag = false;
                break;
            }
        }
        if (flag && sum != 1) {
            cout << "Output: The result is: Yes" << endl;
            return 0;
        } else {
            cout << "Output: The result is: No" << endl;
        }
    }

    for (int num = (n / 2) * 2 - 1; num > 2; num -= 2) {
        bool flag = true;
        for (int fac = 3; fac * fac <= num; fac += 2) {
            if (num % fac == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "The largest prime number less than the input number is: " << num << endl;
            return 0;
        }
    }
    // cout << "The largest prime number less than the input number is: 2" << endl;
    // this case does not exist because the non-prime number must >= 4
    // and the largest prime number less than 4 is 3
    return 0;
}