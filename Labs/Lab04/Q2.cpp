#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the input positive number: ";
    cin >> n;
    cout << "The prime factorization of " << n << " is: " << endl;
    if (n == 1) {
        cout << "1" << endl;
        return 0;
    }
    int k = 2;
    while (n > 1) {
        if (n % k == 0) {
            cout << k << " ";
            n /= k;
        } else {
            k++;
        }
    }
    cout << endl;
    return 0;
}