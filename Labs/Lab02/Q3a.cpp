#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double celsius;
    cout << "Enter temperature in Centigrade: " << endl;
    cin >> celsius;
    cout << setprecision(2) << fixed;
    cout << "Temperature in Fahrenheit is: " << celsius * 9 / 5 + 32 << endl;
    return 0;
}