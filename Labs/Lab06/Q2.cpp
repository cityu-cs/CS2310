#include <iostream>
using namespace std;

int gcd(int, int);

int lcm(int, int);

int main() {
    int a, b;
    cout << "Enter the two integers: ";
    cin >> a >> b;
    cout << "The GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
    cout << "The LCM of " << a << " and " << b << " is: " << lcm(a, b) << endl;

}

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int lcm(int x, int y) {
    return x * y / gcd(x, y);
}